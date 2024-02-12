#ifndef FRAME_H
#define FRAME_H

#include <wx/graphics.h>
#include <wx/wx.h>
#include <wx/notifmsg.h>


class MainFrame : public wxFrame
{
public:
    MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size);
    ~MainFrame();
    void ChangeImage();

private:
	void OnMouseDown(wxMouseEvent& event);
    int currentIndex = 0;
    wxStaticBitmap* imageControl;
};


#endif // FRAME_H
