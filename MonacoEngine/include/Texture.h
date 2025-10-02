#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

/**
 * @class Texture
 * @brief Envuelve una textura 2D en Direct3D 11, incluyendo su recurso y Shader Resource View.
 *
 * Se encarga de texturas cargadas desde archivo, creadas en memoria o copias de otras texturas.
 * Permite inicialización, actualización, asignación a shaders y destrucción segura.
 */
class Texture {
public:
	/** Constructor por defecto */
	Texture() = default;

	/** Destructor por defecto
	 * @note No libera automáticamente; hay que llamar a destroy().
	 */
	~Texture() = default;

	/** Inicializa la textura desde un archivo (png, jpg, dds, etc.)
	 *
	 * Crea el recurso y su ShaderResourceView para poder usarla en shaders.
	 */
	HRESULT init(Device& device,
		const std::string& textureName,
		ExtensionType extensionType);

	/** Inicializa una textura desde memoria
	 *
	 * Útil para render targets, depth buffers o texturas dinámicas.
	 */
	HRESULT init(Device& device,
		unsigned int width,
		unsigned int height,
		DXGI_FORMAT Format,
		unsigned int BindFlags,
		unsigned int sampleCount = 1,
		unsigned int qualityLevels = 0);

	/** Inicializa una textura a partir de otra existente
	 *
	 * Permite crear una nueva textura basada en otra, posiblemente con un formato distinto.
	 */
	HRESULT init(Device& device, Texture& textureRef, DXGI_FORMAT format);

	/** Actualiza la textura
	 * @note Placeholder por ahora; útil si quieres actualizar datos dinámicamente desde CPU a GPU.
	 */
	void update();

	/** Asigna la textura al pipeline de render
	 *
	 * Llama a PSSetShaderResources para poner la textura como recurso de Pixel Shader.
	 */
	void render(DeviceContext& deviceContext, unsigned int StartSlot, unsigned int NumViews);

	/** Libera recursos de la textura
	 *
	 * Libera tanto la textura como su ShaderResourceView asociada.
	 */
	void destroy();

public:
	/** Recurso base de la textura en GPU */
	ID3D11Texture2D* m_texture = nullptr;

	/** ShaderResourceView de la textura, para usar en shaders */
	ID3D11ShaderResourceView* m_textureFromImg = nullptr;

	/** Nombre o ruta de la textura (si proviene de archivo) */
	std::string m_textureName;
};
