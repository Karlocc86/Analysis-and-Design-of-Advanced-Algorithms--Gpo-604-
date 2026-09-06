# QuickSort en TypeScript

Implementacion recursiva de **QuickSort** para arreglos de numeros, basada en el enfoque divide y venceras.

## Descripcion

El algoritmo utiliza el ultimo elemento del rango como pivote. La funcion de particion agrupa a la izquierda los elementos menores o iguales al pivote y devuelve la posicion que divide los dos subrangos. Luego `divide` aplica el mismo proceso de forma recursiva.

El archivo incluye un ejemplo ejecutable que imprime la lista antes y despues del ordenamiento.

## API

```ts
divide(list: number[], left: number, right: number): void
```

- `list`: arreglo de numeros que se ordenara en el mismo lugar.
- `left`: indice inicial del rango.
- `right`: indice final del rango.

## Ejemplo

```ts
const values = [4, 1, 3, 2];
divide(values, 0, values.length - 1);

console.log(values); // [1, 2, 3, 4]
```

## Complejidad

| Caso          | Tiempo       | Espacio auxiliar |
| :------------ | :----------- | :--------------- |
| Mejor caso    | `O(n log n)` | `O(log n)`       |
| Caso promedio | `O(n log n)` | `O(log n)`       |
| Peor caso     | `O(n^2)`     | `O(n)`           |

## Consideraciones

- El arreglo se modifica directamente; no se crea una copia.
- El rango debe usar indices validos y `left` debe ser menor o igual que `right`.
- La seleccion fija del ultimo elemento como pivote puede producir el peor caso en arreglos ya ordenados.
