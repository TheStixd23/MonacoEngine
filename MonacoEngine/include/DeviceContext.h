#pragma once
#include "Prerequisites.h"

/**
 * @class DeviceContext
 * @brief Envuelve un ID3D11DeviceContext y te ayuda a manejar el pipeline de Direct3D 11.
 *
 * Esta clase maneja el contexto inmediato, que básicamente es el que manda comandos a la GPU.
 * Desde aquí puedes configurar shaders, buffers, vistas, estados de rasterización y más.
 */
class DeviceContext {
public:
	/**
	 * @brief Constructor por defecto.
	 */
	DeviceContext() = default;

	/**
	 * @brief Destructor por defecto.
	 */
	~DeviceContext() = default;

	/**
	 * @brief Inicializa el contexto del dispositivo.
	 * @note Aquí es donde normalmente se obtiene el contexto inmediato de D3D11.
	 * @post m_deviceContext != nullptr si todo salió bien.
	 */
	void init();

	/**
	 * @brief Actualiza parámetros internos.
	 * @note Por ahora es un placeholder, sirve para agregar cosas más adelante.
	 */
	void update();

	/**
	 * @brief Ejecuta tareas de render o debug.
	 * @note Placeholder también.
	 */
	void render();

	/**
	 * @brief Libera el contexto.
	 * @post m_deviceContext == nullptr.
	 */
	void destroy();

	// ---------------- Pipeline helpers ----------------

	/** Configura los viewports que se usarán en rasterización. */
	void RSSetViewports(unsigned int NumViewports, const D3D11_VIEWPORT* pViewports);

	/** Asigna Shader Resource Views al Pixel Shader. */
	void PSSetShaderResources(unsigned int StartSlot,
		unsigned int NumViews,
		ID3D11ShaderResourceView* const* ppShaderResourceViews);

	/** Establece el Input Layout activo en la etapa de Input Assembler. */
	void IASetInputLayout(ID3D11InputLayout* pInputLayout);

	/** Asigna un Vertex Shader al pipeline. */
	void VSSetShader(ID3D11VertexShader* pVertexShader,
		ID3D11ClassInstance* const* ppClassInstances,
		unsigned int NumClassInstances);

	/** Asigna un Pixel Shader al pipeline. */
	void PSSetShader(ID3D11PixelShader* pPixelShader,
		ID3D11ClassInstance* const* ppClassInstances,
		unsigned int NumClassInstances);

	/** Actualiza un recurso en GPU con datos de CPU de manera eficiente. */
	void UpdateSubresource(ID3D11Resource* pDstResource,
		unsigned int DstSubresource,
		const D3D11_BOX* pDstBox,
		const void* pSrcData,
		unsigned int SrcRowPitch,
		unsigned int SrcDepthPitch);

	/** Asigna buffers de vértices a la etapa de Input Assembler. */
	void IASetVertexBuffers(unsigned int StartSlot,
		unsigned int NumBuffers,
		ID3D11Buffer* const* ppVertexBuffers,
		const unsigned int* pStrides,
		const unsigned int* pOffsets);

	/** Asigna un Index Buffer a la etapa de Input Assembler. */
	void IASetIndexBuffer(ID3D11Buffer* pIndexBuffer,
		DXGI_FORMAT Format,
		unsigned int Offset);

	/** Asigna Sampler States al Pixel Shader. */
	void PSSetSamplers(unsigned int StartSlot,
		unsigned int NumSamplers,
		ID3D11SamplerState* const* ppSamplers);

	/** Configura el estado de rasterización actual. */
	void RSSetState(ID3D11RasterizerState* pRasterizerState);

	/** Asigna un Blend State al Output Merger. */
	void OMSetBlendState(ID3D11BlendState* pBlendState,
		const float BlendFactor[4],
		unsigned int SampleMask);

	/** Asigna Render Targets y Depth Stencil al Output Merger. */
	void OMSetRenderTargets(unsigned int NumViews,
		ID3D11RenderTargetView* const* ppRenderTargetViews,
		ID3D11DepthStencilView* pDepthStencilView);

	/** Define la topología de primitivas a renderizar. */
	void IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY Topology);

	/** Limpia un Render Target con un color RGBA. */
	void ClearRenderTargetView(ID3D11RenderTargetView* pRenderTargetView,
		const float ColorRGBA[4]);

	/** Limpia un Depth Stencil View. */
	void ClearDepthStencilView(ID3D11DepthStencilView* pDepthStencilView,
		unsigned int ClearFlags,
		float Depth,
		UINT8 Stencil);

	/** Asigna constant buffers al Vertex Shader. */
	void VSSetConstantBuffers(unsigned int StartSlot,
		unsigned int NumBuffers,
		ID3D11Buffer* const* ppConstantBuffers);

	/** Asigna constant buffers al Pixel Shader. */
	void PSSetConstantBuffers(unsigned int StartSlot,
		unsigned int NumBuffers,
		ID3D11Buffer* const* ppConstantBuffers);

	/** Dibuja primitivas indexadas. */
	void DrawIndexed(unsigned int IndexCount,
		unsigned int StartIndexLocation,
		int BaseVertexLocation);

public:
	/** Puntero al contexto inmediato de D3D11. Válido después de init(), liberado en destroy(). */
	ID3D11DeviceContext* m_deviceContext = nullptr;
};
