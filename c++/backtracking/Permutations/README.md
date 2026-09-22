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

## Pruebas

El `main` ejecuta una bateria de 8 pruebas contra `permutations(arr)`, cada
una con un arreglo distinto (vacio, un elemento, varios elementos, numeros
negativos y el arreglo global `nums`). Cada prueba usa dos funciones de
apoyo:

- `factorial(n)`: calcula `n!`, la cantidad de permutaciones esperadas.
- `allPermutationsAreValid(result, arr)`: verifica que cada permutacion
  tenga el mismo tamano y el mismo multiconjunto de valores que `arr`, y que
  no haya permutaciones repetidas en `result`.

`runTest(name, arr)` corre `permutations(arr)`, compara el numero de
resultados contra `factorial(arr.size())`, valida el contenido con
`allPermutationsAreValid` e imprime si la prueba paso o fallo.

### Ejemplo de ejecucion

```text
Ejecutando pruebas de permutations()
Arreglo vacio: OK (1 permutaciones)
Un elemento: OK (1 permutaciones)
Dos elementos: OK (2 permutaciones)
Tres elementos: OK (6 permutaciones)
Cuatro elementos: OK (24 permutaciones)
Numeros negativos y cero: OK (6 permutaciones)
Cinco elementos: OK (120 permutaciones)
Global nums predefinido: OK (6 permutaciones)
```

## Requisitos

- Compilador compatible con C++17 o superior.

## Compilacion directa

Desde la raiz del repositorio:

```bash
g++ -std=c++17 c++/backtracking/Permutations/permutation.cpp -o permutations
```

En Windows:

```powershell
C:\msys64\ucrt64\bin\g++.exe -std=c++17 c++/backtracking/Permutations/permutation.cpp -o permutations.exe
```

## Archivos

- `permutation.cpp`: implementacion de `backtrack` y `permutations`, mas un
  `main` con pruebas automatizadas que verifican la cantidad y validez de
  las permutaciones generadas (aun no esta registrado como target en el
  `CMakeLists.txt` del proyecto).
- `README.md`: documentacion del problema, el algoritmo y las pruebas.
