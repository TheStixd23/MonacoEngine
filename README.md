MonacoEngine
📌 Descripción del Proyecto

MonacoEngine es un motor gráfico desarrollado en C++ con DirectX 11, orientado a la experimentación con renderizado en tiempo real y gestión de recursos gráficos.
Este proyecto forma parte del parcial de Gráficas Computacionales 3D y tiene como objetivo implementar un pipeline gráfico completo, documentar su arquitectura y demostrar su funcionamiento.

🎯 Objetivos del Proyecto

Comprender y aplicar los conceptos del pipeline gráfico en Direct3D 11.

Implementar clases para la carga, gestión y renderizado de texturas, buffers y shaders.

Diseñar una arquitectura modular que permita extender el motor con nuevas funcionalidades.

Generar documentación clara y profesional para el parcial.

🛠️ Arquitectura del Motor

El motor está compuesto por varios módulos principales:

🔹 Diagrama de Arquitectura (UML simplificado)
classDiagram
    class Engine {
        +Init()
        +Run()
        +Shutdown()
    }

    class Device {
        +CreateResources()
    }

    class DeviceContext {
        +Draw()
        +SetPipelineState()
    }

    class Texture {
        +LoadFromFile()
        +Bind()
    }

    class Shader {
        +Compile()
        +Bind()
    }

    class Pipeline {
        +SetShaders()
        +SetResources()
        +Execute()
    }

    Engine --> Device
    Engine --> DeviceContext
    DeviceContext --> Pipeline
    Pipeline --> Shader
    Pipeline --> Texture

🎨 Explicación del Pipeline Implementado

El pipeline implementado en MonacoEngine sigue la estructura de Direct3D 11:

Input Assembler (IA)

Se cargan vértices y sus atributos desde vertex buffers.

Se aplican layouts para interpretar la información.

Vertex Shader (VS)

Procesa cada vértice (posición, color, normales, UV).

Realiza transformaciones MVP (Model-View-Projection).

Rasterizer Stage (RS)

Convierte la geometría en fragmentos/píxeles.

Se aplican reglas de recorte, backface culling y viewport.

Pixel Shader (PS)

Calcula el color de cada píxel.

Se combinan texturas, luces y materiales.

Output Merger (OM)

Se integran los resultados en el Render Target View (RTV).

Aplica Depth-Stencil View (DSV) para pruebas de profundidad y stencil.

📂 Estructura del Proyecto
MonacoEngine/
 ├── include/        # Headers del motor
 ├── src/            # Implementación de clases
 ├── shaders/        # HLSL shaders
 ├── assets/         # Texturas y modelos
 ├── README.md       # Documentación
 └── main.cpp        # Punto de entrada