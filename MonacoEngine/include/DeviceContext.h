#pragma once
#include "Prerequisites.h"

/**
 * @class DeviceContext
 * @brief Encapsula un @c ID3D11DeviceContext en Direct3D 11.
 *
 * Esta clase proporciona métodos para configurar el pipeline de renderizado,
 * actualizar recursos, limpiar buffers y ejecutar draw calls.
 * Organiza los métodos según las etapas típicas del pipeline de Direct3D 11:
 * Input Assembler, Vertex Shader, Pixel Shader, Rasterizer y Output Merger.
 */
class DeviceContext {
public:
    /**
     * @brief Constructor por defecto.
     */
    DeviceContext() = default;

    /**
     * @brief Destructor por defecto.
     * @details No libera automáticamente el dispositivo; llamar a destroy().
     */
    ~DeviceContext() = default;

    // =====================
    // Ciclo de vida
    // =====================
    void init();
    void update();
    void render();
    void destroy();

    // =====================
    // Pipeline: Input Assembler
    // =====================
    void IASetInputLayout(ID3D11InputLayout* pInputLayout);
    void IASetVertexBuffers(unsigned int StartSlot,
        unsigned int NumBuffers,
        ID3D11Buffer* const* ppVertexBuffers,
        const unsigned int* pStrides,
        const unsigned int* pOffsets);
    void IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
        DXGI_FORMAT Format,
        unsigned int Offset);
    void IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

    // =====================
    // Pipeline: Vertex Shader
    // =====================
    void VSSetShader(ID3D11VertexShader* pVertexShader,
        ID3D11ClassInstance* const* ppClassInstances,
        unsigned int NumClassInstances);
    void VSSetConstantBuffers(unsigned int StartSlot,
        unsigned int NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers);

    // =====================
    // Pipeline: Pixel Shader
    // =====================
    void PSSetShader(ID3D11PixelShader* pPixelShader,
        ID3D11ClassInstance* const* ppClassInstances,
        unsigned int NumClassInstances);
    void PSSetShaderResources(unsigned int StartSlot,
        unsigned int NumViews,
        ID3D11ShaderResourceView* const* ppShaderResourceViews);
    void PSSetSamplers(unsigned int StartSlot,
        unsigned int NumSamplers,
        ID3D11SamplerState* const* ppSamplers);
    void PSSetConstantBuffers(unsigned int StartSlot,
        unsigned int NumBuffers,
        ID3D11Buffer* const* ppConstantBuffers);

    // =====================
    // Pipeline: Rasterizer
    // =====================
    void RSSetViewports(unsigned int NumViewports,
        const D3D11_VIEWPORT* pViewports);
    void RSSetState(ID3D11RasterizerState* pRasterizerState);

    // =====================
    // Pipeline: Output Merger
    // =====================
    void OMSetRenderTargets(unsigned int NumViews,
        ID3D11RenderTargetView* const* ppRenderTargetViews,
        ID3D11DepthStencilView* pDepthStencilView);
    void OMSetBlendState(ID3D11BlendState* pBlendState,
        const float BlendFactor[4],
        unsigned int SampleMask);

    // =====================
    // Limpieza de buffers
    // =====================
    void ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
        const float ColorRGBA[4]);
    void ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
        unsigned int ClearFlags,
        float Depth,
        UINT8 Stencil);

    // =====================
    // Recursos
    // =====================
    void UpdateSubresource(ID3D11Resource* pDstResource,
        unsigned int DstSubresource,
        const D3D11_BOX* pDstBox,
        const void* pSrcData,
        unsigned int SrcRowPitch,
        unsigned int SrcDepthPitch);

    // =====================
    // Draw
    // =====================
    void DrawIndexed(unsigned int IndexCount,
        unsigned int StartIndexLocation,
        int BaseVertexLocation);

public:
    /** @brief Contexto del dispositivo de Direct3D 11. */
    ID3D11DeviceContext* m_deviceContext = nullptr;
};
