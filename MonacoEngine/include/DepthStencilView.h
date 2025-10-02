#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;
class Texture;

/**
 * @class DepthStencilView
 * @brief Maneja un ID3D11DepthStencilView para usar un buffer de profundidad/esténcil.
 *
 * Básicamente, esta clase se encarga de crear, aplicar y liberar un DepthStencilView en Direct3D 11,
 * que necesitamos para decirle al pipeline cómo manejar la profundidad y el stencil.
 */
class DepthStencilView {
public:
	/**
	 * @brief Constructor por defecto.
	 * @note No crea nada todavía, solo inicializa la clase.
	 */
	DepthStencilView() = default;

	/**
	 * @brief Destructor por defecto.
	 * @note No libera automáticamente; hay que llamar a destroy() explícitamente.
	 */
	~DepthStencilView() = default;

	/**
	 * @brief Crea el DepthStencilView a partir de una textura de profundidad.
	 *
	 * @param device El dispositivo con el que se va a crear.
	 * @param depthStencil La textura que usaremos como buffer de profundidad/esténcil.
	 * @param format El formato DXGI que queremos usar (ej: DXGI_FORMAT_D24_UNORM_S8_UINT).
	 * @return S_OK si todo salió bien, o un HRESULT con el error si algo falló.
	 *
	 * @note Si devuelve S_OK, entonces m_depthStencilView ya apunta a algo válido.
	 * @sa destroy()
	 */
	HRESULT
		init(Device& device, Texture& depthStencil, DXGI_FORMAT format);

	/**
	 * @brief Actualiza cosas internas si es necesario.
	 *
	 * Por ahora no hace nada, pero queda por si necesitamos cambiar algo más adelante.
	 */
	void
		update() {};

	/**
	 * @brief Asigna este depth-stencil al pipeline para renderizar.
	 *
	 * Llama a OMSetRenderTargets para decirle al DeviceContext que use esta vista.
	 *
	 * @param deviceContext Contexto donde se va a enlazar el depth-stencil.
	 *
	 * @pre m_depthStencilView ya debe haberse creado con init().
	 */
	void
		render(DeviceContext& deviceContext);

	/**
	 * @brief Libera el recurso que tengamos en m_depthStencilView.
	 */
	void
		destroy();

public:
	/**
	 * @brief Puntero al DepthStencilView de Direct3D 11.
	 * @note Válido solo después de init(); se vuelve nullptr tras destroy().
	 */
	ID3D11DepthStencilView* m_depthStencilView = nullptr;
};
