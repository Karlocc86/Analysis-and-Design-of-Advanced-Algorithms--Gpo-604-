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

## Estado pendiente

- El archivo `Nqueens.cpp` no compila actualmente: en la linea de
  `negDiag.insert(r-c);` hay un caracter `s` suelto que rompe la
  compilacion.
- El archivo no tiene una funcion `main`, por lo que todavia no se puede
  ejecutar como programa independiente ni mostrar un ejemplo de salida real.

## Archivos

- `Nqueens.cpp`: implementacion de `backtrack` y `solveMqueens`.
- `Nqueens.md`: documentacion del problema y del algoritmo.
