
#include "DepthStencilView.h"
#include "Texture.h"
#include "Device.h"
#include "DeviceContext.h"

// Implementaci�n de la funci�n init
HRESULT DepthStencilView::init(Device& device, Texture& depthStencil, DXGI_FORMAT format) {
    if (!device.m_device) {
        ERROR("DepthStencilView", "init", "Device is null.");
        return E_FAIL;
    }

    if (!depthStencil.m_texture) {
        ERROR("DepthStencilView", "init", "Texture is null.");
        return E_FAIL;
    }

    // Config depth stencil view description
    D3D11_DEPTH_STENCIL_VIEW_DESC descDSV;
    memset(&descDSV, 0, sizeof(descDSV));
    descDSV.Format = format;
    descDSV.ViewDimension = D3D11_DSV_DIMENSION_TEXTURE2DMS;
    descDSV.Texture2D.MipSlice = 0;

    // Create depth stencil view
    HRESULT hr = device.m_device->CreateDepthStencilView(depthStencil.m_texture, &descDSV, &m_depthStencilView);

    if (FAILED(hr)) {
        ERROR("DepthStencilView", "init",
            ("Failed to create depth stencil view. HRESULT: " + std::to_string(hr)).c_str());
        return hr;
    }

    return S_OK;
}

// Implementaci�n de la funci�n render
void DepthStencilView::render(DeviceContext& deviceContext) {
    if (!deviceContext.m_deviceContext) {
        ERROR("DepthStencilView", "render", "Device context is null.");
        return;
    }

    // Clear depth stencil view
    deviceContext.m_deviceContext->ClearDepthStencilView(m_depthStencilView,
        D3D11_CLEAR_DEPTH | D3D11_CLEAR_STENCIL,
        1.0f,
        0);
}

// Implementaci�n de la funci�n destroy
void DepthStencilView::destroy() {
    SAFE_RELEASE(m_depthStencilView);
}