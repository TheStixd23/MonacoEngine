#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;
class Texture;

/**
 * @class DepthStencilView
 * @brief Encapsula un ID3D11DepthStencilView para usar un recurso de profundidad/esténcil en el pipeline.
 *
 * Esta clase administra la creación, aplicación y liberación de un DepthStencilView en Direct3D 11,
 * necesario para vincular un buffer de profundidad/esténcil a la etapa de Output-Merger.
 *
 */
class DepthStencilView {
public:
	/**
	 * @brief Constructor por defecto (no crea recursos).
	 */
	DepthStencilView() = default;

	/**
	 * @brief Destructor por defecto.
	 * @details No libera automáticamente; llamar a destroy() explícitamente.
	 */
	~DepthStencilView() = default;

	/**
	 * @brief Inicializa el ID3D11DepthStencilView a partir de una textura de profundidad.
	 *
	 * Crea y asocia un DepthStencilView con el recurso proporcionado (generalmente una
	 * textura creada con D3D11_BIND_DEPTH_STENCIL).
	 *
	 * @param device Dispositivo con el que se creará el recurso.
	 * @param depthStencil Textura que servirá como buffer de profundidad/esténcil.
	 * @param format Formato DXGI con el que se creará la vista (ejemplo: DXGI_FORMAT_D24_UNORM_S8_UINT).
	 * @return S_OK si la creación fue exitosa; código HRESULT en caso contrario.
	 *
	 * @post Si retorna S_OK, m_depthStencilView != nullptr.
	 * @sa destroy()
	 */
	HRESULT
		init(Device& device, Texture& depthStencil, DXGI_FORMAT format);

	/**
	 * @brief Actualiza parámetros internos si se requieren cambios en el estado.
	 *
	 * Método de marcador para actualizar la configuración del recurso.
	 *
	 * @note Actualmente no realiza ninguna operación.
	 */
	void
		update() {};

	/**
	 * @brief Asigna la vista de profundidad/esténcil al pipeline de render.
	 *
	 * Llama a OMSetRenderTargets para asociar m_depthStencilView al DeviceContext.
	 *
	 * @param deviceContext Contexto de dispositivo donde se enlazará el depth-stencil view.
	 *
	 * @pre m_depthStencilView debe haberse creado con init().
	 */
	void
		render(DeviceContext& deviceContext);

	/**
	 * @brief Libera el recurso asociado al ID3D11DepthStencilView.
	 */
	void
		destroy();

public:
	/**
	 * @brief Vista de profundidad de Direct3D 11.
	 * @details Válido después de una llamada exitosa a init(); nullptr tras destroy().
	 */
	ID3D11DepthStencilView* m_depthStencilView = nullptr;
};