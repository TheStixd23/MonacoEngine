#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;
class Texture;

/**
 * @class DepthStencilView
 * @brief Encapsula un ID3D11DepthStencilView para usar un recurso de profundidad/est�ncil en el pipeline.
 *
 * Esta clase administra la creaci�n, aplicaci�n y liberaci�n de un DepthStencilView en Direct3D 11,
 * necesario para vincular un buffer de profundidad/est�ncil a la etapa de Output-Merger.
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
	 * @details No libera autom�ticamente; llamar a destroy() expl�citamente.
	 */
	~DepthStencilView() = default;

	/**
	 * @brief Inicializa el ID3D11DepthStencilView a partir de una textura de profundidad.
	 *
	 * Crea y asocia un DepthStencilView con el recurso proporcionado (generalmente una
	 * textura creada con D3D11_BIND_DEPTH_STENCIL).
	 *
	 * @param device Dispositivo con el que se crear� el recurso.
	 * @param depthStencil Textura que servir� como buffer de profundidad/est�ncil.
	 * @param format Formato DXGI con el que se crear� la vista (ejemplo: DXGI_FORMAT_D24_UNORM_S8_UINT).
	 * @return S_OK si la creaci�n fue exitosa; c�digo HRESULT en caso contrario.
	 *
	 * @post Si retorna S_OK, m_depthStencilView != nullptr.
	 * @sa destroy()
	 */
	HRESULT
		init(Device& device, Texture& depthStencil, DXGI_FORMAT format);

	/**
	 * @brief Actualiza par�metros internos si se requieren cambios en el estado.
	 *
	 * M�todo de marcador para actualizar la configuraci�n del recurso.
	 *
	 * @note Actualmente no realiza ninguna operaci�n.
	 */
	void
		update() {};

	/**
	 * @brief Asigna la vista de profundidad/est�ncil al pipeline de render.
	 *
	 * Llama a OMSetRenderTargets para asociar m_depthStencilView al DeviceContext.
	 *
	 * @param deviceContext Contexto de dispositivo donde se enlazar� el depth-stencil view.
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
	 * @details V�lido despu�s de una llamada exitosa a init(); nullptr tras destroy().
	 */
	ID3D11DepthStencilView* m_depthStencilView = nullptr;
};