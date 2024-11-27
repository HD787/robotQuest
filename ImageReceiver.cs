//currenty the approach is to drop this in unity under a game object
//the next step is getting it to load in a vr rig object
using UnityEngine;
using System;
using System.Collections.Generic;
using System.Net;
using System.Net.Sockets;
using System.Threading;
using System.Threading.Tasks;

public class VRImageReceiver : MonoBehaviour
{
    [Header("Network Settings")]
    // [SerializeField] private string host = "127.0.0.1";
    [SerializeField] private string host = "0.0.0.0";
    [SerializeField] private int port = 8081;
    
    [Header("Display Settings")]
    [SerializeField] private MeshRenderer displayRenderer;
    [SerializeField] private float distance = 2f;
    [SerializeField] private float width = 16f;
    [SerializeField] private float height = 9f;
    [SerializeField] private bool curvedDisplay = true;
    [SerializeField] private float curveRadius = 2f;
    [SerializeField] private bool followHead = true;
    [SerializeField] private float followSpeed = 5f;

    [Header("Debug Settings")]
    [SerializeField] private bool enableDetailedLogging = false;
    [SerializeField] private float memoryLogInterval = 5f;
    
    private UdpClient udpClient;
    private const int BufferSize = 65535;
    private const int HeaderSize = 8;
    
    private Dictionary<int, Dictionary<int, byte[]>> chunks = new Dictionary<int, Dictionary<int, byte[]>>();
    private int? currentImageChunks = null;
    private HashSet<int> expectedChunks = null;
    private byte[] latestImageData = null;
    private bool hasNewImage = false;
    
    private CancellationTokenSource cancellationTokenSource;
    private bool isRunning = false;
    private Material displayMaterial;

    // FPV specific variables
    private Transform cameraTransform;
    private Vector3 targetPosition;
    private Quaternion targetRotation;

    // Debug tracking variables
    private int totalPacketsReceived = 0;
    private int successfulImageDisplays = 0;
    private int failedImageDisplays = 0;

    private void LogDebugMessage(string message)
    {
        if (!enableDetailedLogging) return;
        Debug.Log($"[VRImageReceiver] {DateTime.Now:HH:mm:ss.fff}: {message}");
    }

    private void Start()
    {
        LogDebugMessage("Starting VRImageReceiver...");
        cameraTransform = Camera.main.transform;
        SetupDisplay();
        StartReceiver();
    }

    private void SetupDisplay()
    {
        try 
        {
            if (displayRenderer == null)
            {
                LogDebugMessage("Creating FPV display...");
                GameObject display = new GameObject("FPVDisplay");
                display.transform.SetParent(transform, false);

                if (curvedDisplay)
                {
                    CreateCurvedDisplay(display);
                }
                else
                {
                    GameObject quad = GameObject.CreatePrimitive(PrimitiveType.Quad);
                    quad.transform.SetParent(display.transform, false);
                    displayRenderer = quad.GetComponent<MeshRenderer>();
                    quad.transform.localScale = new Vector3(width, height, 1);
                }

                // Position the display
                PositionDisplayInFrontOfCamera();
            }

            LogDebugMessage("Setting up display material...");
            displayMaterial = new Material(Shader.Find("Unlit/Texture"));
            displayMaterial.renderQueue = 3000; // Render on top
            displayRenderer.material = displayMaterial;
            LogDebugMessage("Display setup completed");
        }
        catch (Exception ex)
        {
            LogDebugMessage($"CRITICAL: Error in SetupDisplay: {ex}");
        }
    }

    private void CreateCurvedDisplay(GameObject parent)
    {
        int segments = 10;
        Mesh mesh = new Mesh();
        List<Vector3> vertices = new List<Vector3>();
        List<Vector2> uvs = new List<Vector2>();
        List<int> triangles = new List<int>();

        float segmentWidth = width / segments;
        float angleStep = (width / curveRadius) / segments;

        for (int i = 0; i <= segments; i++)
        {
            float angle = -width / (2 * curveRadius) + i * angleStep;
            float x = Mathf.Sin(angle) * curveRadius;
            float z = curveRadius * (1 - Mathf.Cos(angle));

            vertices.Add(new Vector3(x, -height/2, z));
            vertices.Add(new Vector3(x, height/2, z));
            uvs.Add(new Vector2((float)i / segments, 0));
            uvs.Add(new Vector2((float)i / segments, 1));

            if (i < segments)
            {
                int baseIndex = i * 2;
                triangles.Add(baseIndex);
                triangles.Add(baseIndex + 1);
                triangles.Add(baseIndex + 2);
                triangles.Add(baseIndex + 1);
                triangles.Add(baseIndex + 3);
                triangles.Add(baseIndex + 2);
            }
        }

        mesh.vertices = vertices.ToArray();
        mesh.uv = uvs.ToArray();
        mesh.triangles = triangles.ToArray();
        mesh.RecalculateNormals();

        GameObject curvedDisplay = new GameObject("CurvedDisplay");
        curvedDisplay.transform.SetParent(parent.transform, false);
        MeshFilter meshFilter = curvedDisplay.AddComponent<MeshFilter>();
        displayRenderer = curvedDisplay.AddComponent<MeshRenderer>();
        meshFilter.mesh = mesh;
    }

     private void PositionDisplayInFrontOfCamera()
    {
        if (cameraTransform != null)
        {
            transform.position = cameraTransform.position + cameraTransform.forward * distance;
            transform.rotation = cameraTransform.rotation;
            targetPosition = transform.position;
            targetRotation = transform.rotation;
        }
    }


    private void OnDisable()
    {
        LogDebugMessage("OnDisable called - stopping receiver...");
        StopReceiver();
    }

    private void Update()
    {
        // Debug logging
        if (enableDetailedLogging && Time.frameCount % 300 == 0)
        {
            LogDebugMessage($"Status - Packets: {totalPacketsReceived}, " +
                           $"Images Success/Fail: {successfulImageDisplays}/{failedImageDisplays}, " +
                           $"Memory: {GC.GetTotalMemory(false) / 1024 / 1024}MB");
        }

        // Update display position and rotation
        if (followHead && cameraTransform != null)
        {
            targetPosition = cameraTransform.position + cameraTransform.forward * distance;
            targetRotation = cameraTransform.rotation;

            transform.position = Vector3.Lerp(transform.position, targetPosition, Time.deltaTime * followSpeed);
            transform.rotation = Quaternion.Slerp(transform.rotation, targetRotation, Time.deltaTime * followSpeed);
        }

        // Process new images
        if (hasNewImage && latestImageData != null)
        {
            DisplayImage(latestImageData);
            hasNewImage = false;
        }
    }

    private void StartReceiver()
    {
        if (isRunning) return;

        try
        {
            udpClient = new UdpClient(port);
            cancellationTokenSource = new CancellationTokenSource();
            isRunning = true;

            Task.Run(() => ReceiveLoop(cancellationTokenSource.Token), cancellationTokenSource.Token);
            LogDebugMessage($"Started UDP receiver on {host}:{port}");
        }
        catch (Exception ex)
        {
            LogDebugMessage($"CRITICAL: Failed to start UDP receiver: {ex.Message}");
        }
    }

    private void StopReceiver()
    {
        if (!isRunning) return;

        try
        {
            cancellationTokenSource?.Cancel();
            udpClient?.Close();
            isRunning = false;
            LogDebugMessage("Stopped UDP receiver");
        }
        catch (Exception ex)
        {
            LogDebugMessage($"CRITICAL: Error stopping UDP receiver: {ex.Message}");
        }
    }

    private async Task ReceiveLoop(CancellationToken cancellationToken)
    {
        IPEndPoint remoteEndPoint = new IPEndPoint(IPAddress.Any, 0);
        LogDebugMessage("Starting receive loop");

        while (!cancellationToken.IsCancellationRequested)
        {
            try
            {
                UdpReceiveResult result = await udpClient.ReceiveAsync();
                totalPacketsReceived++;
                
                if (totalPacketsReceived % 100 == 0)
                {
                    LogDebugMessage($"Received {totalPacketsReceived} total packets. Current chunks: {chunks.Count}");
                }

                byte[] data = result.Buffer;
                (int totalChunks, int chunkIndex) = ParseHeader(data);
                
                LogDebugMessage($"Received chunk {chunkIndex + 1}/{totalChunks}");

                byte[] chunkData = new byte[data.Length - HeaderSize];
                Array.Copy(data, HeaderSize, chunkData, 0, chunkData.Length);

                if (chunkIndex == 0)
                {
                    currentImageChunks = totalChunks;
                    expectedChunks = new HashSet<int>();
                    for (int i = 0; i < totalChunks; i++)
                    {
                        expectedChunks.Add(i);
                    }
                }

                if (!chunks.ContainsKey(totalChunks))
                {
                    chunks[totalChunks] = new Dictionary<int, byte[]>();
                }
                chunks[totalChunks][chunkIndex] = chunkData;

                if (currentImageChunks.HasValue && 
                    chunks[currentImageChunks.Value].Count == currentImageChunks.Value)
                {
                    ProcessCompleteImage(chunks[currentImageChunks.Value]);
                    chunks.Remove(currentImageChunks.Value);
                    currentImageChunks = null;
                }
            }
            catch (Exception ex)
            {
                LogDebugMessage($"CRITICAL: Error in receive loop: {ex}");
                if (!cancellationToken.IsCancellationRequested)
                {
                    await Task.Delay(1000, cancellationToken);
                }
            }
        }
    }

    private (int, int) ParseHeader(byte[] data)
    {
        int totalChunks = BitConverter.ToInt32(data, 0);
        int chunkIndex = BitConverter.ToInt32(data, 4);
        return (totalChunks, chunkIndex);
    }

    private void ProcessCompleteImage(Dictionary<int, byte[]> imageChunks)
    {
        try
        {
            LogDebugMessage($"Processing complete image with {imageChunks.Count} chunks");
            List<byte> combined = new List<byte>();
            for (int i = 0; i < imageChunks.Count; i++)
            {
                combined.AddRange(imageChunks[i]);
            }
            
            latestImageData = combined.ToArray();
            hasNewImage = true;
            LogDebugMessage($"Image processed, size: {latestImageData.Length / 1024}KB");
        }
        catch (Exception ex)
        {
            LogDebugMessage($"CRITICAL: Error processing image: {ex}");
        }
    }

    private void DisplayImage(byte[] imageData)
    {
        if (displayRenderer == null || displayMaterial == null)
        {
            LogDebugMessage("CRITICAL: Display components not properly initialized!");
            return;
        }

        try
        {
            LogDebugMessage($"Creating new texture. Memory before: {GC.GetTotalMemory(false) / 1024 / 1024}MB");
            Texture2D texture = new Texture2D(2, 2);
            
            if (texture.LoadImage(imageData))
            {
                // Destroy old texture to prevent memory leaks
                if (displayMaterial.mainTexture != null)
                {
                    LogDebugMessage("Destroying old texture");
                    Destroy(displayMaterial.mainTexture);
                }
                
                displayMaterial.mainTexture = texture;
                successfulImageDisplays++;
                LogDebugMessage($"Image #{successfulImageDisplays} loaded. Size: {imageData.Length / 1024}KB");
            }
            else
            {
                failedImageDisplays++;
                LogDebugMessage($"Failed to load image #{failedImageDisplays}. Data size: {imageData.Length / 1024}KB");
            }
            
            LogDebugMessage($"Memory after: {GC.GetTotalMemory(false) / 1024 / 1024}MB");
        }
        catch (Exception ex)
        {
            failedImageDisplays++;
            LogDebugMessage($"CRITICAL: Error displaying image: {ex}");
        }
    }

    private void OnDestroy()
    {
        LogDebugMessage("OnDestroy called - cleaning up resources...");
        StopReceiver();
        
        if (displayMaterial.mainTexture != null)
        {
            Destroy(displayMaterial.mainTexture);
            LogDebugMessage("Destroyed main texture");
        }
        if (displayMaterial != null)
        {
            Destroy(displayMaterial);
            LogDebugMessage("Destroyed display material");
        }
    }
}