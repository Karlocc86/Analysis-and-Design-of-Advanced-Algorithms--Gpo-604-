//
// Created by sebas on 06/09/2026.
//

#include "MyGraph.h"
#include <stdexcept>

MyGraph::MyGraph(bool unidireccional) {
    esUnidireccional = unidireccional;
}

void MyGraph::agregarVertice(const std::string &nodo) {

    listaAdyacencia.try_emplace(nodo);

    // El try_emplace es nuevo para mi, es un metodo moderno de c++ 17
    // que como lo dice try y emplace, es intentar insertar el elemento
    // si la clave no existe, ahi si reserva memoria y crea el valor, si
    // existiera no hace nada ni pierde tiempo haciendo pasos innnecasarios
    // que no haran nada (construir el valor) porque seran descartados.
    // Tiene una funcion similar de lo que ya conozco que hubiera sido el
    // listaAdyacencia[nodo]; pero aparentemente tendria que usar iteradores
    // para saber si existe o no con lo del .find ==mp.end() o usar el .count()

}

void MyGraph::agregarArista(const std::string &origen, const std::string &destino, int peso) {

    if (peso < 0) {
        throw std::invalid_argument("En el dijkstra no se meten pesos negativos: " + std::to_string(peso));
    }

    agregarVertice(origen);
    agregarVertice(destino);

    listaAdyacencia[origen].emplace_back(destino, peso);

    // funcionaria tambien listaAdyacencia[origen].push_back( diferencia ->[Arista](destino, peso));
    // el beneficio de emplace_back aqui es q no tengo que instanciar un objeto arista temporal
    // para meterlo al hashmap, con emplace back me ahorro el instanciar el objeto y le paso
    // directamente los parametros y ya.

    if (!esUnidireccional) { //Si no es unidireccional le pongo una vertice de regreso destino -> origen
        listaAdyacencia[destino].emplace_back(origen, peso);
    }

}


bool MyGraph::getVertice(const std::string &nodo) const {
    return listaAdyacencia.find(nodo) != listaAdyacencia.end();
}

const std::vector<Arista> &MyGraph::getVecinos(const std::string &nodo) const {
    auto it = listaAdyacencia.find(nodo);
    if (it == listaAdyacencia.end()) {
        throw std::out_of_range("El vertice o nodo del que intentas buscar vecino no existe");
    }

    return it -> second; // retorna el valor ( [second] que es un iterador (un puntero por eso el ->) )
                         //  lo que seria el vector de Aritas o destinos
}

const std::unordered_map<std::string, std::vector<Arista> > MyGraph::getListaAdyacencia() const {
    return listaAdyacencia;
}
