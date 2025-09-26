#pragma once

/**
 * @file Prerequisites.h
 * @brief Archivo de cabecera principal que incluye librer�as, macros y estructuras comunes
 * utilizadas en el motor de renderizado Direct3D 11.
 */

 // --------------------------------------------------------------------------------------
 // Librerias STD
 // --------------------------------------------------------------------------------------
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include <xnamath.h>
#include <thread>

// --------------------------------------------------------------------------------------
// Librerias DirectX
// --------------------------------------------------------------------------------------
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include "Resource.h"
#include "resource.h"

// Third Party Libraries

// --------------------------------------------------------------------------------------
// MACROS
// --------------------------------------------------------------------------------------

/**
 * @def SAFE_RELEASE(x)
 * @brief Macro para liberar con seguridad una interfaz COM de DirectX.
 *
 * Libera la interfaz si no es nula y luego establece el puntero a nullptr.
 */
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

 /**
  * @def MESSAGE( classObj, method, state )
  * @brief Macro de depuraci�n para registrar mensajes de �xito en la creaci�n de recursos.
  *
  * Escribe un mensaje formateado en la ventana de salida de depuraci�n de Visual Studio.
  *
  * @param classObj Nombre de la clase.
  * @param method Nombre del m�todo.
  * @param state Mensaje de estado (ej. "OK").
  */
#define MESSAGE( classObj, method, state )	\
{	\
	std::wostringstream os_;	\
	os_ << classObj << "::" << method << " : " << "[CREATION OF RESOURCE " << ": " << state << "] \n"; \
	OutputDebugStringW( os_.str().c_str() );	\
}

  /**
   * @def ERROR(classObj, method, errorMSG)
   * @brief Macro de depuraci�n para registrar mensajes de error.
   *
   * Escribe un mensaje de error formateado en la ventana de salida de depuraci�n.
   * Incluye manejo de excepci�n b�sico para evitar fallos durante el registro.
   *
   * @param classObj Nombre de la clase.
   * @param method Nombre del m�todo.
   * @param errorMSG Mensaje de error detallado.
   */
#define ERROR(classObj, method, errorMSG)	\
{	\
	 try {	\
		 std::wostringstream os_;	\
		 os_ << L"ERROR : " << classObj << L"::" << method	\
			 << L" : " << errorMSG << L"\n";	\
		 OutputDebugStringW(os_.str().c_str());	\
	 } catch (...) {	\
		 OutputDebugStringW(L"Failed to log error message.\n");\
	 }	\
}

   // --------------------------------------------------------------------------------------
   // Structures
   // --------------------------------------------------------------------------------------

   /**
	* @brief Estructura de v�rtice b�sica utilizada para el Input Layout.
	*/
struct SimpleVertex
{
	/** Posici�n del v�rtice (X, Y, Z). */
	XMFLOAT3 Pos;
	/** Coordenadas de textura (U, V). */
	XMFLOAT2 Tex;
};

/**
 * @brief Buffer de constantes para datos que cambian raramente (ej. la vista).
 */
struct CBNeverChanges
{
	/** Matriz de vista (View Matrix). */
	XMMATRIX mView;
};

/**
 * @brief Buffer de constantes para datos que cambian al redimensionar la ventana (ej. la proyecci�n).
 */
struct CBChangeOnResize
{
	/** Matriz de proyecci�n (Projection Matrix). */
	XMMATRIX mProjection;
};

/**
 * @brief Buffer de constantes para datos que cambian cada frame (ej. la matriz de mundo).
 */
struct CBChangesEveryFrame
{
	/** Matriz de mundo (World Matrix). */
	XMMATRIX mWorld;
	/** Color del objeto o malla (RGBA). */
	XMFLOAT4 vMeshColor;
};

/**
 * @enum ExtensionType
 * @brief Tipos de extensi�n de archivo de textura soportados para la carga.
 */
enum ExtensionType {
	/** Textura DDS (DirectDraw Surface). */
	DDS = 0,
	/** Textura PNG. */
	PNG = 1,
	/** Textura JPG/JPEG. */
	JPG = 2
};