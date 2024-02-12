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
/// Brings the frame to the foreground if it was hidden
/// </summary>
/// <param name=""></param>
void TaskBarIcon::OnButtonClick(wxTaskBarIconEvent&)
{
    if (frame) {
        bool isVisible = frame->IsShown();
        frame->Show(!isVisible);
        if (!isVisible) {
            frame->Raise();
        }
    }
}