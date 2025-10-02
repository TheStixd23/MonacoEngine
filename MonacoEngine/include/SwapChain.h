#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;
class Window;
class Texture;

/**
 * @class SwapChain
 * @brief Envuelve un IDXGISwapChain para manejar buffers de presentación en pantalla.
 *
 * Un Swap Chain se encarga de gestionar los buffers de renderizado (front y back buffer)
 * y presentarlos en la ventana. También soporta MSAA para suavizado de bordes.
 */
class SwapChain {
public:
	/** Constructor por defecto */
	SwapChain() = default;

	/** Destructor por defecto
	 * @note No libera automáticamente; llamar a destroy().
	 */
	~SwapChain() = default;

	/** Inicializa el Swap Chain y obtiene el back buffer.
	 *
	 * Esto crea el swap chain asociado a una ventana específica y guarda
	 * el back buffer como textura para renderizar.
	 */
	HRESULT init(Device& device,
		DeviceContext& deviceContext,
		Texture& backBuffer,
		Window window);

	/** Actualiza parámetros internos del Swap Chain.
	 * @note Placeholder por ahora, útil si quieres manejar resize o cambios de MSAA dinámicamente.
	 */
	void update();

	/** Ejecuta operaciones de render relacionadas con el Swap Chain.
	 * @note Actualmente no hace nada; puede usarse para depuración.
	 */
	void render();

	/** Libera todos los recursos asociados al Swap Chain.
	 * Incluye interfaces DXGI de device, adapter y factory.
	 */
	void destroy();

	/** Presenta el back buffer en pantalla.
	 * @note Aquí se puede controlar V-Sync si se desea.
	 */
	void present();

public:
	/** Objeto principal del Swap Chain */
	IDXGISwapChain* m_swapChain = nullptr;

	/** Tipo de driver utilizado (hardware, referencia, software, etc.) */
	D3D_DRIVER_TYPE m_driverType = D3D_DRIVER_TYPE_NULL;

private:
	/** Nivel de características soportado por el dispositivo */
	D3D_FEATURE_LEVEL m_featureLevel = D3D_FEATURE_LEVEL_11_0;

	/** Número de muestras para MSAA (ej. 4 = 4x MSAA) */
	unsigned int m_sampleCount;

	/** Niveles de calidad soportados para MSAA */
	unsigned int m_qualityLevels;

	/** Interfaz DXGI para el dispositivo */
	IDXGIDevice* m_dxgiDevice = nullptr;

	/** Interfaz DXGI para el adaptador (GPU) */
	IDXGIAdapter* m_dxgiAdapter = nullptr;

	/** Interfaz DXGI para la fábrica (creación de swap chains) */
	IDXGIFactory* m_dxgiFactory = nullptr;
};
