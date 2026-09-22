# N-Queens (Backtracking) en C++

Implementacion del problema de las N reinas usando backtracking: colocar `n`
reinas en un tablero de `n x n` de forma que ninguna par de reinas se ataque
entre si (misma fila, misma columna o misma diagonal).

## Objetivo

Dado un entero `n`, encontrar todas las formas de colocar `n` reinas en un
tablero `n x n` sin que ninguna amenace a otra, y devolver cada solucion como
una representacion del tablero.

## Algoritmo

`solveMqueens(n)` prepara el estado inicial y delega en `backtrack`:

- `col`: columnas ya ocupadas por una reina.
- `posDiag`: diagonales positivas ocupadas, identificadas por `r + c`
  (esta suma se mantiene constante a lo largo de una diagonal `\`).
- `negDiag`: diagonales negativas ocupadas, identificadas por `r - c`
  (esta resta se mantiene constante a lo largo de una diagonal `/`).
- `board`: tablero de `n` strings de longitud `n`, inicializado con `'.'`.
- `result`: acumula una copia del tablero por cada solucion valida.

`backtrack(r, n, col, negDiag, posDiag, board, result)` procesa el tablero
fila por fila:

1. Si `r == n`, ya se coloco una reina en cada fila: se guarda una copia de
   `board` en `result`.
2. Si no, para cada columna `c` de la fila `r`:
   - Si `c`, `r - c` o `r + c` ya estan ocupados, esa casilla se descarta
     (`continue`).
   - Si esta libre, se marca la columna y ambas diagonales, se coloca la
     reina (`board[r][c] = 'Q'`) y se llama recursivamente a `backtrack`
     para la fila `r + 1`.
   - Al volver de la recursion se deshace la marca (columna, diagonales y
     casilla), para poder probar la siguiente columna con el tablero en su
     estado original (paso clasico de backtracking).

Este enfoque evita construir tableros invalidos desde el inicio: cada
colocacion se descarta en cuanto se detecta un conflicto, en vez de generar
todas las permutaciones posibles y filtrarlas despues.

## Complejidad

Sea `n` el numero de reinas (y el tamano del tablero).

| Medida  | Complejidad |
| :------ | :---------- |
| Tiempo  | `O(n!)` en el peor caso |
| Espacio | `O(n^2)` para guardar cada solucion, mas `O(n)` de la pila de recursion y los conjuntos de control |

El tiempo real es mucho menor a `n!` en la practica gracias a la poda
temprana (columnas y diagonales ocupadas), pero `O(n!)` sigue siendo la cota
superior del espacio de busqueda sin podar.

## Uso del programa

El ejecutable solicita el tamano del tablero `n` y muestra cuantas
soluciones existen, ademas del tablero de la primera solucion encontrada.

### Ejemplo de ejecucion

Entrada:

```text
Ingrese el tamano del tablero (n): 4
```

Salida:

```text
Soluciones encontradas: 2
Primera solucion:
.Q..
...Q
Q...
..Q.
```

## Requisitos

- Compilador compatible con C++17 o superior.
- CMake 4.2 o superior si se utiliza la configuracion del proyecto.

## Compilacion directa

Desde la raiz del repositorio:

```bash
g++ -std=c++17 c++/backtracking/Nqueens/Nqueens.cpp -o nqueens
```

En Windows:

```powershell
C:\msys64\ucrt64\bin\g++.exe -std=c++17 c++/backtracking/Nqueens/Nqueens.cpp -o nqueens.exe
```

## Compilacion con CMake

```bash
cmake -S . -B build
cmake --build build --target Nqueens
```

El ejecutable se genera como `Nqueens` en Linux/macOS o `Nqueens.exe` en
Windows, dentro del directorio de compilacion correspondiente.

## Archivos

- `Nqueens.cpp`: implementacion de `backtrack`, `solveMqueens` y un `main`
  interactivo para probar el algoritmo.
- `Nqueens.md`: documentacion del problema y del algoritmo.
