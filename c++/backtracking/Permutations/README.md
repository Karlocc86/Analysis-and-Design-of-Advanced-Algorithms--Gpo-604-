# Permutaciones (Backtracking) en C++

Implementacion del problema clasico de generar todas las permutaciones de un
arreglo de enteros usando backtracking.

## Objetivo

Dado un arreglo `arr` de `n` elementos distintos, encontrar todas las formas
posibles de ordenarlos, es decir, todas sus permutaciones.

## Algoritmo

`permutations(arr)` prepara el estado inicial y delega en `backtrack`:

- `path`: permutacion parcial que se esta construyendo.
- `seen`: vector de booleanos del mismo tamano que `arr`, indica si
  `arr[i]` ya forma parte de `path`.
- `solution`: acumula cada permutacion completa encontrada.

`backtrack(path, n, solution, seen, arr)` construye una permutacion
posicion por posicion:

1. Si `path.size() == n`, ya se eligieron los `n` elementos: se guarda una
   copia de `path` en `solution`.
2. Si no, para cada indice `i` de `arr`:
   - Si `seen[i]` es verdadero, `arr[i]` ya esta en el `path` actual, esa
     opcion se descarta (`continue`).
   - Si esta libre, se marca `arr[i]` como usado y se agrega al `path`, y
     se llama recursivamente a `backtrack` para elegir la siguiente
     posicion.
   - Al volver de la recursion se deshace la eleccion (se quita `arr[i]`
     del `path` y se desmarca en `seen`), para poder probar otro elemento
     en esa misma posicion (paso clasico de backtracking).

Este enfoque evita repetir un mismo indice dentro de una permutacion sin
necesidad de eliminar y reinsertar elementos del arreglo original.

## Complejidad

Sea `n` el numero de elementos del arreglo.

| Medida  | Complejidad |
| :------ | :---------- |
| Tiempo  | `O(n! * n)`, hay `n!` permutaciones y cada una toma `O(n)` copiar a `solution` |
| Espacio | `O(n! * n)` para guardar todas las soluciones, mas `O(n)` de la pila de recursion, `path` y `seen` |

## Archivos

- `permutation.cpp`: implementacion de `backtrack` y `permutations`. No
  incluye un `main`, es un conjunto de funciones pensado para usarse desde
  otro archivo o para practicar el patron de backtracking (aun no esta
  registrado como target en el `CMakeLists.txt` del proyecto).
- `README.md`: documentacion del problema y del algoritmo.
