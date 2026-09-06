# MergeSort en C++

Implementacion recursiva de **MergeSort** para ordenar un vector de enteros mediante el enfoque divide y venceras.

## Descripcion

El algoritmo divide el vector en dos mitades hasta obtener segmentos de uno o cero elementos. Luego combina las mitades ordenadas mediante la funcion `merge`, conservando el orden relativo de elementos iguales.

La funcion `mergeSort` retorna un nuevo vector ordenado y deja intacto el vector original.

La implementacion se compila como una biblioteca para que pueda reutilizarse y probarse desde otros archivos.

Las pruebas automatizadas se encuentran en `test_mergeSort.cpp` y verifican vectores vacios, un solo elemento, valores repetidos, numeros negativos y que el vector original no se modifique.

## Complejidad

| Caso            | Tiempo       | Espacio auxiliar |
| :-------------- | :----------- | :--------------- |
| Todos los casos | `O(n log n)` | `O(n)`           |

El espacio auxiliar se utiliza para crear los vectores izquierdo, derecho y resultado durante la combinacion. La recursion agrega una profundidad de `O(log n)`.

## Requisitos

- Compilador compatible con C++14 o superior.
- CMake, si se utiliza la configuracion del proyecto.

## Ejecucion de las pruebas

Desde la raiz del repositorio, despues de configurar CMake:

```bash
cmake --build cmake-build-debug --target testMergeSort
ctest --test-dir cmake-build-debug -R MergeSortTest --output-on-failure
```

En Windows, el ejecutable generado puede ser `testMergeSort.exe`.

## Estructura principal

- `merge`: combina dos vectores ordenados en un unico vector ordenado.
- `mergeSort`: divide el vector y ordena recursivamente cada mitad.
- `test_mergeSort.cpp`: valida el comportamiento del algoritmo mediante pruebas automatizadas.
