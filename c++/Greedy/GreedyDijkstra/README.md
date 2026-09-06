# Dijkstra en C++

Implementacion del algoritmo de Dijkstra para encontrar las rutas mas cortas
desde un vertice origen en un grafo ponderado.

## Descripcion

El modulo incluye:

- `MyGraph`: representa un grafo mediante una lista de adyacencia.
- `Arista`: almacena el vertice destino y el peso de una arista.
- `Dijkstra::resolver`: calcula las distancias minimas y los predecesores desde
  un vertice origen.
- `ResultadoDijkstra::trayecto`: reconstruye la ruta hacia un destino.

El grafo puede ser dirigido o no dirigido. Al crear `MyGraph`, el parametro
`true` indica que las aristas son unidireccionales; el valor por defecto es
`false`.

## Restricciones

Dijkstra requiere pesos no negativos. `agregarArista` lanza
`std::invalid_argument` si recibe un peso menor que cero. Tambien se lanza una
excepcion si se intenta resolver el algoritmo desde un vertice inexistente.

## Ejemplo de uso

```cpp
MyGraph grafo(false);
grafo.agregarArista("A", "B", 10);
grafo.agregarArista("A", "C", 2);
grafo.agregarArista("C", "D", 3);
grafo.agregarArista("D", "B", 1);

auto resultado = Dijkstra::resolver(grafo, "A");

// Distancia minima: 6
int distancia = resultado.distancias.at("B");

// Ruta: A -> C -> D -> B
std::vector<std::string> ruta = resultado.trayecto("B");
```

Si el destino no existe o es inalcanzable, `trayecto` devuelve un vector
vacio. Las distancias inalcanzables se almacenan como `INF`.

## Complejidad

La implementacion utiliza un `std::priority_queue` como min-heap y aplica
eliminacion perezosa para descartar entradas obsoletas.

| Metrica | Complejidad |
| :------ | :---------- |
| Tiempo  | `O((V + E) log V)` |
| Espacio | `O(V + E)` |

Donde `V` es el numero de vertices y `E` el numero de aristas.

## Requisitos

- Compilador compatible con C++17 o superior.
- CMake 4.2 o superior, si se utiliza la configuracion del proyecto.

## Ejecucion directa

Desde la raiz del repositorio:

```bash
g++ -std=c++17 \
  c++/Greedy/GreedyDijkstra/MyGraph.cpp \
  c++/Greedy/GreedyDijkstra/Dijkstra.cpp \
  c++/Greedy/GreedyDijkstra/main.cpp \
  -o greedyDijkstra
./greedyDijkstra
```

En Windows, el ejecutable generado puede ser `greedyDijkstra.exe`.

## Ejecucion con CMake

```bash
cmake -S . -B build
cmake --build build --target greedyDijkstra
```

El programa de ejemplo en `main.cpp` prueba grafos dirigidos y no dirigidos,
vertices aislados y el manejo de errores por pesos negativos u origen
inexistente.