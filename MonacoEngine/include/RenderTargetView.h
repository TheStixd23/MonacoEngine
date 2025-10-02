#pragma once
#include "Prerequisites.h"

// Forward Declarations
class Device;
class DeviceContext;
class Texture;
class DepthStencilView;

/**
 * @class RenderTargetView
 * @brief Envuelve un ID3D11RenderTargetView para usar una textura como destino de render.
 *
 * Esta clase se encarga de crear, configurar y usar un Render Target View (RTV) en Direct3D 11.
 * Básicamente te permite enviar el resultado del renderizado (color) a texturas o al back buffer.
 */
class RenderTargetView {
public:
	/** Constructor por defecto */
	RenderTargetView() = default;

	/** Destructor por defecto.
	 * @note No libera automáticamente, hay que llamar a destroy().
	 */
	~RenderTargetView() = default;

	/** Inicializa el RTV usando el back buffer de la swap chain */
	HRESULT init(Device& device, Texture& backBuffer, DXGI_FORMAT Format);

	/** Inicializa el RTV desde una textura genérica, útil para render targets auxiliares */
	HRESULT init(Device& device,
		Texture& inTex,
		D3D11_RTV_DIMENSION ViewDimension,
		DXGI_FORMAT Format);

	/** Actualiza parámetros internos del RTV.
	 * @note Placeholder por ahora, útil si quieres cambiar cosas dinámicamente en el futuro.
	 */
	void update();

	/**
	 * @brief Limpia y asigna el RTV junto con un Depth Stencil View.
	 *
	 * Esto llama a OMSetRenderTargets y ClearRenderTargetView para preparar
	 * el render target y limpiar con el color que quieras.
	 */
	void render(DeviceContext& deviceContext,
		DepthStencilView& depthStencilView,
		unsigned int numViews,
		const float ClearColor[4]);

	/**
	 * @brief Asigna el RTV al contexto sin limpiar ni usar Depth Stencil.
	 *
	 * Útil si solo quieres enlazar la textura sin tocar el DSV ni limpiar nada.
	 */
	void render(DeviceContext& deviceContext,
		unsigned int numViews);

	/** Libera el recurso COM de Direct3D 11.
	 * @note Seguro llamarlo varias veces.
	 */
	void destroy();

private:
	/** Puntero al recurso COM de Direct3D 11 para el Render Target View.
	 * Válido tras init(), nullptr tras destroy().
	 */
	ID3D11RenderTargetView* m_renderTargetView = nullptr;
};
