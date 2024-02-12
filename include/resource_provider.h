#ifndef RESOURCEPROVIDER_H
#define RESOURCEPROVIDER_H

#include <wx/mstream.h>
#include <wx/image.h>
#include <wx/bitmap.h> // For wxBitmap
#include <wx/icon.h>
#include <string>
#include <unordered_map>

class ResourceProvider {
public:
	static ResourceProvider& GetInstance();

#pragma region TrayIcon
	wxIcon GetHealthyIcon();
	wxIcon GetErrorIcon();
#pragma endregion

#pragma region Component Status
	wxImage GetHealthyIndicator();
	wxImage GetWarningIndicator();
	wxImage GetErrorIndicator();
	wxImage GetNotFoundIndicator();
#pragma endregion

	wxImage GetLogo();

private:
	ResourceProvider(); // Private constructor
	static wxImage LoadImageFromMemory(const unsigned char* data, size_t size);
	static wxIcon LoadIconFromMemory(const unsigned char* data, size_t size);
	static ResourceProvider* instance; // Singleton instance
};

#endif // RESOURCEPROVIDER_H
