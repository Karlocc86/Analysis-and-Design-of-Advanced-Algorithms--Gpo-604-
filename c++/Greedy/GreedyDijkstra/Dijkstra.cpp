//
// Created by sebas on 06/09/2026.
//

#include "Dijkstra.h"
#include <algorithm> // pal reverse
#include <stdexcept>
#include <queue>
#include <functional> // para greater de priority queue
#include <utility> // para poder usar pair en la etiqueta ELementPQ aunque parecia funcionar sin la lib

std::vector<std::string> ResultadoDijkstra::trayecto(const std::string& destino) const {
    auto it = distancias.find(destino);

    if (it == distancias.end() || it->second == INF) { //Si no existe el vertice y/o es inalcancable (inf).
        return {}; // No hay camino
    }

    std::vector<std::string> camino;
    std::string actual = destino;

    while (migajasDePan.find(actual) != migajasDePan.end()) {
        camino.push_back(actual);
        actual = migajasDePan.at(actual);

        // at funciona parecido a lo que usaria -> migajasDePan[actual]
        // o sea buscaria desde donde llego o el valor de la llave,
        // la diferencia de usar [] vs .at(), es que si no existiera "[actual]"
        // los [] crearian ese vertice vacio, .at() funciona como una excepcion
        // out_of_range (aparte de que es solo de lectura), no modificaria nada y checaria
        // si existe -> continuaria sanamente el programa | si no existiera -> no lo crea
        // de la nada.

        // .at() es solo lectura vs [] que no lo son
        // definimos la funcion como const asi que no se puede usar []
        // porque puede modificar ResultadoDijkstra

    }

    camino.push_back(actual);

    std::reverse(camino.begin(), camino.end());

    return camino;

}


ResultadoDijkstra Dijkstra::resolver(const MyGraph &grafo, const std::string &origen) {
    if (!grafo.getVertice(origen)) {
        throw std::invalid_argument("No existe el vertice origen: " + origen);
    }

    ResultadoDijkstra resultado;

    for (const auto& [nodo, _] : grafo.getListaAdyacencia()) {
        resultado.distancias[nodo] = INF;
    }

    resultado.distancias[origen] = 0;

    // Creamos un par: (distancia_acumulada, nombre_nodo)
    // using es para crear un alias/etiqueta para "std::pair<int, std::string>"
    // ayuda que no tenga que estar escribiendo siempre std::pair<int, std::string>

    using ElementoPQ = std::pair<int, std::string>;

    // Explicacion de todo lo de priority_queue que es la primera vez que la uso o eso recuerdo
    // Por defecto, std::priority_queue es un Max-Heap (saca el elemento más grande con .top()).
    // Para Dijkstra necesitamos un Min-Heap (que el camino más corto salga primero).
    //
    // std::priority_queue recibe 3 parámetros de plantilla: <Tipo, Contenedor, Comparador>
    // 1. ElementoPQ: Qué guardamos dentro del montículo.
    // 2. std::vector<ElementoPQ>: El contenedor subyacente donde se guardan los datos en memoria.
    //    (Es obligatorio escribirlo porque en C++ no puedes saltarte el 2do parámetro para configurar el 3ro).
    // 3. std::greater<ElementoPQ>: Cambia la regla de orden. Por defecto usa std::less (Max-Heap);
    //    con std::greater se convierte en Min-Heap.
    //
    // ¿Por qué funciona con pares sin código extra?
    // std::pair compara automáticamente su primer elemento (.first).
    // Al ser (distancia, nodo), compara distancias y coloca la menor arriba.
    std::priority_queue<ElementoPQ, std::vector<ElementoPQ>, std::greater<ElementoPQ>> pq;

    // emplace construye el std::pair(0, origen) in-place dentro de la cola sin copias temporales
    // asi igualito que con lo del hashmap del try_emplace, sin pasar el objeto solo los parametros.
    // Con el Push de toda la vida seria asi pq.push(std::make_pair(...)) con make_pair temporal como Arista(...)

    pq.emplace(0,origen);

    while (!pq.empty()) {

        // Sacamos distanciaActual con pq.top().fisrt
        // por lo consecuente sacamos el nombre del nodo actual con pq.top().second
        auto [distanciaActual, u] = pq.top();
        pq.pop();

        // ====================================================================
        // De la IA para el mundo
        // PODA (Lazy Deletion):
        // Como std::priority_queue no permite modificar elementos (decrease_key),
        // insertamos duplicados con distancias menores.
        // Si sacamos una distancia peor que la mejor registrada en el mapa,
        // significa que este elemento es un residuo obsoleto y lo ignoramos.
        // ====================================================================

        if (distanciaActual > resultado.distancias[u]) {
            continue;
        }

        // ====================================================================
        // RELAJACIÓN DE ARISTAS:
        // Exploramos todos los vecinos alcanzables directamente desde 'u'
        // ====================================================================

        for (const auto& arista : grafo.getVecinos(u)) {
            const std::string& v = arista.destino; //.destino viene del struct de Arista
            int peso = arista.peso;


            if (resultado.distancias[u] + peso < resultado.distancias[v]) {

                resultado.distancias[v] = resultado.distancias[u] + peso;
                resultado.migajasDePan[v] = u;
                pq.emplace(resultado.distancias[v], v);
            }
        }
    }

    return resultado;
}

