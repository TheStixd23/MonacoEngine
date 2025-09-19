#pragma once

// =====================
// Librerías estándar
// =====================
#include <string>
#include <sstream>
#include <vector>
#include <windows.h>
#include <xnamath.h>
#include <thread>

// =====================
// Librerías DirectX
// =====================
#include <d3d11.h>
#include <d3dx11.h>
#include <d3dcompiler.h>
#include "Resource.h"
#include "resource.h"

// =====================
// MACROS
// =====================

/**
 * @brief Libera un recurso COM seguro.
 */
#define SAFE_RELEASE(x) if(x != nullptr) x->Release(); x = nullptr;

 /**
  * @brief Muestra un mensaje de creación de recurso en el OutputDebugString.
  */
#define MESSAGE(classObj, method, state)         \
{                                                \
    std::wostringstream os_;                      \
    os_ << classObj << "::" << method << " : "   \
        << "[CREATION OF RESOURCE " << ": " << state << "] \n"; \
    OutputDebugStringW(os_.str().c_str());      \
}

  /**
   * @brief Muestra un mensaje de error en el OutputDebugString.
   */
#define ERROR(classObj, method, errorMSG)                \
{                                                        \
    try {                                                \
        std::wostringstream os_;                         \
        os_ << L"ERROR : " << classObj << L"::" << method \
            << L" : " << errorMSG << L"\n";             \
        OutputDebugStringW(os_.str().c_str());          \
    } catch (...) {                                      \
        OutputDebugStringW(L"Failed to log error message.\n"); \
    }                                                    \
}

   // =====================
   // Estructuras para shaders
   // =====================

   /**
    * @struct SimpleVertex
    * @brief Estructura de vértice simple con posición y coordenadas de textura.
    */
struct SimpleVertex
{
    XMFLOAT3 Pos;  /**< Posición del vértice */
    XMFLOAT2 Tex;  /**< Coordenadas de textura */
};

/**
 * @struct CBNeverChanges
 * @brief Constantes que nunca cambian durante el ciclo de vida del shader.
 */
struct CBNeverChanges
{
    XMMATRIX mView;  /**< Matriz de vista */
};

/**
 * @struct CBChangeOnResize
 * @brief Constantes que cambian solo al redimensionar la ventana.
 */
struct CBChangeOnResize
{
    XMMATRIX mProjection;  /**< Matriz de proyección */
};

/**
 * @struct CBChangesEveryFrame
 * @brief Constantes que cambian en cada frame.
 */
struct CBChangesEveryFrame
{
    XMMATRIX mWorld;      /**< Matriz world */
    XMFLOAT4 vMeshColor;  /**< Color del mesh */
};

// =====================
// Enumeraciones
// =====================

/**
 * @enum ExtensionType
 * @brief Tipos de extensión soportados para texturas.
 */
enum ExtensionType {
    DDS = 0,  /**< Formato DDS */
    PNG = 1,  /**< Formato PNG */
    JPG = 2   /**< Formato JPG */
};
