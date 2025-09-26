#pragma once
#include "Prerequisites.h"

/**
 * @class Window
 * @brief Encapsula la gesti�n de una ventana de Windows para la aplicaci�n.
 *
 * Esta clase maneja la creaci�n, inicializaci�n y administraci�n de la ventana
 * principal de la aplicaci�n, sirviendo como la superficie de presentaci�n para el renderizado.
 */
class
	Window {
public:
	/**
	 * @brief Constructor por defecto.
	 */
	Window() = default;

	/**
	 * @brief Destructor por defecto.
	 */
	~Window() = default;

	/**
	 * @brief Inicializa la ventana de Windows.
	 *
	 * Registra la clase de ventana y crea la instancia HWND.
	 *
	 * @param hInstance Manejador de instancia de la aplicaci�n.
	 * @param nCmdShow Par�metro que especifica c�mo se debe mostrar la ventana.
	 * @param wndproc Puntero a la funci�n de procedimiento de ventana (window procedure).
	 * @return S_OK si la creaci�n fue exitosa; c�digo HRESULT en caso contrario.
	 *
	 * @post Si retorna S_OK, m_hWnd != nullptr y se establecen m_width y m_height.
	 */
	HRESULT
		init(HINSTANCE hInstance, int nCmdShow, WNDPROC wndproc);

	/**
	 * @brief Actualiza el estado de la ventana.
	 *
	 * Maneja eventos, redimensionamiento u otras actualizaciones de estado.
	 *
	 * @note M�todo de marcador, �til para manejar la l�gica de la ventana (ej. eventos de entrada).
	 */
	void
		update();

	/**
	 * @brief Renderiza la ventana.
	 *
	 * Usualmente se utilizar�a para forzar el repintado de �reas no cliente.
	 *
	 * @note M�todo de marcador.
	 */
	void
		render();

	/**
	 * @brief Destruye la ventana y libera los recursos asociados.
	 *
	 * Libera el manejador de instancia y el HWND.
	 *
	 * @post m_hWnd == nullptr.
	 */
	void
		destroy();

public:
	/**
	 * @brief Manejador de la ventana de Windows.
	 */
	HWND m_hWnd = nullptr;
	/**
	 * @brief Ancho de la ventana en p�xeles.
	 */
	unsigned int m_width;
	/**
	 * @brief Alto de la ventana en p�xeles.
	 */
	unsigned int m_height;
private:
	/**
	 * @brief Manejador de instancia de la aplicaci�n.
	 */
	HINSTANCE m_hInst = nullptr;
	/**
	 * @brief Estructura que almacena las coordenadas del �rea cliente de la ventana.
	 */
	RECT m_rect;
	/**
	 * @brief Nombre o t�tulo de la ventana.
	 */
	std::string m_windowName = "Monaco Engine";
};