#include <iostream>
#include "main.h"
#include "taskbar.h"

#define main main

bool TrayApp::OnInit()
{
    // Get the size of the screen
    wxRect screenRect = wxGetClientDisplayRect();

    // Calculate the desired position and size
    int margin = 5; // Margin from the screen edges
    int frameWidth = 400;
    int frameHeight = 340;
    int posX = screenRect.GetWidth() - frameWidth - margin;
    int posY = screenRect.GetHeight() - frameHeight - margin;

	MainFrame* frame = new MainFrame("Tray App", wxPoint(posX, posY), wxSize(frameWidth, frameHeight));
	TaskBarIcon* taskBarIcon = new TaskBarIcon(frame);

	return true;
}

// This is the entry point for the application
IMPLEMENT_APP(TrayApp);