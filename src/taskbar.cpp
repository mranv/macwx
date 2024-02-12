#include "taskbar.h"
#include "frame.h"
#include "resource_provider.h" // Include the generated header

BEGIN_EVENT_TABLE(TaskBarIcon, wxTaskBarIcon)
                EVT_TASKBAR_LEFT_UP(TaskBarIcon::OnButtonClick)
                EVT_TASKBAR_RIGHT_UP(TaskBarIcon::OnButtonClick)
END_EVENT_TABLE()

TaskBarIcon::TaskBarIcon(MainFrame* mainFrame)
{
    frame = mainFrame;
    SetIcon(ResourceProvider::GetInstance().GetHealthyIcon(), wxT("Single Tray"));
}

/// <summary>
/// Handles the taskbar icon click event
/// </summary>
/// <param name="event">The taskbar icon event</param>
void TaskBarIcon::OnButtonClick(wxTaskBarIconEvent& event)
{
    // Add debug output to check if the function is being called
    wxLogDebug(wxT("Taskbar icon clicked"));

    if (frame) {
        bool isVisible = frame->IsShown();

        // Add debug output to check the frame visibility status
        wxLogDebug(wxT("Frame visibility: %s"), isVisible ? wxT("Visible") : wxT("Hidden"));

        frame->Show(!isVisible);

        // Add debug output to check if the frame is being shown after toggling
        wxLogDebug(wxT("Frame visibility after toggling: %s"), frame->IsShown() ? wxT("Visible") : wxT("Hidden"));

        if (!isVisible) {
            frame->Raise(); // Bring the frame to the foreground
        }
    }
}
