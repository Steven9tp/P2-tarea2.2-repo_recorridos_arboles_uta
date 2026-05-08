# Recorridos de Árboles Binarios en C++ y Java
Este proyecto implementa los cuatro tipos de recorridos de árboles binarios (Inorden, Preorden, Postorden y BFS) en dos lenguajes de programación: C++ y Java. El programa construye un árbol binario de enteros, aplica los recorridos, cuenta nodos y hojas, y finaliza con un caso aplicado a un Sistema de Gimnasio.

# Objetivo
Implementar y analizar los principales recorridos de árboles binarios utilizando C++ y Java, aplicando recursividad para los recorridos DFS (Inorden, Preorden, Postorden) y una cola para el recorrido BFS (nivel por nivel).

# Funcionalidades
|N|	Funcionalidad|	Descripción|
|-|---------------|-----------------|
|1|	Recorrido inorden|	Visita: izquierdo → raíz → derecho (orden ascendente)|
|2|	Recorrido preorden|	Visita: raíz → izquierdo → derecho|
|3|	Recorrido postorden|	Visita: izquierdo → derecho → raíz|
|4|	Recorrido BFS|	Visita nivel por nivel usando una cola|
|5|	Contar nodos|	Calcula el número total de nodos en el árbol|
|6|	Contar hojas|	Cuenta los nodos que no tienen hijos|
|7|	Caso aplicado|	Sistema de Gimnasio con justificación de recorridos|
Estructura del Proyecto
````
recorridos-arboles/
│
├── README.md
├── src/
│   ├── cpp/
│   │   └── main.cpp
│   └── java/
│       └── Main.java
````
# Código Fuente
*Librerías utilizadas (C++)
````
#include <iostream>  // Entrada/salida de datos
#include <queue>     // Cola para el recorrido BFS
#include <string>    // Manejo de cadenas (caso gimnasio)
````
* Librerías utilizadas (Java)
````
import java.util.*;  // Queue, LinkedList para BFS
````
* Estructuras principales (C++)
````
struct Nodo {
    int dato;
    Nodo* izquierda;
    Nodo* derecha;
};

struct NodoSistema {
    int id;
    string nombre;
    NodoSistema* izquierda;
    NodoSistema* derecha;
};
````
* Estructuras principales (Java)
````
class Nodo {
    int dato;
    Nodo izquierda;
    Nodo derecha;
}

class NodoSistema {
    int id;
    String nombre;
    NodoSistema izquierda;
    NodoSistema derecha;
}
````
# Compilación y Ejecución
Requisitos
C++: Compilador g++ (9.4 o superior)

Java: JDK (11 o superior)

* Compilar y ejecutar C++
````
cd src/cpp
g++ main.cpp -o recorridos
./recorridos
````
* Compilar y ejecutar Java
````
cd src/java
javac Main.java
java Main
````
* Datos de Prueba
Árbol inicial
Nodos: 10, 5, 15, 2, 7, 12, 20

Árbol modificado
Nodos agregados: 1, 3, 18, 25

Estructura esperada del árbol final
````
                10 (Raíz)
              /    \
             5      15
            / \    /  \
           2   7  12  20
          / \         / \
         1   3       18 25
````
# Resultados Esperados
|Recorrido	|Resultado|
|-|-|
|Inorden	|1, 2, 3, 5, 7, 10, 12, 15, 18, 20, 25|
|Preorden	|10, 5, 2, 1, 3, 7, 15, 12, 20, 18, 25|
|Postorden	|1, 3, 2, 7, 5, 12, 18, 25, 20, 15, 10|
|BFS	|10, 5, 15, 2, 7, 12, 20, 1, 3, 18, 25|
|Total de nodos	|11|
|Total de hojas|	6|

# Caso Aplicado: Sistema de Gimnasio
* Estructura del sistema
````
                1: Sistema Gimnasio (Raíz)
                /                      \
        2: Gestion Clientes          3: Gestion Pagos
           /          \                /          \
    4:Registrar   5:Actualizar   6:Procesar    7:Reportar
````
# Preguntas y respuestas
1. ¿Qué recorrido usar para mostrar el menú principal?
Preorden. Porque visita primero la raíz y luego los submenús.

2. ¿Qué recorrido usar para procesar primero los módulos internos?
Postorden. Porque procesa las hojas antes que los nodos padres.

3. ¿Qué recorrido usar para mostrar módulos nivel por nivel?
BFS. Porque muestra nivel 1, luego nivel 2, luego nivel 3.

# Salida del Programa
El programa ejecuta automáticamente cinco ejercicios:

* Recorridos del árbol original
* Recorridos del árbol con nuevos nodos
* Conteo total de nodos
* onteo de nodos hoja
* Caso aplicado del Sistema de Gimnasio

# Conceptos Teóricos Aplicados
|Concepto	|Definición|
|-|-|
|Inorden	|izquierdo → raíz → derecho|
|Preorden	|raíz → izquierdo → derecho|
|Postorden	|izquierdo → derecho → raíz|
|BFS	|nivel por nivel con cola|
|Nodo hoja|	nodo sin hijos|

#Recorridos Explicados
|Recorrido|	Orden|	Resultado ejemplo|
|-|-|-|
|Inorden|	Izquierdo → Raíz → Derecho|	1, 2, 3, 5, 7, 10, 12, 15, 18, 20, 25|
|Preorden|	Raíz → Izquierdo → Derecho|	10, 5, 2, 1, 3, 7, 15, 12, 20, 18, 25|
|Postorden|	Izquierdo → Derecho → Raíz|	1, 3, 2, 7, 5, 12, 18, 25, 20, 15, 10|
|BFS|	Nivel 1, luego nivel 2, luego nivel 3|	10, 5, 15, 2, 7, 12, 20, 1, 3, 18, 25|

#Conclusión
La implementación de los recorridos de árboles binarios en C++ y Java permite comprender las diferencias fundamentales entre los recorridos DFS (Inorden, Preorden, Postorden) y BFS. Los resultados obtenidos demuestran que el programa funciona correctamente en ambos lenguajes, cumpliendo con todos los objetivos planteados. El caso aplicado al Sistema de Gimnasio muestra la utilidad práctica de cada tipo de recorrido: Preorden para menús jerárquicos, Postorden para procesamiento interno y BFS para navegación por niveles. Este proyecto demuestra la importancia de los árboles binarios y sus recorridos en problemas reales como sistemas de menús, dashboards y estructuras jerárquicas.

