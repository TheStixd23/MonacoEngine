#pragma once
#include "Prerequisites.h"

/**
 * @class Window
 * @brief Clase encargada de manejar la creaci�n, actualizaci�n, renderizado y destrucci�n de una ventana en la aplicaci�n.
 *
 * Esta clase abstrae las operaciones principales relacionadas con una ventana de Windows,
 * incluyendo la inicializaci�n con un procedimiento de ventana, la actualizaci�n del bucle de mensajes,
 * el renderizado y la destrucci�n de recursos asociados.
 */
class Window {
public:
    /**
     * @brief Constructor por defecto de la clase Window.
     */
    Window() = default;

    /**
     * @brief Destructor por defecto de la clase Window.
     */
    ~Window() = default;

    /**
     * @brief Inicializa la ventana.
     *
     * Crea y registra la ventana principal de la aplicaci�n, utilizando la instancia
     * del programa, el modo de visualizaci�n y el procedimiento de ventana definido.
     *
     * @param hInstance Instancia de la aplicaci�n.
     * @param nCmdShow Par�metro que indica c�mo se debe mostrar la ventana (minimizada, maximizada, normal, etc.).
     * @param wndproc Procedimiento de ventana que maneja los mensajes enviados a la ventana.
     * @return HRESULT C�digo de resultado de la operaci�n. Devuelve S_OK si fue exitoso, o un c�digo de error en caso contrario.
     */
    HRESULT init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc);

    /**
     * @brief Actualiza la ventana.
     *
     * Procesa la cola de mensajes de la ventana y ejecuta la l�gica de actualizaci�n correspondiente.
     */
    void update();

    /**
     * @brief Renderiza el contenido de la ventana.
     *
     * Llama al procedimiento encargado de dibujar el contenido en la ventana.
     */
    void render();

    /**
     * @brief Destruye la ventana y libera recursos.
     *
     * Se encarga de liberar los recursos asociados a la ventana y destruir el handle de la misma.
     */
    void destroy();

public:
    HWND m_hWnd = nullptr;            ///< Handle de la ventana.
    unsigned int m_width;             ///< Ancho de la ventana en p�xeles.
    unsigned int m_height;            ///< Alto de la ventana en p�xeles.

private:
    HINSTANCE m_hInst = nullptr;      ///< Instancia de la aplicaci�n.
    RECT m_rect;                      ///< Rect�ngulo que define las dimensiones de la ventana.
    std::string m_windowName = "MonacoEngine"; ///< Nombre por defecto de la ventana.
};
