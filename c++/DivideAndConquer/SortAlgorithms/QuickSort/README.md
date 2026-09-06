# QuickSort en C++

Implementacion recursiva de **QuickSort** para ordenar un vector de enteros mediante el enfoque divide y venceras.

## Descripcion

El algoritmo selecciona el ultimo elemento del rango como pivote. Durante la particion, los elementos menores o iguales al pivote se colocan a su izquierda. Al finalizar, el pivote queda en su posicion definitiva y el proceso se repite recursivamente en los dos subrangos.

La funcion `main` muestra el vector antes y despues del ordenamiento.

## Complejidad

| Caso          | Tiempo       | Espacio auxiliar |
| :------------ | :----------- | :--------------- |
| Mejor caso    | `O(n log n)` | `O(log n)`       |
| Caso promedio | `O(n log n)` | `O(log n)`       |
| Peor caso     | `O(n^2)`     | `O(n)`           |

El peor caso puede aparecer cuando el pivote elegido es siempre el menor o el mayor elemento.

## Requisitos

- Compilador compatible con C++14 o superior.
- CMake, si se utiliza la configuracion del proyecto.

## Ejecucion directa

Desde la raiz del repositorio:

```bash
g++ -std=c++14 c++/DivideAndConquer/SortAlgorithms/QuickSort/quickSort.cpp -o quickSort
./quickSort
```

En Windows, el ejecutable generado puede ser `quickSort.exe`.

## Estructura principal

- `swap`: intercambia dos elementos.
- `conquer`: particiona el rango y devuelve la posicion del pivote.
- `divide`: ordena recursivamente los subrangos.
