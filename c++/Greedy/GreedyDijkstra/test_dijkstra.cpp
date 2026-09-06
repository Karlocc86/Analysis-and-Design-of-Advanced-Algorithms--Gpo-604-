#include "Dijkstra.h"
#include <cassert>
#include <stdexcept>
#include <string>
#include <vector>

int main()
{
    MyGraph grafo(false);

    grafo.agregarArista("A", "B", 10);
    grafo.agregarArista("A", "C", 2);
    grafo.agregarArista("C", "D", 3);
    grafo.agregarArista("D", "B", 1);
    grafo.agregarVertice("Isla");

    auto resultado = Dijkstra::resolver(grafo, "A");

    assert(resultado.distancias.at("B") == 6);

    const auto ruta = resultado.trayecto("B");
    assert((ruta == std::vector<std::string>{"A", "C", "D", "B"}));

    assert(resultado.distancias.at("A") == 0);
    assert((resultado.trayecto("A") == std::vector<std::string>{"A"}));
    assert(resultado.distancias.at("Isla") == INF);
    assert(resultado.trayecto("Isla").empty());

    MyGraph grafoDirigido(true);
    grafoDirigido.agregarArista("Inicio", "Medio", 5);
    grafoDirigido.agregarArista("Medio", "Fin", 4);

    auto resultadoDirigido = Dijkstra::resolver(grafoDirigido, "Fin");
    assert(resultadoDirigido.distancias.at("Inicio") == INF);
    assert(resultadoDirigido.trayecto("Inicio").empty());

    MyGraph caminosEmpatados(true);
    caminosEmpatados.agregarArista("A", "B", 2);
    caminosEmpatados.agregarArista("B", "D", 3);
    caminosEmpatados.agregarArista("A", "C", 3);
    caminosEmpatados.agregarArista("C", "D", 2);

    auto resultadoEmpatado = Dijkstra::resolver(caminosEmpatados, "A");
    assert(resultadoEmpatado.distancias.at("D") == 5);
    assert(!resultadoEmpatado.trayecto("D").empty());

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

    lanzoExcepcion = false;

    try
    {
        Dijkstra::resolver(grafo, "Fantasma");
    }
    catch (const std::invalid_argument &)
    {
        lanzoExcepcion = true;
    }

    assert(lanzoExcepcion);
    return 0;
}