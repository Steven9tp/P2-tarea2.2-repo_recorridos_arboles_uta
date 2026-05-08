#include <iostream>
#include <queue>
#include <string>
using namespace std;

// Estructura para los ejercicios 1-4
struct Nodo {
  int dato;
  Nodo *izquierda;
  Nodo *derecha;

  Nodo(int valor) {
    dato = valor;
    izquierda = nullptr;
    derecha = nullptr;
  }
};

// Estructura específica para el Ejercicio 5 (Caso aplicado)
struct NodoSistema {
  int id;
  string nombre;
  NodoSistema *izquierda;
  NodoSistema *derecha;

  NodoSistema(int _id, string _nombre) {
    id = _id;
    nombre = _nombre;
    izquierda = nullptr;
    derecha = nullptr;
  }
};

// ==================== FUNCIONES COMUNES (Ejercicios 1-4) ====================
void preorden(Nodo *raiz) {
  if (raiz == nullptr) return;
  cout << raiz->dato << " ";
  preorden(raiz->izquierda);
  preorden(raiz->derecha);
}

void inorden(Nodo *raiz) {
  if (raiz == nullptr) return;
  inorden(raiz->izquierda);
  cout << raiz->dato << " ";
  inorden(raiz->derecha);
}

void postorden(Nodo *raiz) {
  if (raiz == nullptr) return;
  postorden(raiz->izquierda);
  postorden(raiz->derecha);
  cout << raiz->dato << " ";
}

void bfs(Nodo *raiz) {
  if (raiz == nullptr) return;
  queue<Nodo *> cola;
  cola.push(raiz);
  while (!cola.empty()) {
    Nodo *actual = cola.front();
    cola.pop();
    cout << actual->dato << " ";
    if (actual->izquierda != nullptr) cola.push(actual->izquierda);
    if (actual->derecha != nullptr) cola.push(actual->derecha);
  }
}

// ==================== FUNCIONES PARA RECORRIDOS DEL SISTEMA (Ejercicio 5) ====================
void preordenSistema(NodoSistema *raiz) {
  if (raiz == nullptr) return;
  cout << raiz->id << ":" << raiz->nombre << "  ";
  preordenSistema(raiz->izquierda);
  preordenSistema(raiz->derecha);
}

void inordenSistema(NodoSistema *raiz) {
  if (raiz == nullptr) return;
  inordenSistema(raiz->izquierda);
  cout << raiz->id << ":" << raiz->nombre << "  ";
  inordenSistema(raiz->derecha);
}

void postordenSistema(NodoSistema *raiz) {
  if (raiz == nullptr) return;
  postordenSistema(raiz->izquierda);
  postordenSistema(raiz->derecha);
  cout << raiz->id << ":" << raiz->nombre << "  ";
}

void bfsSistema(NodoSistema *raiz) {
  if (raiz == nullptr) return;
  queue<NodoSistema *> cola;
  cola.push(raiz);
  while (!cola.empty()) {
    NodoSistema *actual = cola.front();
    cola.pop();
    cout << actual->id << ":" << actual->nombre << "  ";
    if (actual->izquierda != nullptr) cola.push(actual->izquierda);
    if (actual->derecha != nullptr) cola.push(actual->derecha);
  }
}

// ==================== FUNCIONES PARA EJERCICIOS 3 Y 4 ====================
int contarNodos(Nodo *raiz) {
  if (raiz == nullptr) return 0;
  return 1 + contarNodos(raiz->izquierda) + contarNodos(raiz->derecha);
}

int contarHojas(Nodo *raiz) {
  if (raiz == nullptr) return 0;
  if (raiz->izquierda == nullptr && raiz->derecha == nullptr) return 1;
  return contarHojas(raiz->izquierda) + contarHojas(raiz->derecha);
}

// ==================== EJERCICIO 1 ====================
void ejercicio1() {
  cout << "\n========================================" << endl;
  cout << "              EJERCICIO 1                " << endl;
  cout << "    Arbol original (10,5,15,2,7,12,20)   " << endl;
  cout << "========================================\n" << endl;

  Nodo *raiz = new Nodo(10);
  raiz->izquierda = new Nodo(5);
  raiz->derecha = new Nodo(15);
  raiz->izquierda->izquierda = new Nodo(2);
  raiz->izquierda->derecha = new Nodo(7);
  raiz->derecha->izquierda = new Nodo(12);
  raiz->derecha->derecha = new Nodo(20);

  cout << "Estructura del arbol:" << endl;
  cout << "        10" << endl;
  cout << "       /  \\" << endl;
  cout << "      5    15" << endl;
  cout << "     / \\   / \\" << endl;
  cout << "    2   7 12 20\n" << endl;

  cout << "--- RECORRIDOS ---" << endl;
  cout << "Preorden:  "; preorden(raiz);
  cout << "\nInorden:   "; inorden(raiz);
  cout << "\nPostorden: "; postorden(raiz);
  cout << "\nBFS:       "; bfs(raiz);
  cout << "\n" << endl;
}

// ==================== EJERCICIO 2 ====================
void ejercicio2() {
  cout << "\n========================================" << endl;
  cout << "              EJERCICIO 2                " << endl;
  cout << "  Arbol modificado (agregando 1,3,18,25) " << endl;
  cout << "========================================\n" << endl;

  Nodo *raiz = new Nodo(10);
  raiz->izquierda = new Nodo(5);
  raiz->derecha = new Nodo(15);
  raiz->izquierda->izquierda = new Nodo(2);
  raiz->izquierda->derecha = new Nodo(7);
  raiz->derecha->izquierda = new Nodo(12);
  raiz->derecha->derecha = new Nodo(20);

  raiz->izquierda->izquierda->izquierda = new Nodo(1);
  raiz->izquierda->izquierda->derecha = new Nodo(3);
  raiz->derecha->derecha->izquierda = new Nodo(18);
  raiz->derecha->derecha->derecha = new Nodo(25);

  cout << "Estructura del arbol modificado:" << endl;
  cout << "          10" << endl;
  cout << "       /     \\" << endl;
  cout << "      5       15" << endl;
  cout << "     / \\     / \\" << endl;
  cout << "    2   7   12 20" << endl;
  cout << "   / \\         / \\" << endl;
  cout << "  1   3       18 25\n" << endl;

  cout << "--- RECORRIDOS DEL ARBOL MODIFICADO ---" << endl;
  cout << "Preorden:  "; preorden(raiz);
  cout << "\nInorden:   "; inorden(raiz);
  cout << "\nPostorden: "; postorden(raiz);
  cout << "\nBFS:       "; bfs(raiz);
  cout << "\n" << endl;
}

// ==================== EJERCICIO 3 ====================
void ejercicio3() {
  cout << "\n========================================" << endl;
  cout << "              EJERCICIO 3                " << endl;
  cout << "       Funcion para contar nodos         " << endl;
  cout << "========================================\n" << endl;

  Nodo *raiz = new Nodo(10);
  raiz->izquierda = new Nodo(5);
  raiz->derecha = new Nodo(15);
  raiz->izquierda->izquierda = new Nodo(2);
  raiz->izquierda->derecha = new Nodo(7);
  raiz->derecha->izquierda = new Nodo(12);
  raiz->derecha->derecha = new Nodo(20);
  raiz->izquierda->izquierda->izquierda = new Nodo(1);
  raiz->izquierda->izquierda->derecha = new Nodo(3);
  raiz->derecha->derecha->izquierda = new Nodo(18);
  raiz->derecha->derecha->derecha = new Nodo(25);

  cout << "Codigo de la funcion:" << endl;
  cout << "+---------------------------------------------------+" << endl;
  cout << "| int contarNodos(Nodo* raiz) {                    |" << endl;
  cout << "|     if (raiz == nullptr) return 0;               |" << endl;
  cout << "|     return 1 + contarNodos(raiz->izquierda) +    |" << endl;
  cout << "|            contarNodos(raiz->derecha);           |" << endl;
  cout << "| }                                                |" << endl;
  cout << "+---------------------------------------------------+\n" << endl;

  cout << "--- RECORRIDOS DEL ARBOL ---" << endl;
  cout << "Preorden:  "; preorden(raiz);
  cout << "\nInorden:   "; inorden(raiz);
  cout << "\nPostorden: "; postorden(raiz);
  cout << "\nBFS:       "; bfs(raiz);

  cout << "\n\n--- RESULTADO ---" << endl;
  cout << "Total de nodos en el arbol: " << contarNodos(raiz) << endl;
  cout << "\n" << endl;
}

// ==================== EJERCICIO 4 ====================
void ejercicio4() {
  cout << "\n========================================" << endl;
  cout << "              EJERCICIO 4                " << endl;
  cout << "       Funcion para contar hojas         " << endl;
  cout << "========================================\n" << endl;

  Nodo *raiz = new Nodo(10);
  raiz->izquierda = new Nodo(5);
  raiz->derecha = new Nodo(15);
  raiz->izquierda->izquierda = new Nodo(2);
  raiz->izquierda->derecha = new Nodo(7);
  raiz->derecha->izquierda = new Nodo(12);
  raiz->derecha->derecha = new Nodo(20);
  raiz->izquierda->izquierda->izquierda = new Nodo(1);
  raiz->izquierda->izquierda->derecha = new Nodo(3);
  raiz->derecha->derecha->izquierda = new Nodo(18);
  raiz->derecha->derecha->derecha = new Nodo(25);

  cout << "Codigo de la funcion:" << endl;
  cout << "+---------------------------------------------------+" << endl;
  cout << "| int contarHojas(Nodo* raiz) {                    |" << endl;
  cout << "|     if (raiz == nullptr) return 0;               |" << endl;
  cout << "|     if (raiz->izquierda == nullptr &&            |" << endl;
  cout << "|         raiz->derecha == nullptr) return 1;      |" << endl;
  cout << "|     return contarHojas(raiz->izquierda) +        |" << endl;
  cout << "|            contarHojas(raiz->derecha);           |" << endl;
  cout << "| }                                                |" << endl;
  cout << "+---------------------------------------------------+\n" << endl;

  cout << "Identificacion de hojas (nodos sin hijos):" << endl;
  cout << "  - Nodo 1: sin hijos -> es hoja" << endl;
  cout << "  - Nodo 3: sin hijos -> es hoja" << endl;
  cout << "  - Nodo 7: sin hijos -> es hoja" << endl;
  cout << "  - Nodo 12: sin hijos -> es hoja" << endl;
  cout << "  - Nodo 18: sin hijos -> es hoja" << endl;
  cout << "  - Nodo 25: sin hijos -> es hoja\n" << endl;

  cout << "--- RECORRIDOS DEL ARBOL ---" << endl;
  cout << "Preorden:  "; preorden(raiz);
  cout << "\nInorden:   "; inorden(raiz);
  cout << "\nPostorden: "; postorden(raiz);
  cout << "\nBFS:       "; bfs(raiz);

  cout << "\n\n--- RESULTADO ---" << endl;
  cout << "Total de hojas en el arbol: " << contarHojas(raiz) << endl;
  cout << "\n" << endl;
}

// ==================== EJERCICIO 5 ====================
void ejercicio5() {
  cout << "\n========================================" << endl;
  cout << "              EJERCICIO 5                " << endl;
  cout << "  Caso aplicado: Sistema de Gimnasio     " << endl;
  cout << "========================================\n" << endl;

  // Construir el arbol del Sistema de Gimnasio
  NodoSistema *sistema = new NodoSistema(1, "Sistema Gimnasio");
  sistema->izquierda = new NodoSistema(2, "Gestion Clientes");
  sistema->derecha = new NodoSistema(3, "Gestion Pagos");
  sistema->izquierda->izquierda = new NodoSistema(4, "Registrar Cliente");
  sistema->izquierda->derecha = new NodoSistema(5, "Actualizar Cliente");
  sistema->derecha->izquierda = new NodoSistema(6, "Procesar Pago");
  sistema->derecha->derecha = new NodoSistema(7, "Reportar Pagos");

  cout << "ESTRUCTURA DEL SISTEMA DE GIMNASIO:\n" << endl;
  cout << "                  1:Sistema Gimnasio (RAIZ)" << endl;
  cout << "                /                      \\" << endl;
  cout << "         2:Gestion Clientes          3:Gestion Pagos" << endl;
  cout << "            /          \\               /         \\" << endl;
  cout << "      4:Registrar   5:Actualizar   6:Procesar   7:Reportar" << endl;
  cout << "       (Hoja)         (Hoja)         (Hoja)       (Hoja)\n" << endl;

  cout << "--- RECORRIDOS DEL SISTEMA ---" << endl;

  cout << "\n> Preorden (Menu principal -> submenus):" << endl;
  cout << "   ";
  preordenSistema(sistema);

  cout << "\n\n> Inorden (Modulos ordenados):" << endl;
  cout << "   ";
  inordenSistema(sistema);

  cout << "\n\n> Postorden (Hojas antes que padres):" << endl;
  cout << "   ";
  postordenSistema(sistema);

  cout << "\n\n> BFS (Nivel por nivel):" << endl;
  cout << "   ";
  bfsSistema(sistema);

  cout << "\n\n--- RESPUESTAS DEL EJERCICIO 5 ---\n" << endl;

  cout << "+---------------------------------------------------------------+" << endl;
  cout << "| Pregunta 1: Que recorrido usar para mostrar el menu principal? |" << endl;
  cout << "+---------------------------------------------------------------+" << endl;
  cout << "| RESPUESTA: PREORDEN                                           |" << endl;
  cout << "|                                                               |" << endl;
  cout << "| JUSTIFICACION:                                                |" << endl;
  cout << "| Preorden visita la raiz (Sistema Gimnasio) antes que los      |" << endl;
  cout << "| submenus (Clientes y Pagos). Esto permite mostrar primero     |" << endl;
  cout << "| la opcion principal y luego las opciones secundarias.         |" << endl;
  cout << "+---------------------------------------------------------------+\n" << endl;

  cout << "+---------------------------------------------------------------+" << endl;
  cout << "| Pregunta 2: Que recorrido usar para procesar primero los      |" << endl;
  cout << "|             modulos internos?                                 |" << endl;
  cout << "+---------------------------------------------------------------+" << endl;
  cout << "| RESPUESTA: POSTORDEN                                          |" << endl;
  cout << "|                                                               |" << endl;
  cout << "| JUSTIFICACION:                                                |" << endl;
  cout << "| Postorden procesa las hojas (Registrar, Actualizar, Procesar, |" << endl;
  cout << "| Reportar) antes que sus nodos padres (Clientes y Pagos).      |" << endl;
  cout << "| Util para liberar recursos o ejecutar operaciones internas.   |" << endl;
  cout << "+---------------------------------------------------------------+\n" << endl;

  cout << "+---------------------------------------------------------------+" << endl;
  cout << "| Pregunta 3: Que recorrido usar para mostrar modulos nivel por |" << endl;
  cout << "|             nivel?                                            |" << endl;
  cout << "+---------------------------------------------------------------+" << endl;
  cout << "| RESPUESTA: BFS (Breadth First Search)                         |" << endl;
  cout << "|                                                               |" << endl;
  cout << "| JUSTIFICACION:                                                |" << endl;
  cout << "| BFS muestra nivel 1 (Sistema Gimnasio), luego nivel 2         |" << endl;
  cout << "| (Gestion Clientes, Gestion Pagos), luego nivel 3              |" << endl;
  cout << "| (Registrar, Actualizar, Procesar, Reportar). Ideal para       |" << endl;
  cout << "| dashboards o menus de navegacion.                             |" << endl;
  cout << "+---------------------------------------------------------------+\n" << endl;
}

// ==================== MAIN PRINCIPAL ====================
int main() {
  cout << "\n+==============================================================+" << endl;
  cout << "|                                                              |" << endl;
  cout << "|     RECORRIDOS DE ARBOLES BINARIOS - ESTRUCTURA DE DATOS     |" << endl;
  cout << "|     Universidad Tecnica de Ambato                            |" << endl;
  cout << "|     Ingenieria de Software - Tercero B                       |" << endl;
  cout << "|                                                              |" << endl;
  cout << "|     INTEGRANTES:                                             |" << endl;
  cout << "|     [Nombres de los integrantes del grupo]                   |" << endl;
  cout << "|                                                              |" << endl;
  cout << "+==============================================================+" << endl;

  ejercicio1();
  cout << "\n==============================================================\n" << endl;
  ejercicio2();
  cout << "\n==============================================================\n" << endl;
  ejercicio3();
  cout << "\n==============================================================\n" << endl;
  ejercicio4();
  cout << "\n==============================================================\n" << endl;
  ejercicio5();

  cout << "\n+==============================================================+" << endl;
  cout << "|                     FIN DEL PROGRAMA                         |" << endl;
  cout << "+==============================================================+" << endl;

  return 0;
}
