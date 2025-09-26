#pragma once
#include "Prerequisites.h"

/**
 * @class Window
 * @brief Encapsula la gestión de una ventana de Windows para la aplicación.
 *
 * Esta clase maneja la creación, inicialización y administración de la ventana
 * principal de la aplicación, sirviendo como la superficie de presentación para el renderizado.
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
	 * @param hInstance Manejador de instancia de la aplicación.
	 * @param nCmdShow Parámetro que especifica cómo se debe mostrar la ventana.
	 * @param wndproc Puntero a la función de procedimiento de ventana (window procedure).
	 * @return S_OK si la creación fue exitosa; código HRESULT en caso contrario.
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
	 * @note Método de marcador, útil para manejar la lógica de la ventana (ej. eventos de entrada).
	 */
	void
		update();

	/**
	 * @brief Renderiza la ventana.
	 *
	 * Usualmente se utilizaría para forzar el repintado de áreas no cliente.
	 *
	 * @note Método de marcador.
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
	 * @brief Ancho de la ventana en píxeles.
	 */
	unsigned int m_width;
	/**
	 * @brief Alto de la ventana en píxeles.
	 */
	unsigned int m_height;
private:
	/**
	 * @brief Manejador de instancia de la aplicación.
	 */
	HINSTANCE m_hInst = nullptr;
	/**
	 * @brief Estructura que almacena las coordenadas del área cliente de la ventana.
	 */
	RECT m_rect;
	/**
	 * @brief Nombre o título de la ventana.
	 */
	std::string m_windowName = "Monaco Engine";
};