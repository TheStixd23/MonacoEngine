#pragma once

/**
 * @file Prerequisites.h
 * @brief Cabecera principal del motor, incluye librer�as, macros y estructuras comunes.
 *
 * Aqu� van todas las cosas b�sicas que usamos en el motor de Direct3D 11:
 * librer�as, definiciones de macros �tiles y estructuras que se usan en shaders y buffers.
 */

 // --------------------------------------------------------------------------------------
 // Librer�as est�ndar
 // --------------------------------------------------------------------------------------
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include <xnamath.h>
#include <thread>

// --------------------------------------------------------------------------------------
// Librer�as DirectX
// --------------------------------------------------------------------------------------
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include "Resource.h"
#include "resource.h"

// --------------------------------------------------------------------------------------
// Macros �tiles
// --------------------------------------------------------------------------------------

/**
 * @def SAFE_RELEASE(x)
 * @brief Libera de manera segura un puntero COM de DirectX y lo deja en nullptr.
 */
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

 /**
  * @def MESSAGE(classObj, method, state)
  * @brief Macro para loggear mensajes de �xito al crear recursos.
  *
  * Escribe un mensaje bonito en la ventana de salida de Visual Studio.
  */
#define MESSAGE(classObj, method, state)	\
{	\
	std::wostringstream os_;	\
	os_ << classObj << "::" << method << " : " << "[CREATION OF RESOURCE " << ": " << state << "] \n"; \
	OutputDebugStringW(os_.str().c_str());	\
}

  /**
   * @def ERROR(classObj, method, errorMSG)
   * @brief Macro para loggear errores.
   *
   * Escribe un mensaje de error en la ventana de depuraci�n.
   * Maneja excepciones por si algo falla al registrar.
   */
#define ERROR(classObj, method, errorMSG)	\
{	\
	try {	\
		std::wostringstream os_;	\
		os_ << L"ERROR : " << classObj << L"::" << method << L" : " << errorMSG << L"\n";	\
		OutputDebugStringW(os_.str().c_str());	\
	} catch (...) {	\
		OutputDebugStringW(L"Failed to log error message.\n");\
	}	\
}

   // --------------------------------------------------------------------------------------
   // Estructuras b�sicas
   // --------------------------------------------------------------------------------------

   /** V�rtice simple para el Input Layout. */
struct SimpleVertex
{
	XMFLOAT3 Pos;  /**< Posici�n (X, Y, Z) */
	XMFLOAT2 Tex;  /**< Coordenadas de textura (U, V) */
};

/** Constant buffer para datos que casi nunca cambian (ej. la vista). */
struct CBNeverChanges
{
	XMMATRIX mView; /**< Matriz de vista */
};

/** Constant buffer para datos que cambian al redimensionar ventana (ej. la proyecci�n). */
struct CBChangeOnResize
{
	XMMATRIX mProjection; /**< Matriz de proyecci�n */
};

/** Constant buffer para datos que cambian cada frame (ej. la matriz de mundo). */
struct CBChangesEveryFrame
{
	XMMATRIX mWorld;     /**< Matriz de mundo */
	XMFLOAT4 vMeshColor; /**< Color del objeto o malla (RGBA) */
};

/** Tipos de extensi�n de archivo de textura soportados. */
enum ExtensionType {
	DDS = 0, /**< Textura DDS (DirectDraw Surface) */
	PNG = 1, /**< Textura PNG */
	JPG = 2  /**< Textura JPG/JPEG */
};
