# Busqueda Binaria Recursiva en TypeScript

Implementacion generica de **Busqueda Binaria** con recursion y comparadores personalizados.

## Descripcion

`binarySearchRecursive` busca un elemento dentro de un arreglo ordenado. En cada llamada compara el objetivo con el elemento central y descarta la mitad que no puede contenerlo.

La funcion admite cualquier tipo `T`, siempre que el arreglo este ordenado de acuerdo con el comparador utilizado.

## API

```ts
binarySearchRecursive<T>(arr, target, compare?, lo?, hi?): number
```

- `arr`: arreglo ordenado donde se realiza la busqueda.
- `target`: valor que se desea encontrar.
- `compare`: comparador opcional; devuelve un numero menor, igual o mayor que cero.
- `lo` y `hi`: limites opcionales del rango de busqueda.
- Retorna el indice encontrado o `-1` si el objetivo no existe.

## Ejemplo

```ts
const values = [1, 3, 5, 7, 9];
const position = binarySearchRecursive(values, 7);

console.log(position); // 3
```

## Complejidad

| Metrica          | Complejidad                 |
| :--------------- | :-------------------------- |
| Tiempo           | `O(log n)`                  |
| Espacio auxiliar | `O(log n)` por la recursion |

## Consideraciones

- El arreglo debe estar ordenado segun `compare`.
- La funcion no modifica el arreglo recibido.
- Para objetos o reglas de orden personalizadas, se debe proporcionar un comparador.
