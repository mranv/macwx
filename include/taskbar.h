#ifndef TASKBAR_H
#define TASKBAR_H


#include <wx/mstream.h> // For wxMemoryInputStream
#include <wx/icon.h>    // For wxIcon
#include <wx/bitmap.h> // For wxBitmap
#include <wx/image.h>  // For wxBITMAP_TYPE_ICO
#include <wx/taskbar.h> // For wxTaskBarIcon
#include "frame.h" // Include the main frame

class TaskBarIcon : public wxTaskBarIcon
{
public:
    TaskBarIcon(MainFrame* mainFrame);
    void OnButtonClick(wxTaskBarIconEvent&);

private:
    MainFrame* frame; // Pointer to main frame to show/hide
    DECLARE_EVENT_TABLE()
};


#endif // TASKBAR_H