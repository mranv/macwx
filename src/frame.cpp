#include "frame.h"
#include "resource_provider.h"
#include <wx/stattext.h> // For wxStaticText

MainFrame::MainFrame(const wxString& title, const wxPoint& pos, const wxSize& size) : wxFrame(NULL, wxID_ANY, title, pos, size, wxFRAME_NO_TASKBAR | wxBORDER_NONE | wxFRAME_SHAPED)
{
    // Set the background color to a light blue
    SetBackgroundColour(wxColour(251, 252, 253));

    wxBitmap bitmap(GetSize().x, GetSize().y); // Create a bitmap the size of the window
    wxMemoryDC dc(bitmap);
    dc.SetBackground(*wxBLACK_BRUSH);
    dc.Clear();

    // Draw a white rounded rectangle in the area you want to keep
    dc.SetBrush(*wxWHITE_BRUSH);
    dc.DrawRoundedRectangle(0, 0, bitmap.GetWidth(), bitmap.GetHeight(), 10); // 20 is the radius of the corners

    // Deselect the bitmap from the device context
    dc.SelectObject(wxNullBitmap);

    // Now that the bitmap is not selected in the wxMemoryDC, you can use it elsewhere
    // Create a mask from the bitmap and apply it to the window
    wxMask* mask = new wxMask(bitmap, *wxBLACK); // Black is the transparent color
    bitmap.SetMask(mask);
    SetShape(wxRegion(bitmap));

    wxImage logoImage = ResourceProvider::GetInstance().GetLogo();

    // Create a static bitmap control to display the logo
    wxStaticBitmap* logo = new wxStaticBitmap(this, wxID_ANY, logoImage);

    // Get the size of the frame and the bitmap
    wxSize frameSize = this->GetSize();
    wxSize bitmapSize = logoImage.GetSize();

    // Calculate the position to place the bitmap at the bottom center of the frame
    int posX = 20;
    int posY = frameSize.GetHeight() - bitmapSize.GetHeight() - 2; // 5px margin from the bottom

    // Set the position of the logo
    logo->SetPosition(wxPoint(posX, posY));

    // Create the version text
    wxStaticText* versionText = new wxStaticText(this, wxID_ANY, wxT("V4.7.2"), wxDefaultPosition, wxDefaultSize, wxALIGN_LEFT);

    // Set an elegant and larger font
    wxFont versionFont = wxFont(22, // size
                                wxFONTFAMILY_SWISS, // family
                                wxFONTSTYLE_NORMAL, // style
                                wxFONTWEIGHT_BOLD, // weight
                                false, // no underline
                                wxT("Helvetica")); // face name
    versionText->SetFont(versionFont);
    versionText->SetForegroundColour(wxColour(0, 128, 0)); // A shade of green

    // Set the position of the version text
    versionText->SetPosition(wxPoint(posX + bitmapSize.GetX() + 5, posY + 20));

    // Set the window background to be transparent
    this->Bind(wxEVT_LEFT_DOWN, &MainFrame::OnMouseDown, this);
    this->Bind(wxEVT_RIGHT_DOWN, &MainFrame::OnMouseDown, this);


    wxImage indicatorImage = ResourceProvider::GetInstance().GetHealthyIndicator();

    // Create a static bitmap control to display the image
    imageControl = new wxStaticBitmap(this, wxID_ANY, indicatorImage);

    // Calculate the position to place the bitmap at the center of the frame
    posX = (frameSize.GetWidth() - indicatorImage.GetWidth()) / 2;
    posY = (frameSize.GetHeight() - indicatorImage.GetHeight()) / 2;

    // Set the position of the image
    imageControl->SetPosition(wxPoint(posX, posY));
}

void MainFrame::OnMouseDown(wxMouseEvent& event) {
    this->Hide();
    this->ChangeImage();
    this->Layout();
    this->Refresh();
}

void MainFrame::ChangeImage()
{
    if (++currentIndex > 3)
    {
        currentIndex = 0;
    }

    wxImage image;

    switch (currentIndex)
    {
        case 0:
            image = ResourceProvider::GetInstance().GetHealthyIndicator();
            break;
        case 1:
            image = ResourceProvider::GetInstance().GetWarningIndicator();
            break;
        case 2:
            image = ResourceProvider::GetInstance().GetErrorIndicator();
            break;
        default:
            image = ResourceProvider::GetInstance().GetNotFoundIndicator();
            break;
    }

    imageControl->SetBitmap(wxBitmap(image));

    // Adjust notification as needed for macOS
    wxNotificationMessage notification("title", "message", this);
    notification.SetFlags(wxICON_ASTERISK);
    notification.Show(10);
}

MainFrame::~MainFrame()
{
    // Optionally, clean up resources here
    // Need to prevent memory leaks
    // The frame is automatically deleted when the application exits
}
