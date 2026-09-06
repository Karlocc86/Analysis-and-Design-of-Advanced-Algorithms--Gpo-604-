#include "Dijkstra.h"
#include <cassert>
#include <stdexcept>

int main()
{
    MyGraph grafo(false);

    grafo.agregarArista("A", "B", 10);
    grafo.agregarArista("A", "C", 2);
    grafo.agregarArista("C", "D", 3);
    grafo.agregarArista("D", "B", 1);

    auto resultado = Dijkstra::resolver(grafo, "A");

    assert(resultado.distancias.at("B") == 6);

    const auto ruta = resultado.trayecto("B");
    assert((ruta == std::vector<std::string>{"A", "C", "D", "B"}));

    grafo.agregarVertice("Isla");
    assert(resultado.trayecto("Isla").empty());

    bool lanzoExcepcion = false;

    try
    {
        grafo.agregarArista("A", "X", -5);
    }
    catch (const std::invalid_argument &)
    {
        lanzoExcepcion = true;
    }

    assert(lanzoExcepcion);
    return 0;
}