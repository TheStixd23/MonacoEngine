#pragma once
#include "Prerequisites.h"

/**
 * @class Device
 * @brief Envuelve un ID3D11Device y facilita crear recursos en Direct3D 11.
 *
 * Esta clase es básicamente un contenedor para el dispositivo de D3D11.
 * Te da métodos para crear vistas, texturas, shaders, buffers y estados,
 * así no tienes que lidiar directamente con los detalles del API.
 *
 * @note No maneja automáticamente el DeviceContext.
 * @warning Asegúrate de llamar a init() antes de crear cualquier recurso.
 */
class Device {
public:
	/**
	 * @brief Constructor por defecto.
	 */
	Device() = default;

	/**
	 * @brief Destructor por defecto.
	 */
	~Device() = default;

	/**
	 * @brief Inicializa el dispositivo de Direct3D 11.
	 *
	 * Crea el ID3D11Device que necesitamos para trabajar.
	 *
	 * @post m_device != nullptr si todo salió bien.
	 */
	void init();

	/**
	 * @brief Actualiza parámetros internos.
	 * @note Por ahora no hace nada, pero sirve si queremos meter cosas más adelante.
	 */
	void update();

	/**
	 * @brief Aquí podríamos ejecutar tareas de render o manejo de recursos.
	 * @note Placeholder por ahora.
	 */
	void render();

	/**
	 * @brief Libera el ID3D11Device.
	 *
	 * @post m_device == nullptr.
	 */
	void destroy();

	/**
	 * @brief Crea una Render Target View (RTV).
	 */
	HRESULT CreateRenderTargetView(ID3D11Resource* pResource,
		const D3D11_RENDER_TARGET_VIEW_DESC* pDesc,
		ID3D11RenderTargetView** ppRTView);

	/**
	 * @brief Crea una textura 2D.
	 */
	HRESULT CreateTexture2D(const D3D11_TEXTURE2D_DESC* pDesc,
		const D3D11_SUBRESOURCE_DATA* pInitialData,
		ID3D11Texture2D** ppTexture2D);

	/**
	 * @brief Crea una Depth Stencil View (DSV).
	 */
	HRESULT CreateDepthStencilView(ID3D11Resource* pResource,
		const D3D11_DEPTH_STENCIL_VIEW_DESC* pDesc,
		ID3D11DepthStencilView** ppDepthStencilView);

	/**
	 * @brief Crea un Vertex Shader.
	 */
	HRESULT CreateVertexShader(const void* pShaderBytecode,
		unsigned int BytecodeLength,
		ID3D11ClassLinkage* pClassLinkage,
		ID3D11VertexShader** ppVertexShader);

	/**
	 * @brief Crea un Input Layout.
	 */
	HRESULT CreateInputLayout(const D3D11_INPUT_ELEMENT_DESC* pInputElementDescs,
		unsigned int NumElements,
		const void* pShaderBytecodeWithInputSignature,
		unsigned int BytecodeLength,
		ID3D11InputLayout** ppInputLayout);

	/**
	 * @brief Crea un Pixel Shader.
	 */
	HRESULT CreatePixelShader(const void* pShaderBytecode,
		unsigned int BytecodeLength,
		ID3D11ClassLinkage* pClassLinkage,
		ID3D11PixelShader** ppPixelShader);

	/**
	 * @brief Crea un Buffer genérico (vertex, index, constant, etc.).
	 */
	HRESULT CreateBuffer(const D3D11_BUFFER_DESC* pDesc,
		const D3D11_SUBRESOURCE_DATA* pInitialData,
		ID3D11Buffer** ppBuffer);

	/**
	 * @brief Crea un Sampler State.
	 */
	HRESULT CreateSamplerState(const D3D11_SAMPLER_DESC* pSamplerDesc,
		ID3D11SamplerState** ppSamplerState);

public:
	/**
	 * @brief Puntero al dispositivo Direct3D 11.
	 * @note Creado en init(), liberado en destroy().
	 */
	ID3D11Device* m_device = nullptr;
};
