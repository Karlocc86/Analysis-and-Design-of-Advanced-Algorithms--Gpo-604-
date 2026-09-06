//
// Created by sebas on 06/09/2026.
//


#ifndef ALGORITMOSAVANZADOS_DIJKSTRA_H
#define ALGORITMOSAVANZADOS_DIJKSTRA_H
//Convenio siempre importa despues del #define o include guards.

#include "MyGraph.h"
#include <limits> // paraconstexpr
#include <string>
#include <vector> // lib principle: include what you see
#include <unordered_map>

constexpr int INF = std::numeric_limits<int>::max(); // version moderna y segura del INT_MAX

struct ResultadoDijkstra {
    std::unordered_map<std::string, int> distancias;
    std::unordered_map<std::string, std::string> migajasDePan;
    // Como un rastro de migajas de pan donde sabes desde iniciaste y llegaste, no guarda
    // toda la ruta, solo el destino anterior desde donde llego de la manera mas eficiente
    // ej. de B llegue desde A. Es el predecesor en palabras mas puntales.

    // V -> numero de vertices en el grafo
    // No se guardan las listas completos de predecesores sobre la marcha S(O(V^2)), porque
    // consumiria mucha memoria, por eso se guarda no mas el anterior como dije antes S(O(V))
    // ej. V = 100,000
    // Approach S(O(v)) -> serian 100,000 pares que serian algunos mb de ram
    // Aprroach S(O(v^2)) -> serian ((100,000)^2)/2 = 5,000,000,000 strings requiriendo mas de 40gb de RAM
    // mb vs 40-50gb de RAM | comparativa de costo exagerada

    std::vector<std::string> trayecto(const std::string& destino) const;

};

// Se pudo haber hecho todo dentro de Dijkstra como lo pense, pero la IA me recomendo hacerlo
// separado (struct & class) por las siguientes razones:

// ¿Por qué separar el struct Resultado de la clase/función en vez de meter todo junto?
//
// 1. Separación de responsabilidades (SRP):
//    El struct es un contenedor pasivo de datos (el "reporte"). La clase/función es la lógica
//    que los calcula. Mezclarlos ata el ciclo de vida del dato a la maquinaria que lo generó.
//
// 2. Limpieza de memoria (Stack vs Heap):
//    Estructuras pesadas auxiliares (como la std::priority_queue) se destruyen de la pila
//    en cuanto termina la función. Solo sobrevive en RAM el struct liviano con los resultados.
//
// 3. Función pura e inmutabilidad:
//    Al no tener estado interno, no hay riesgo de sobreescribir datos si calculas múltiples
//    rutas (ej. origen "A" y origen "B"). Es seguro para concurrencia (thread-safe) y
//    evita objetos zombi en memoria.

class Dijkstra {

    Dijkstra() = delete; //Clase de utilidad no tiene atributos miembro,
                         // no almacena variables internas y no guarda ningún estado.
                         // Solo contiene una función estática.

    // Una clase de utilidad (utility class) es una clase diseñada exclusivamente
    // para agrupar funciones o herramientas relacionadas, sin almacenar variables internas (no tiene estado)
    // y sin la intención de que se creen objetos a partir de ella.
public:
    static ResultadoDijkstra resolver(const MyGraph& grafo, const std::string& origen);


};


#endif //ALGORITMOSAVANZADOS_DIJKSTRA_H
