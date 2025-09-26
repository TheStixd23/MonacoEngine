#pragma once
#include "Prerequisites.h"

// Forward Declarations
class Device;
class DeviceContext;
class Texture;
class DepthStencilView;

/**
 * @class RenderTargetView
 * @brief Encapsula un ID3D11RenderTargetView para usar un recurso como destino de renderizado en el pipeline.
 *
 * Esta clase administra la creación, configuración y uso de un Render Target View (RTV)
 * en Direct3D 11, permitiendo vincular texturas a la etapa de Output-Merger para
 * recibir el resultado del renderizado (color).
 */
class
	RenderTargetView {
public:
	/**
	 * @brief Constructor por defecto.
	 */
	RenderTargetView() = default;

	/**
	 * @brief Destructor por defecto.
	 * @details No libera automáticamente el recurso COM; llamar a destroy().
	 */
	~RenderTargetView() = default;

	/**
	 * @brief Inicializa el Render Target View desde el back buffer.
	 *
	 * @param device Dispositivo con el que se crea el recurso.
	 * @param backBuffer Textura que representa el back buffer (swap chain).
	 * @param Format Formato del RTV (ej. DXGI_FORMAT_R8G8B8A8_UNORM).
	 * @return S_OK si fue exitoso; código HRESULT en caso contrario.
	 *
	 * @post Si retorna S_OK, m_renderTargetView != nullptr.
	 */
	HRESULT
		init(Device& device, Texture& backBuffer, DXGI_FORMAT Format);

	/**
	 * @brief Inicializa el Render Target View desde una textura genérica.
	 *
	 * Crea un RTV con una dimensión y formato específicos, útil para render targets auxiliares.
	 *
	 * @param device Dispositivo con el que se crea el recurso.
	 * @param inTex Textura que será usada como destino de renderizado.
	 * @param ViewDimension Dimensión de la vista (ej. D3D11_RTV_DIMENSION_TEXTURE2D).
	 * @param Format Formato del RTV.
	 * @return S_OK si fue exitoso; código HRESULT en caso contrario.
	 */
	HRESULT
		init(Device& device,
			Texture& inTex,
			D3D11_RTV_DIMENSION ViewDimension,
			DXGI_FORMAT Format);

	/**
	 * @brief Actualiza parámetros internos del RTV.
	 *
	 * Método de marcador para futuras extensiones (por ejemplo, cambiar dinámicamente
	 * la configuración del RTV o recrearlo).
	 *
	 * @note Actualmente no realiza ninguna operación.
	 */
	void
		update();

	/**
	 * @brief Limpia y asigna el RTV junto con un Depth Stencil View (DSV).
	 *
	 * Llama a OMSetRenderTargets y ClearRenderTargetView para establecer y limpiar el destino.
	 *
	 * @param deviceContext Contexto de dispositivo donde se aplicará.
	 * @param depthStencilView Depth Stencil View a asociar.
	 * @param numViews Número de vistas de render (típicamente 1).
	 * @param ClearColor Color RGBA usado para limpiar el RTV.
	 *
	 * @pre m_renderTargetView debe estar creado con init().
	 */
	void
		render(DeviceContext& deviceContext,
			DepthStencilView& depthStencilView,
			unsigned int numViews,
			const float ClearColor[4]);

	/**
	 * @brief Asigna el RTV al contexto sin limpiar ni usar Depth Stencil.
	 *
	 * Llama a OMSetRenderTargets solo con el RTV y un puntero nulo para DSV.
	 *
	 * @param deviceContext Contexto de dispositivo donde se aplicará.
	 * @param numViews Número de vistas de render (típicamente 1).
	 *
	 * @pre m_renderTargetView debe estar creado con init().
	 */
	void
		render(DeviceContext& deviceContext,
			unsigned int numViews);

	/**
	 * @brief Libera el recurso ID3D11RenderTargetView.
	 *
	 * Idempotente: puede llamarse múltiples veces de forma segura.
	 *
	 * @post m_renderTargetView == nullptr.
	 */
	void
		destroy();
private:
	/**
	 * @brief Recurso COM de Direct3D 11 para la vista de Render Target.
	 * @details Válido tras init(); nullptr después de destroy().
	 */
	ID3D11RenderTargetView* m_renderTargetView = nullptr;
};