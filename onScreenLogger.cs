using UnityEngine;
using UnityEngine.UI;

public class OnScreenLogger : MonoBehaviour
{
    [SerializeField] private Text debugText; // Reference to a UI Text component
    [SerializeField] private int maxLines = 20; // Limit the number of lines displayed

    private string logContent = ""; // Stores log messages
    private int currentLines = 0;

    private void Start()
    {
        if (debugText != null)
        {
            debugText.text = "Log system initialized.";
        }
        else
        {
            Debug.LogError("DebugText reference is missing! Assign a UI Text component in the Inspector.");
        }
    }

    private void OnEnable()
    {
        Application.logMessageReceived += HandleLog;
    }

    private void OnDisable()
    {
        Application.logMessageReceived -= HandleLog;
    }

    private void HandleLog(string logString, string stackTrace, LogType type)
    {
        // Add new log message
        logContent += logString + "\n";
        currentLines++;

        // Trim the log if it exceeds max lines
        if (currentLines > maxLines)
        {
            int firstNewline = logContent.IndexOf('\n');
            logContent = logContent.Substring(firstNewline + 1);
            currentLines--;
        }

        // Update the UI Text
        if (debugText != null)
        {
            // debugText.text = logContent;
            debugText.text = "TESTING";
        }
    }
}
