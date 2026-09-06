# Búsqueda Binaria Recursiva en C++

Implementación recursiva de **Búsqueda Binaria** en C++, con generación pseudoaleatoria del valor objetivo.

## Descripción

El programa genera un objetivo entero con `std::uniform_int_distribution`, aplica búsqueda binaria sobre el intervalo `[0, 100]` y muestra el resultado encontrado. En cada llamada, el rango se reduce aproximadamente a la mitad.

## Funcionamiento

- `std::random_device` obtiene la semilla del generador.
- `std::mt19937` genera la secuencia pseudoaleatoria.
- `binarySearch` compara el objetivo con el punto medio y continúa en el subrango correspondiente.
- Si el valor no está dentro del intervalo buscado, retorna `-1`.

## Complejidad

| Métrica          | Complejidad                 |
| :--------------- | :-------------------------- |
| Tiempo           | `O(log n)`                  |
| Mejor caso       | `O(1)`                      |
| Espacio auxiliar | `O(log n)` por la recursión |

## Requisitos

- Compilador compatible con C++14 o superior.
- Biblioteca estándar de C++.

## Ejecución directa

Desde la raíz del repositorio:

```bash
g++ -std=c++14 c++/DivideAndConquer/SortAlgorithms/SearchAlgorithms/binarySearch.cpp -o binarySearch
./binarySearch
```

En Windows, el ejecutable generado puede ser `binarySearch.exe`.

## Nota sobre el rango

El generador está configurado con el intervalo `[0, 101]`, mientras que la búsqueda se ejecuta sobre `[0, 100]`. Por ello, si el objetivo generado es `101`, el programa retorna `-1` de forma esperada.
