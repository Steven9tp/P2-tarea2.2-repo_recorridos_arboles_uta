import java.util.*;

// Nodo para los ejercicios 1-4
class Nodo {
    int dato;
    Nodo izquierda;
    Nodo derecha;

    Nodo(int valor) {
        this.dato = valor;
        this.izquierda = null;
        this.derecha = null;
    }
}

// Nodo específico para el Ejercicio 5 (Caso aplicado)
class NodoSistema {
    int id;
    String nombre;
    NodoSistema izquierda;
    NodoSistema derecha;

    NodoSistema(int _id, String _nombre) {
        this.id = _id;
        this.nombre = _nombre;
        this.izquierda = null;
        this.derecha = null;
    }
}

public class Main {

    // ==================== FUNCIONES COMUNES (Ejercicios 1-4) ====================
    static void preorden(Nodo raiz) {
        if (raiz == null) return;
        System.out.print(raiz.dato + " ");
        preorden(raiz.izquierda);
        preorden(raiz.derecha);
    }

    static void inorden(Nodo raiz) {
        if (raiz == null) return;
        inorden(raiz.izquierda);
        System.out.print(raiz.dato + " ");
        inorden(raiz.derecha);
    }

    static void postorden(Nodo raiz) {
        if (raiz == null) return;
        postorden(raiz.izquierda);
        postorden(raiz.derecha);
        System.out.print(raiz.dato + " ");
    }

    static void bfs(Nodo raiz) {
        if (raiz == null) return;
        Queue<Nodo> cola = new LinkedList<>();
        cola.add(raiz);
        while (!cola.isEmpty()) {
            Nodo actual = cola.poll();
            System.out.print(actual.dato + " ");
            if (actual.izquierda != null) cola.add(actual.izquierda);
            if (actual.derecha != null) cola.add(actual.derecha);
        }
    }

    // ==================== FUNCIONES PARA RECORRIDOS DEL SISTEMA (Ejercicio 5) ====================
    static void preordenSistema(NodoSistema raiz) {
        if (raiz == null) return;
        System.out.print(raiz.id + ":" + raiz.nombre + "  ");
        preordenSistema(raiz.izquierda);
        preordenSistema(raiz.derecha);
    }

    static void inordenSistema(NodoSistema raiz) {
        if (raiz == null) return;
        inordenSistema(raiz.izquierda);
        System.out.print(raiz.id + ":" + raiz.nombre + "  ");
        inordenSistema(raiz.derecha);
    }

    static void postordenSistema(NodoSistema raiz) {
        if (raiz == null) return;
        postordenSistema(raiz.izquierda);
        postordenSistema(raiz.derecha);
        System.out.print(raiz.id + ":" + raiz.nombre + "  ");
    }

    static void bfsSistema(NodoSistema raiz) {
        if (raiz == null) return;
        Queue<NodoSistema> cola = new LinkedList<>();
        cola.add(raiz);
        while (!cola.isEmpty()) {
            NodoSistema actual = cola.poll();
            System.out.print(actual.id + ":" + actual.nombre + "  ");
            if (actual.izquierda != null) cola.add(actual.izquierda);
            if (actual.derecha != null) cola.add(actual.derecha);
        }
    }

    // ==================== FUNCIONES PARA EJERCICIOS 3 Y 4 ====================
    static int contarNodos(Nodo raiz) {
        if (raiz == null) return 0;
        return 1 + contarNodos(raiz.izquierda) + contarNodos(raiz.derecha);
    }

    static int contarHojas(Nodo raiz) {
        if (raiz == null) return 0;
        if (raiz.izquierda == null && raiz.derecha == null) return 1;
        return contarHojas(raiz.izquierda) + contarHojas(raiz.derecha);
    }

    // ==================== EJERCICIO 1 ====================
    static void ejercicio1() {
        System.out.println("\n========================================");
        System.out.println("              EJERCICIO 1                ");
        System.out.println("    Arbol original (10,5,15,2,7,12,20)   ");
        System.out.println("========================================\n");

        Nodo raiz = new Nodo(10);
        raiz.izquierda = new Nodo(5);
        raiz.derecha = new Nodo(15);
        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha = new Nodo(7);
        raiz.derecha.izquierda = new Nodo(12);
        raiz.derecha.derecha = new Nodo(20);

        System.out.println("Estructura del arbol:");
        System.out.println("        10");
        System.out.println("       /  \\");
        System.out.println("      5    15");
        System.out.println("     / \\   / \\");
        System.out.println("    2   7 12 20\n");

        System.out.println("--- RECORRIDOS ---");
        System.out.print("Preorden:  "); preorden(raiz);
        System.out.print("\nInorden:   "); inorden(raiz);
        System.out.print("\nPostorden: "); postorden(raiz);
        System.out.print("\nBFS:       "); bfs(raiz);
        System.out.println("\n");
    }

    // ==================== EJERCICIO 2 ====================
    static void ejercicio2() {
        System.out.println("\n========================================");
        System.out.println("              EJERCICIO 2                ");
        System.out.println("  Arbol modificado (agregando 1,3,18,25) ");
        System.out.println("========================================\n");

        Nodo raiz = new Nodo(10);
        raiz.izquierda = new Nodo(5);
        raiz.derecha = new Nodo(15);
        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha = new Nodo(7);
        raiz.derecha.izquierda = new Nodo(12);
        raiz.derecha.derecha = new Nodo(20);

        raiz.izquierda.izquierda.izquierda = new Nodo(1);
        raiz.izquierda.izquierda.derecha = new Nodo(3);
        raiz.derecha.derecha.izquierda = new Nodo(18);
        raiz.derecha.derecha.derecha = new Nodo(25);

        System.out.println("Estructura del arbol modificado:");
        System.out.println("          10");
        System.out.println("       /     \\");
        System.out.println("      5       15");
        System.out.println("     / \\     / \\");
        System.out.println("    2   7   12 20");
        System.out.println("   / \\         / \\");
        System.out.println("  1   3       18 25\n");

        System.out.println("--- RECORRIDOS DEL ARBOL MODIFICADO ---");
        System.out.print("Preorden:  "); preorden(raiz);
        System.out.print("\nInorden:   "); inorden(raiz);
        System.out.print("\nPostorden: "); postorden(raiz);
        System.out.print("\nBFS:       "); bfs(raiz);
        System.out.println("\n");
    }

    // ==================== EJERCICIO 3 ====================
    static void ejercicio3() {
        System.out.println("\n========================================");
        System.out.println("              EJERCICIO 3                ");
        System.out.println("       Funcion para contar nodos         ");
        System.out.println("========================================\n");

        Nodo raiz = new Nodo(10);
        raiz.izquierda = new Nodo(5);
        raiz.derecha = new Nodo(15);
        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha = new Nodo(7);
        raiz.derecha.izquierda = new Nodo(12);
        raiz.derecha.derecha = new Nodo(20);
        raiz.izquierda.izquierda.izquierda = new Nodo(1);
        raiz.izquierda.izquierda.derecha = new Nodo(3);
        raiz.derecha.derecha.izquierda = new Nodo(18);
        raiz.derecha.derecha.derecha = new Nodo(25);

        System.out.println("Codigo de la funcion:");
        System.out.println("+---------------------------------------------------+");
        System.out.println("| static int contarNodos(Nodo raiz) {               |");
        System.out.println("|     if (raiz == null) return 0;                   |");
        System.out.println("|     return 1 + contarNodos(raiz.izquierda) +      |");
        System.out.println("|                contarNodos(raiz.derecha);         |");
        System.out.println("| }                                                |");
        System.out.println("+---------------------------------------------------+\n");

        System.out.println("--- RECORRIDOS DEL ARBOL ---");
        System.out.print("Preorden:  "); preorden(raiz);
        System.out.print("\nInorden:   "); inorden(raiz);
        System.out.print("\nPostorden: "); postorden(raiz);
        System.out.print("\nBFS:       "); bfs(raiz);

        System.out.println("\n\n--- RESULTADO ---");
        System.out.println("Total de nodos en el arbol: " + contarNodos(raiz));
        System.out.println("\n");
    }

    // ==================== EJERCICIO 4 ====================
    static void ejercicio4() {
        System.out.println("\n========================================");
        System.out.println("              EJERCICIO 4                ");
        System.out.println("       Funcion para contar hojas         ");
        System.out.println("========================================\n");

        Nodo raiz = new Nodo(10);
        raiz.izquierda = new Nodo(5);
        raiz.derecha = new Nodo(15);
        raiz.izquierda.izquierda = new Nodo(2);
        raiz.izquierda.derecha = new Nodo(7);
        raiz.derecha.izquierda = new Nodo(12);
        raiz.derecha.derecha = new Nodo(20);
        raiz.izquierda.izquierda.izquierda = new Nodo(1);
        raiz.izquierda.izquierda.derecha = new Nodo(3);
        raiz.derecha.derecha.izquierda = new Nodo(18);
        raiz.derecha.derecha.derecha = new Nodo(25);

        System.out.println("Codigo de la funcion:");
        System.out.println("+---------------------------------------------------+");
        System.out.println("| static int contarHojas(Nodo raiz) {               |");
        System.out.println("|     if (raiz == null) return 0;                   |");
        System.out.println("|     if (raiz.izquierda == null &&                 |");
        System.out.println("|         raiz.derecha == null) return 1;           |");
        System.out.println("|     return contarHojas(raiz.izquierda) +          |");
        System.out.println("|            contarHojas(raiz.derecha);             |");
        System.out.println("| }                                                |");
        System.out.println("+---------------------------------------------------+\n");

        System.out.println("Identificacion de hojas (nodos sin hijos):");
        System.out.println("  - Nodo 1: sin hijos -> es hoja");
        System.out.println("  - Nodo 3: sin hijos -> es hoja");
        System.out.println("  - Nodo 7: sin hijos -> es hoja");
        System.out.println("  - Nodo 12: sin hijos -> es hoja");
        System.out.println("  - Nodo 18: sin hijos -> es hoja");
        System.out.println("  - Nodo 25: sin hijos -> es hoja\n");

        System.out.println("--- RECORRIDOS DEL ARBOL ---");
        System.out.print("Preorden:  "); preorden(raiz);
        System.out.print("\nInorden:   "); inorden(raiz);
        System.out.print("\nPostorden: "); postorden(raiz);
        System.out.print("\nBFS:       "); bfs(raiz);

        System.out.println("\n\n--- RESULTADO ---");
        System.out.println("Total de hojas en el arbol: " + contarHojas(raiz));
        System.out.println("\n");
    }

    // ==================== EJERCICIO 5 ====================
    static void ejercicio5() {
        System.out.println("\n========================================");
        System.out.println("              EJERCICIO 5                ");
        System.out.println("  Caso aplicado: Sistema de Gimnasio     ");
        System.out.println("========================================\n");

        // Construir el arbol del Sistema de Gimnasio
        NodoSistema sistema = new NodoSistema(1, "Sistema Gimnasio");
        sistema.izquierda = new NodoSistema(2, "Gestion Clientes");
        sistema.derecha = new NodoSistema(3, "Gestion Pagos");
        sistema.izquierda.izquierda = new NodoSistema(4, "Registrar Cliente");
        sistema.izquierda.derecha = new NodoSistema(5, "Actualizar Cliente");
        sistema.derecha.izquierda = new NodoSistema(6, "Procesar Pago");
        sistema.derecha.derecha = new NodoSistema(7, "Reportar Pagos");

        System.out.println("ESTRUCTURA DEL SISTEMA DE GIMNASIO:\n");
        System.out.println("                  1:Sistema Gimnasio (RAIZ)");
        System.out.println("                /                      \\");
        System.out.println("         2:Gestion Clientes          3:Gestion Pagos");
        System.out.println("            /          \\               /         \\");
        System.out.println("      4:Registrar   5:Actualizar   6:Procesar   7:Reportar");
        System.out.println("       (Hoja)         (Hoja)         (Hoja)       (Hoja)\n");

        System.out.println("--- RECORRIDOS DEL SISTEMA ---");

        System.out.println("\n> Preorden (Menu principal -> submenus):");
        System.out.print("   "); preordenSistema(sistema);

        System.out.println("\n\n> Inorden (Modulos ordenados):");
        System.out.print("   "); inordenSistema(sistema);

        System.out.println("\n\n> Postorden (Hojas antes que padres):");
        System.out.print("   "); postordenSistema(sistema);

        System.out.println("\n\n> BFS (Nivel por nivel):");
        System.out.print("   "); bfsSistema(sistema);

        System.out.println("\n\n--- RESPUESTAS DEL EJERCICIO 5 ---\n");

        System.out.println("+---------------------------------------------------------------+");
        System.out.println("| Pregunta 1: Que recorrido usar para mostrar el menu principal? |");
        System.out.println("+---------------------------------------------------------------+");
        System.out.println("| RESPUESTA: PREORDEN                                           |");
        System.out.println("|                                                               |");
        System.out.println("| JUSTIFICACION:                                                |");
        System.out.println("| Preorden visita la raiz (Sistema Gimnasio) antes que los      |");
        System.out.println("| submenus (Clientes y Pagos). Esto permite mostrar primero     |");
        System.out.println("| la opcion principal y luego las opciones secundarias.         |");
        System.out.println("+---------------------------------------------------------------+\n");

        System.out.println("+---------------------------------------------------------------+");
        System.out.println("| Pregunta 2: Que recorrido usar para procesar primero los      |");
        System.out.println("|             modulos internos?                                 |");
        System.out.println("+---------------------------------------------------------------+");
        System.out.println("| RESPUESTA: POSTORDEN                                          |");
        System.out.println("|                                                               |");
        System.out.println("| JUSTIFICACION:                                                |");
        System.out.println("| Postorden procesa las hojas (Registrar, Actualizar, Procesar, |");
        System.out.println("| Reportar) antes que sus nodos padres (Clientes y Pagos).      |");
        System.out.println("| Util para liberar recursos o ejecutar operaciones internas.   |");
        System.out.println("+---------------------------------------------------------------+\n");

        System.out.println("+---------------------------------------------------------------+");
        System.out.println("| Pregunta 3: Que recorrido usar para mostrar modulos nivel por |");
        System.out.println("|             nivel?                                            |");
        System.out.println("+---------------------------------------------------------------+");
        System.out.println("| RESPUESTA: BFS (Breadth First Search)                         |");
        System.out.println("|                                                               |");
        System.out.println("| JUSTIFICACION:                                                |");
        System.out.println("| BFS muestra nivel 1 (Sistema Gimnasio), luego nivel 2         |");
        System.out.println("| (Gestion Clientes, Gestion Pagos), luego nivel 3              |");
        System.out.println("| (Registrar, Actualizar, Procesar, Reportar). Ideal para       |");
        System.out.println("| dashboards o menus de navegacion.                             |");
        System.out.println("+---------------------------------------------------------------+\n");
    }

    // ==================== MAIN PRINCIPAL ====================
    public static void main(String[] args) {
        System.out.println("\n+==============================================================+");
        System.out.println("|                                                              |");
        System.out.println("|     RECORRIDOS DE ARBOLES BINARIOS - ESTRUCTURA DE DATOS     |");
        System.out.println("|     Universidad Tecnica de Ambato                            |");
        System.out.println("|     Ingenieria de Software - Tercero B                       |");
        System.out.println("|                                                              |");
        System.out.println("|     INTEGRANTES:                                             |");
        System.out.println("|     [Nombres de los integrantes del grupo]                   |");
        System.out.println("|                                                              |");
        System.out.println("+==============================================================+");

        ejercicio1();
        System.out.println("\n==============================================================\n");
        ejercicio2();
        System.out.println("\n==============================================================\n");
        ejercicio3();
        System.out.println("\n==============================================================\n");
        ejercicio4();
        System.out.println("\n==============================================================\n");
        ejercicio5();

        System.out.println("\n+==============================================================+");
        System.out.println("|                     FIN DEL PROGRAMA                         |");
        System.out.println("+==============================================================+");
    }
}