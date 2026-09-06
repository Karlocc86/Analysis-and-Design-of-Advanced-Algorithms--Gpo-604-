#include <iostream>
#include <vector>
#include <string>
#include "MyGraph.h"
#include "Dijkstra.h"

//Main hecho por IA para probar lo que hice

// Función auxiliar para imprimir el vector de trayecto con flechas
void imprimirRuta(const std::vector<std::string>& ruta) {
    if (ruta.empty()) {
        std::cout << "[Sin ruta disponible]\n";
        return;
    }

    for (size_t i = 0; i < ruta.size(); ++i) {
        std::cout << ruta[i];
        if (i + 1 < ruta.size()) {
            std::cout << " -> ";
        }
    }
    std::cout << "\n";
}

int main() {
    std::cout << "====================================================\n";
    std::cout << " CASO 1: Grafo No Dirigido (Eleccion por costo)\n";
    std::cout << "====================================================\n";
    /*
             (10)
        A ------------ B
        |              |
     (2)|              |(1)
        |     (3)      |
        C ------------ D
    */
    MyGraph grafoND(false);
    grafoND.agregarArista("A", "B", 10);
    grafoND.agregarArista("A", "C", 2);
    grafoND.agregarArista("C", "D", 3);
    grafoND.agregarArista("D", "B", 1);

    // Ruta esperada A -> B:
    // Directa A -> B cuesta 10
    // Vía C y D: A -> C -> D -> B cuesta (2 + 3 + 1 = 6) -> Mas optima
    auto resND = Dijkstra::resolver(grafoND, "A");

    std::cout << "Distancia A -> B: " << resND.distancias.at("B") << " (Esperado: 6)\n";
    std::cout << "Camino A -> B:    ";
    imprimirRuta(resND.trayecto("B"));

    std::cout << "\n====================================================\n";
    std::cout << " CASO 2: Grafo Dirigido (Sentido unico)\n";
    std::cout << "====================================================\n";
    /*
        Inicio ----(5)---> Medio ----(4)---> Fin
    */
    MyGraph grafoD(true);
    grafoD.agregarArista("Inicio", "Medio", 5);
    grafoD.agregarArista("Medio", "Fin", 4);

    auto resD = Dijkstra::resolver(grafoD, "Inicio");
    std::cout << "Distancia Inicio -> Fin: " << resD.distancias.at("Fin") << " (Esperado: 9)\n";
    std::cout << "Camino Inicio -> Fin:    ";
    imprimirRuta(resD.trayecto("Fin"));

    // Desde Fin no se puede volver a Inicio
    auto resReversa = Dijkstra::resolver(grafoD, "Fin");
    std::cout << "Distancia Fin -> Inicio: "
              << (resReversa.distancias.at("Inicio") == INF ? "INF" : std::to_string(resReversa.distancias.at("Inicio")))
              << " (Esperado: INF)\n";
    std::cout << "Camino Fin -> Inicio:    ";
    imprimirRuta(resReversa.trayecto("Inicio"));

    std::cout << "\n====================================================\n";
    std::cout << " CASO 3: Nodo Aislado / Inalcanzable\n";
    std::cout << "====================================================\n";
    grafoND.agregarVertice("Isla");

    auto resIsla = Dijkstra::resolver(grafoND, "A");
    std::cout << "Distancia A -> Isla: "
              << (resIsla.distancias.at("Isla") == INF ? "INF" : "Conectado")
              << " (Esperado: INF)\n";
    std::cout << "Camino A -> Isla:    ";
    imprimirRuta(resIsla.trayecto("Isla"));

    std::cout << "\n====================================================\n";
    std::cout << " CASO 4: Manejo de Errores y Excepciones\n";
    std::cout << "====================================================\n";
    try {
        // Intentar agregar peso negativo
        grafoND.agregarArista("A", "C", -3);
    } catch (const std::invalid_argument& e) {
        std::cout << "[Atrapado] Error de arista: " << e.what() << "\n";
    }

    try {
        // Intentar resolver desde un nodo que no existe en el grafo
        Dijkstra::resolver(grafoND, "Fantasma");
    } catch (const std::invalid_argument& e) {
        std::cout << "[Atrapado] Error de origen: " << e.what() << "\n";
    }

    return 0;
}