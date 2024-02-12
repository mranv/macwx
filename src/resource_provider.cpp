#include "resource_provider.h"
#include "healthy_icon.h"
#include "error_icon.h"
#include "healthy_indicator.h"
#include "warning_indicator.h"
#include "error_indicator.h"
#include "not_found_indicator.h"
#include "logo.h"

ResourceProvider* ResourceProvider::instance = nullptr;

ResourceProvider& ResourceProvider::GetInstance() {
    if (!instance) {
        instance = new ResourceProvider();
    }
    return *instance;
}

ResourceProvider::ResourceProvider() {
    wxInitAllImageHandlers();  // Ensure the ICO handler is initialized
}

wxIcon ResourceProvider::GetHealthyIcon() {
    return LoadIconFromMemory(assets_icon_healthy_ico, assets_icon_healthy_ico_len);
}

wxIcon ResourceProvider::GetErrorIcon() {
    return LoadIconFromMemory(assets_icon_error_ico, assets_icon_error_ico_len);
}

wxImage ResourceProvider::GetHealthyIndicator() {
    return LoadImageFromMemory(assets_indicator_healthy_png, assets_indicator_healthy_png_len);
}

wxImage ResourceProvider::GetWarningIndicator() {
    return LoadImageFromMemory(assets_indicator_warning_png, assets_indicator_warning_png_len);
}

wxImage ResourceProvider::GetErrorIndicator() {
    return LoadImageFromMemory(assets_indicator_error_png, assets_indicator_error_png_len);
}

wxImage ResourceProvider::GetNotFoundIndicator() {
    return LoadImageFromMemory(assets_indicator_not_found_png, assets_indicator_not_found_png_len);
}

wxImage ResourceProvider::GetLogo() {
    return LoadImageFromMemory(assets_logo_png, assets_logo_png_len);
}

wxImage ResourceProvider::LoadImageFromMemory(const unsigned char* data, size_t size) {
    wxMemoryInputStream memStream(data, size);
    wxImage image(memStream, wxBITMAP_TYPE_ANY);

    if (image.IsOk()) {
        return image;
    }
    else {
        return wxImage();
    }
}

wxIcon ResourceProvider::LoadIconFromMemory(const unsigned char* data, size_t size) {
    wxMemoryInputStream memStream(data, size);
    wxImage image(memStream, wxBITMAP_TYPE_ANY);

    if (image.IsOk()) {
        wxBitmap bitmap(image);
        wxIcon icon;
        icon.CopyFromBitmap(bitmap);
        return icon;
    }
    else {
        return wxIcon();
    }
}
