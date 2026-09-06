# MergeSort en C++

Implementacion recursiva de **MergeSort** para ordenar un vector de enteros mediante el enfoque divide y venceras.

## Descripcion

El algoritmo divide el vector en dos mitades hasta obtener segmentos de uno o cero elementos. Luego combina las mitades ordenadas mediante la funcion `merge`, conservando el orden relativo de elementos iguales.

La funcion `mergeSort` retorna un nuevo vector ordenado y deja intacto el vector original.

La funcion `main` muestra el vector antes y despues del ordenamiento.

## Complejidad

| Caso            | Tiempo       | Espacio auxiliar |
| :-------------- | :----------- | :--------------- |
| Todos los casos | `O(n log n)` | `O(n)`           |

El espacio auxiliar se utiliza para crear los vectores izquierdo, derecho y resultado durante la combinacion. La recursion agrega una profundidad de `O(log n)`.

## Requisitos

- Compilador compatible con C++14 o superior.
- CMake, si se utiliza la configuracion del proyecto.

## Ejecucion directa

Desde la raiz del repositorio:

```bash
g++ -std=c++14 c++/DivideAndConquer/SortAlgorithms/MergeSort/mergeSort.cpp -o mergeSort
./mergeSort
```

En Windows, el ejecutable generado puede ser `mergeSort.exe`.

## Estructura principal

- `merge`: combina dos vectores ordenados en un unico vector ordenado.
- `mergeSort`: divide el vector y ordena recursivamente cada mitad.
- `main`: ejecuta el algoritmo y muestra los resultados.
