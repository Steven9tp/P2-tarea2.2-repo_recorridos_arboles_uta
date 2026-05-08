Recorridos de Árboles Binarios en C++ y Java
Descripción
Este proyecto implementa los cuatro tipos de recorridos de árboles binarios (Inorden, Preorden, Postorden y BFS) en dos lenguajes de programación: C++ y Java. El programa construye un árbol binario de enteros, aplica los recorridos, cuenta nodos y hojas, y finaliza con un caso aplicado a un Sistema de Gimnasio.

Objetivo
Implementar y analizar los principales recorridos de árboles binarios utilizando C++ y Java, aplicando recursividad para los recorridos DFS (Inorden, Preorden, Postorden) y una cola para el recorrido BFS (nivel por nivel).

Integrantes
Rol	Nombre
Líder	Carrasco Manotoa Cesar Steven
Programador 1	[Nombre - Implementación nodos y recorridos en C++]
Programador 2	[Nombre - Implementación nodos y recorridos en Java]
Programador 3	[Nombre - Funciones contar nodos y hojas]
Documentador	[Nombre - README]
Expositor	[Nombre - Presentación]
Funcionalidades
#	Funcionalidad	Descripción
1	Recorrido inorden	Visita: izquierdo → raíz → derecho (orden ascendente)
2	Recorrido preorden	Visita: raíz → izquierdo → derecho
3	Recorrido postorden	Visita: izquierdo → derecho → raíz
4	Recorrido BFS	Visita nivel por nivel usando una cola
5	Contar nodos	Calcula el número total de nodos en el árbol
6	Contar hojas	Cuenta los nodos que no tienen hijos
7	Caso aplicado	Sistema de Gimnasio con justificación de recorridos
Estructura del Proyecto
text
recorridos-arboles/
│
├── README.md              # Este archivo
├── src/
│   ├── cpp/
│   │   └── main.cpp       # Implementación en C++
│   └── java/
│       └── Main.java      # Implementación en Java
Código Fuente
Librerías utilizadas (C++)
cpp
#include <iostream>  // Entrada/salida de datos
#include <queue>     // Cola para el recorrido BFS
#include <string>    // Manejo de cadenas (caso gimnasio)
Librerías utilizadas (Java)
java
import java.util.*;  // Queue, LinkedList para BFS
Estructuras principales (C++)
Nodo: Representa cada elemento del árbol de enteros

cpp
struct Nodo {
    int dato;              // Valor entero del nodo
    Nodo* izquierda;       // Apuntador al hijo izquierdo
    Nodo* derecha;         // Apuntador al hijo derecho
};
NodoSistema: Representa cada módulo del caso aplicado

cpp
struct NodoSistema {
    int id;                // Identificador del módulo
    string nombre;         // Nombre del módulo
    NodoSistema* izquierda; // Submódulo izquierdo
    NodoSistema* derecha;   // Submódulo derecho
};
Estructuras principales (Java)
java
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
Compilación y Ejecución
Requisitos
C++: Compilador g++ (9.4 o superior)

Java: JDK (11 o superior)

Compilar y ejecutar C++
bash
cd src/cpp
g++ main.cpp -o recorridos
./recorridos        # En Linux/Mac
recorridos.exe      # En Windows
Compilar y ejecutar Java
bash
cd src/java
javac Main.java
java Main
Datos de Prueba Sugeridos
Árbol inicial (Ejercicio 1)
Nodos insertados en orden: 10, 5, 15, 2, 7, 12, 20

Árbol modificado (Ejercicio 2)
Nodos agregados: 1, 3, 18, 25

Estructura esperada del árbol final
text
                10 (Raíz)
              /    \
             5      15
            / \    /  \
           2   7  12  20
          / \         / \
         1   3       18 25
      (Hoja)(Hoja) (Hoja)(Hoja)
Resultados Esperados
Recorrido	Resultado
Inorden	1, 2, 3, 5, 7, 10, 12, 15, 18, 20, 25
Preorden	10, 5, 2, 1, 3, 7, 15, 12, 20, 18, 25
Postorden	1, 3, 2, 7, 5, 12, 18, 25, 20, 15, 10
BFS	10, 5, 15, 2, 7, 12, 20, 1, 3, 18, 25
Total de nodos	11
Total de hojas	6 (nodos 1, 3, 7, 12, 18, 25)
Caso Aplicado: Sistema de Gimnasio (Ejercicio 5)
Estructura esperada del sistema
text
                1: Sistema Gimnasio (Raíz)
                /                      \
        2: Gestion Clientes          3: Gestion Pagos
           /          \                /          \
    4:Registrar   5:Actualizar   6:Procesar    7:Reportar
      (Hoja)         (Hoja)         (Hoja)        (Hoja)
Preguntas y respuestas
Pregunta 1: ¿Qué recorrido usar para mostrar el menú principal?
Respuesta: Preorden. Porque visita primero la raíz (Sistema Gimnasio) y luego los submenús.

Pregunta 2: ¿Qué recorrido usar para procesar primero los módulos internos?
Respuesta: Postorden. Porque procesa las hojas antes que los nodos padres.

Pregunta 3: ¿Qué recorrido usar para mostrar módulos nivel por nivel?
Respuesta: BFS. Porque muestra nivel 1, luego nivel 2, luego nivel 3.

Salida del Programa
El programa ejecuta automáticamente los cinco ejercicios al iniciar, mostrando:

Recorridos del árbol original (10,5,15,2,7,12,20)

Recorridos del árbol con nuevos nodos (1,3,18,25)

Conteo total de nodos del árbol

Conteo de nodos hoja

Caso aplicado del Sistema de Gimnasio con justificaciones

Conceptos Teóricos Aplicados
Concepto	Definición	En el proyecto
Inorden	Recorrido: izquierdo → raíz → derecho	Orden ascendente: 1,2,3,5,7,10...
Preorden	Recorrido: raíz → izquierdo → derecho	Raíz primero: 10,5,2,1,3,7...
Postorden	Recorrido: izquierdo → derecho → raíz	Hojas primero: 1,3,2,7,5...
BFS	Recorrido nivel por nivel con cola	Nivel 1:10, Nivel 2:5,15...
Nodo hoja	Nodo sin hijos izquierdo ni derecho	Nodos 1, 3, 7, 12, 18, 25
Recorridos explicados
Recorrido	Orden de visita	Resultado ejemplo
Inorden	Izquierdo → Raíz → Derecho	1, 2, 3, 5, 7, 10, 12, 15, 18, 20, 25
Preorden	Raíz → Izquierdo → Derecho	10, 5, 2, 1, 3, 7, 15, 12, 20, 18, 25
Postorden	Izquierdo → Derecho → Raíz	1, 3, 2, 7, 5, 12, 18, 25, 20, 15, 10
BFS	Nivel 1, luego nivel 2, luego nivel 3	10, 5, 15, 2, 7, 12, 20, 1, 3, 18, 25
Conclusión
La implementación de los recorridos de árboles binarios en C++ y Java permite comprender las diferencias fundamentales entre los recorridos DFS (Inorden, Preorden, Postorden) y BFS. Los resultados obtenidos demuestran que el programa funciona correctamente en ambos lenguajes, cumpliendo con todos los objetivos planteados. El caso aplicado al Sistema de Gimnasio muestra la utilidad práctica de cada tipo de recorrido: Preorden para menús jerárquicos, Postorden para procesamiento interno y BFS para navegación por niveles. Este proyecto demuestra la importancia de los árboles binarios y sus recorridos en problemas reales como sistemas de menús, dashboards y estructuras jerárquicas.

