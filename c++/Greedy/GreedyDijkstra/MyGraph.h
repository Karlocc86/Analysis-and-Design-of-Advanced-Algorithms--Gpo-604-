//
// Created by sebas on 06/09/2026.
//

#include <string>
#include <vector>
#include <unordered_map>

#ifndef ALGORITMOSAVANZADOS_MYGRAPH_H
#define ALGORITMOSAVANZADOS_MYGRAPH_H

struct Arista {

    std::string destino;
    int peso;
    Arista(const std::string& d, int p) : destino(d), peso(p) {}

};


class MyGraph {

private:
    std::unordered_map<std::string,std::vector<Arista>> listaAdyacencia;
    bool esUnidireccional;

public:

    explicit MyGraph(bool unidireccional = false); // Aparentemente en c++ es regla dorada : utilizar explicit
                                                   // cuando un constructor sera de un solo parametro, esto
                                                   // evita al compilador asumir cosas | reduce ambiguiedad y
                                                   // bloqueas por completo conversiones sin sentido.

    //funciones
    void agregarVertice(const std::string& nodo);
    void agregarArista(const std::string& origen , const std::string& destino, int peso);

    //getters
    bool getVertice(const std::string& nodo) const;
    const std::vector<Arista>& getVecinos(const std::string& nodo) const;
    const std::unordered_map<std::string , std::vector<Arista>> getListaAdyacencia() const;


};


#endif //ALGORITMOSAVANZADOS_MYGRAPH_H
