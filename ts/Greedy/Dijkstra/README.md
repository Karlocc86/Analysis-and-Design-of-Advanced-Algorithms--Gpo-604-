# Dijkstra en TypeScript

Implementacion del algoritmo de Dijkstra para encontrar las rutas mas cortas desde un vertice origen en un grafo ponderado.

Esta version reproduce la implementacion de C++ usando clases de TypeScript, `Map` para representar la lista de adyacencia y una cola de prioridad basada en un min-heap.

## Contenido

El directorio contiene:

- `MyGraph.ts`: representa el grafo y sus aristas.
- `minPriorityQueue.ts`: implementa una cola de prioridad generica mediante un min-heap.
- `Dijkstra.ts`: contiene el algoritmo y la reconstruccion de rutas.

> **Nota sobre el nombre del archivo:** actualmente el archivo del grafo se llama `MyGraph..ts`, con dos puntos antes de `ts`. Por eso `Dijkstra.ts` lo importa como `./MyGraph.`. Si se cambia el nombre, tambien debe actualizarse ese import.

## Descripcion

El modulo expone las siguientes abstracciones:

### `Arista`

```typescript
interface Arista {
  destino: string;
  peso: number;
}
```

Representa una conexion entre dos vertices. `destino` identifica el vertice vecino y `peso` representa el costo de recorrer la arista.

### `MyGraph`

Representa un grafo mediante una lista de adyacencia:

```typescript
const grafo = new MyGraph(false);
```

El constructor recibe un booleano opcional:

- `false` (valor por defecto): el grafo es no dirigido.
- `true`: el grafo es dirigido o unidireccional.

Sus operaciones principales son:

- `agregarVertice(nodo)`: agrega un vertice si aun no existe.
- `agregarArista(origen, destino, peso)`: agrega una arista y crea los vertices si es necesario.
- `tieneVertice(nodo)`: indica si el vertice existe.
- `getVecinos(nodo)`: devuelve las aristas salientes del vertice.
- `getVertices()`: devuelve un iterador con todos los vertices.

### `MinPriorityQueue<T>`

Es una cola de prioridad generica implementada con un arreglo que mantiene la propiedad de min-heap. El elemento con menor prioridad siempre se extrae primero.

```typescript
const cola = new MinPriorityQueue<string>();

cola.push(10, "B");
cola.push(2, "C");

const siguiente = cola.pop(); // [2, "C"]
```

La clase ofrece:

- `push(prioridad, elemento)`: inserta un elemento y ejecuta `bubbleUp`.
- `pop()`: elimina y devuelve `[prioridad, elemento]`, o `undefined` si la cola esta vacia.
- `length`: cantidad actual de elementos.
- `isEmpty`: indica si la cola esta vacia.

### `Dijkstra.resolver`

Calcula las distancias minimas desde un origen:

```typescript
const resultado = Dijkstra.resolver(grafo, "A");
```

Devuelve un `ResultadoDijkstra` con:

- `distancias`: `ReadonlyMap<string, number>` con la distancia minima a cada vertice.
- `migajasDePan`: mapa de predecesores usado para reconstruir las rutas.
- `trayecto(destino)`: devuelve la ruta como arreglo de vertices.

## Restricciones

Dijkstra solo funciona correctamente con pesos no negativos. `MyGraph.agregarArista` lanza un error si recibe un peso menor que cero.

Tambien se lanza un error si se intenta ejecutar el algoritmo desde un vertice que no existe:

```typescript
Dijkstra.resolver(grafo, "NoExiste");
// Error: El nodo origen: NoExiste no existe
```

Los vertices que no pueden alcanzarse conservan la distancia `Infinity`. Para ellos, `trayecto(destino)` devuelve un arreglo vacio.

## Ejemplo completo

```typescript
import { MyGraph } from "./MyGraph.";
import { Dijkstra } from "./Dijkstra";

const grafo = new MyGraph(false);

grafo.agregarArista("A", "B", 10);
grafo.agregarArista("A", "C", 2);
grafo.agregarArista("C", "D", 3);
grafo.agregarArista("D", "B", 1);

const resultado = Dijkstra.resolver(grafo, "A");

console.log(resultado.distancias.get("B"));
// 6

console.log(resultado.trayecto("B"));
// ["A", "C", "D", "B"]
```

La ruta indirecta es mas barata que la ruta directa:

```text
A -> B       costo 10
A -> C -> D -> B   costo 2 + 3 + 1 = 6
```

## Grafos dirigidos

Para crear un grafo dirigido, se utiliza `true`:

```typescript
const grafo = new MyGraph(true);

grafo.agregarArista("Inicio", "Medio", 5);
grafo.agregarArista("Medio", "Fin", 4);

const resultado = Dijkstra.resolver(grafo, "Inicio");

console.log(resultado.distancias.get("Fin"));
// 9

console.log(resultado.trayecto("Fin"));
// ["Inicio", "Medio", "Fin"]
```

En este caso no se crean automaticamente las aristas inversas. Por eso la ruta desde `Fin` hacia `Inicio` es inalcanzable:

```typescript
const reversa = Dijkstra.resolver(grafo, "Fin");

console.log(reversa.distancias.get("Inicio"));
// Infinity

console.log(reversa.trayecto("Inicio"));
// []
```

## Como funciona el algoritmo

1. Se inicializa la distancia de todos los vertices con `Infinity`.
2. La distancia del origen se establece en `0`.
3. El origen se inserta en la cola de prioridad.
4. Se extrae el vertice con menor distancia conocida.
5. Se revisan sus vecinos y se intenta mejorar la distancia de cada uno.
6. Cuando se encuentra una distancia mejor, se actualizan la distancia y el predecesor, y se inserta una nueva entrada en la cola.
7. Las entradas antiguas de la cola se descartan mediante eliminacion perezosa.
8. El proceso termina cuando la cola queda vacia.

La eliminacion perezosa significa que no se modifica una entrada existente dentro del heap. En su lugar, se inserta la nueva distancia y, al extraer una entrada obsoleta, se ignora:

```typescript
if (distanciaActual > (distancias.get(u) ?? Infinity)) {
  continue;
}
```

## Reconstruccion de rutas

`ResultadoDijkstra` guarda el predecesor de cada vertice en `migajasDePan`. Por ejemplo:

```text
migajasDePan["C"] = "A"
migajasDePan["D"] = "C"
migajasDePan["B"] = "D"
```

Para reconstruir `B`, el algoritmo recorre hacia atras:

```text
B -> D -> C -> A
```

Finalmente invierte el arreglo y devuelve:

```text
A -> C -> D -> B
```

Si el destino es el mismo origen, la ruta contiene solamente el origen:

```typescript
const resultado = Dijkstra.resolver(grafo, "A");
console.log(resultado.trayecto("A"));
// ["A"]
```

## Complejidad

La implementacion utiliza un min-heap y eliminacion perezosa para manejar prioridades antiguas.

| Metrica | Complejidad        |
| :------ | :----------------- |
| Tiempo  | `O((V + E) log V)` |
| Espacio | `O(V + E)`         |

Donde:

- `V` es el numero de vertices.
- `E` es el numero de aristas.

En un grafo no dirigido, cada arista agregada se almacena en las dos listas de adyacencia correspondientes.

## Requisitos

- Node.js instalado.
- Dependencias instaladas desde el directorio `ts` mediante `npm install`.

La configuracion de TypeScript se encuentra en `ts/tsconfig.json` y el script de pruebas en `ts/package.json`.

Para instalar las dependencias:

```powershell
cd ts
npm install
```

Para verificar el archivo principal con TypeScript:

```powershell
npx tsc --noEmit --strict Greedy/Dijkstra/Dijkstra.ts
```

Tambien se pueden verificar todos los archivos incluidos en la configuracion:

```powershell
npx tsc -p tsconfig.json --noEmit
```

## Pruebas automatizadas

El archivo `test_dijkstra.ts` contiene pruebas para:

- Extraccion del min-heap en orden creciente.
- Cola vacia, `length` e `isEmpty`.
- Grafos dirigidos y no dirigidos.
- Rechazo de pesos negativos.
- Rechazo de vertices inexistentes.
- Ruta mas corta frente a una ruta directa mas cara.
- Ruta desde el origen hacia si mismo.
- Vertices inalcanzables.
- Dos rutas con el mismo costo.

Desde la carpeta `ts`, ejecuta:

```powershell
npm run test:dijkstra
```

El comando compila los archivos con `tsconfig.json` y ejecuta el resultado con Node.js. Una ejecucion correcta muestra:

```text
Todas las pruebas de Dijkstra pasaron correctamente.
```

## Pruebas manuales recomendadas

Antes de considerar terminada una modificacion, conviene probar estos casos:

- Ruta directa y ruta alternativa mas barata.
- Origen igual al destino.
- Vertice inalcanzable.
- Grafo dirigido.
- Grafo no dirigido.
- Varias rutas con el mismo costo.
- Peso cero.
- Peso negativo.
- Origen inexistente.
- Cola de prioridad vacia.
- Extraccion de varios elementos del min-heap en orden creciente.

Una comprobacion sencilla del min-heap es:

```typescript
const cola = new MinPriorityQueue<string>();

cola.push(5, "cinco");
cola.push(1, "uno");
cola.push(3, "tres");

console.log(cola.pop()); // [1, "uno"]
console.log(cola.pop()); // [3, "tres"]
console.log(cola.pop()); // [5, "cinco"]
console.log(cola.pop()); // undefined
```

## Diferencias con la version de C++

- `std::map` y otros contenedores se sustituyen por `Map`.
- `std::priority_queue` se sustituye por `MinPriorityQueue`.
- `INF` se representa con `Infinity`.
- `std::vector<string>` se representa con `string[]`.
- `ReadonlyMap` evita que el consumidor reasigne directamente las colecciones expuestas por el resultado.
- El resultado vacio de una ruta se representa con `[]`.
