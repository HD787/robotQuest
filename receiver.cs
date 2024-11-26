using System;
using System.Collections.Generic;
using System.IO;
using System.Net;
using System.Net.Sockets;
using System.Text;
using UnityEngine

public class ImageReceiver
{
    private readonly UdpClient udpClient;
    private const int BufferSize = 65535; // Max UDP packet size
    private const int HeaderSize = 8;     // Size of the packet header (two uint32_t)
    private readonly string outputDir = "data/received_images";

    private Dictionary<int, Dictionary<int, byte[]>> chunks = new Dictionary<int, Dictionary<int, byte[]>>();
    private int? currentImageChunks = null;
    private HashSet<int> expectedChunks = null;

    public ImageReceiver(string host = "127.0.0.1", int port = 8081)
    {
        udpClient = new UdpClient(port);
        Console.WriteLine($"Listening on {host}:{port}...");

        // Ensure output directory exists
        if (!Directory.Exists(outputDir))
        {
            Directory.CreateDirectory(outputDir);
        }
    }

    public void Run()
    {
        try
        {
            Console.WriteLine("Starting image receiver...");
            ReceiveImage();
        }
        catch (Exception ex)
        {
            Console.WriteLine($"Receiver error: {ex.Message}");
        }
        finally
        {
            udpClient.Close();
            Console.WriteLine("Shutting down receiver...");
        }
    }

    private void ReceiveImage()
    {
        IPEndPoint remoteEndPoint = new IPEndPoint(IPAddress.Any, 0);

        while (true)
        {
            try
            {
                byte[] data = udpClient.Receive(ref remoteEndPoint);

                // Parse the header
                (int totalChunks, int chunkIndex) = ParseHeader(data);

                // Extract the chunk data
                byte[] chunkData = new byte[data.Length - HeaderSize];
                Array.Copy(data, HeaderSize, chunkData, 0, chunkData.Length);

                // If this is the first chunk of a new image
                if (chunkIndex == 0)
                {
                    currentImageChunks = totalChunks;
                    expectedChunks = new HashSet<int>();
                    for (int i = 0; i < totalChunks; i++)
                    {
                        expectedChunks.Add(i);
                    }
                }

                // Add the chunk to the appropriate collection
                if (!chunks.ContainsKey(totalChunks))
                {
                    chunks[totalChunks] = new Dictionary<int, byte[]>();
                }

                chunks[totalChunks][chunkIndex] = chunkData;

                // Check if all chunks are received
                if (currentImageChunks.HasValue &&
                    chunks[currentImageChunks.Value].Count == currentImageChunks.Value)
                {
                    SaveCompleteImage(chunks[currentImageChunks.Value]);
                    chunks.Remove(currentImageChunks.Value);
                    currentImageChunks = null;
                }
            }
            catch (Exception ex)
            {
                Console.WriteLine($"Error receiving data: {ex.Message}");
            }
        }
    }

    private (int, int) ParseHeader(byte[] data)
    {
        // Read two integers (uint32) from the beginning of the data
        int totalChunks = BitConverter.ToInt32(data, 0);
        int chunkIndex = BitConverter.ToInt32(data, 4);
        return (totalChunks, chunkIndex);
    }

    private void SaveCompleteImage(Dictionary<int, byte[]> imageChunks)
    {
        byte[] imageData = CombineChunks(imageChunks);

        // Create a unique filename based on the current timestamp
        string timestamp = DateTimeOffset.Now.ToUnixTimeMilliseconds().ToString();
        string filename = Path.Combine(outputDir, $"image_{timestamp}.jpg");

        // Save the image data to a file
        File.WriteAllBytes(filename, imageData);
        Console.WriteLine($"Saved complete image: {filename} ({imageData.Length} bytes)");
    }

    private byte[] CombineChunks(Dictionary<int, byte[]> imageChunks)
    {
        List<byte> combined = new List<byte>();

        for (int i = 0; i < imageChunks.Count; i++)
        {
            combined.AddRange(imageChunks[i]);
        }

        return combined.ToArray();
    }
}
