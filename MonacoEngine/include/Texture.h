#pragma once
#include "Prerequisites.h"

class Device;
class DeviceContext;

/**
 * @class Texture
 * @brief Encapsula un recurso de textura en Direct3D 11.
 *
 * Esta clase administra la creaci�n, actualizaci�n, renderizado y destrucci�n
 * de texturas en Direct3D.
 *
 * Soporta inicializaci�n desde:
 * - Archivos de imagen.
 * - Par�metros de tama�o y formato personalizados.
 * - Otra textura existente como referencia.
 */
class Texture {
public:
    /**
     * @brief Constructor por defecto.
     */
    Texture() = default;

    /**
     * @brief Destructor por defecto.
     * @details No libera autom�ticamente los recursos COM; llamar a destroy().
     */
    ~Texture() = default;

    /**
     * @brief Inicializa la textura a partir de un archivo de imagen.
     *
     * @param device        Dispositivo Direct3D.
     * @param textureName   Nombre o ruta del archivo de textura.
     * @param extensionType Tipo de extensi�n de la imagen (ej. PNG, JPG).
     * @return @c S_OK si fue exitoso; c�digo @c HRESULT en caso contrario.
     *
     * @post Si retorna @c S_OK, @c m_texture y @c m_textureFromImg != nullptr.
     */
    HRESULT init(Device& device,
        const std::string& textureName,
        ExtensionType extensionType);

    /**
     * @brief Inicializa una textura vac�a con dimensiones y formato definidos.
     *
     * @param device        Dispositivo Direct3D.
     * @param width         Ancho de la textura en p�xeles.
     * @param height        Alto de la textura en p�xeles.
     * @param Format        Formato de la textura (ej. DXGI_FORMAT_R8G8B8A8_UNORM).
     * @param BindFlags     Banderas de enlace (ej. D3D11_BIND_RENDER_TARGET).
     * @param sampleCount   N�mero de muestras para MSAA (por defecto 1).
     * @param qualityLevels Nivel de calidad de MSAA (por defecto 0).
     * @return @c S_OK si fue exitoso; c�digo @c HRESULT en caso contrario.
     */
    HRESULT init(Device& device,
        unsigned int width,
        unsigned int height,
        DXGI_FORMAT Format,
        unsigned int BindFlags,
        unsigned int sampleCount = 1,
        unsigned int qualityLevels = 0);

    /**
     * @brief Inicializa una textura a partir de otra ya existente.
     *
     * @param device     Dispositivo Direct3D.
     * @param textureRef Referencia a la textura base.
     * @param format     Nuevo formato para la textura.
     * @return @c S_OK si fue exitoso; c�digo @c HRESULT en caso contrario.
     */
    HRESULT init(Device& device, Texture& textureRef, DXGI_FORMAT format);

    /**
     * @brief Actualiza el contenido de la textura.
     *
     * M�todo de marcador para soporte de modificaciones din�micas.
     */
    void update();

    /**
     * @brief Asocia la textura al pipeline de renderizado.
     *
     * @param deviceContext Contexto de dispositivo utilizado para renderizar.
     * @param StartSlot     Slot inicial donde se enlazar� la textura.
     * @param NumViews      N�mero de vistas a asociar.
     */
    void render(DeviceContext& deviceContext, unsigned int StartSlot, unsigned int NumViews);

    /**
     * @brief Libera todos los recursos asociados a la textura.
     *
     * @post @c m_texture y @c m_textureFromImg == nullptr.
     */
    void destroy();

public:
    /**
     * @brief Objeto principal de la textura en Direct3D 11.
     */
    ID3D11Texture2D* m_texture = nullptr;

    /**
     * @brief Vista de recurso de la textura (para shaders).
     */
    ID3D11ShaderResourceView* m_textureFromImg = nullptr;

    /**
     * @brief Nombre o ruta asociada a la textura cargada.
     */
    std::string m_textureName;
};
