# MergeSort en TypeScript

Implementacion generica de **MergeSort** usando divide y venceras y un comparador configurable.

## Descripcion

`mergeSort` divide el arreglo en dos mitades hasta obtener segmentos de un elemento. Luego combina las mitades ordenadas mediante `merge`, conservando el orden relativo de elementos equivalentes.

La implementacion retorna un nuevo arreglo y deja intacto el arreglo original.

## API

```ts
mergeSort<T>(arr: T[], compare?: Comparator<T>): T[]
```

- `arr`: arreglo que se desea ordenar.
- `compare`: comparador opcional; por defecto utiliza el orden natural de los valores.
- Retorna un nuevo arreglo ordenado.

## Ejemplo

```ts
const values = [5, 2, 8, 1, 3];
const sorted = mergeSort(values);

console.log(sorted); // [1, 2, 3, 5, 8]
console.log(values); // [5, 2, 8, 1, 3]
```

## Complejidad

| Metrica          | Complejidad                     |
| :--------------- | :------------------------------ |
| Tiempo           | `O(n log n)` en todos los casos |
| Espacio auxiliar | `O(n)`                          |

## Validaciones incluidas

El archivo incorpora comprobaciones para:

- Arreglos de numeros.
- Arreglos vacios.
- Arreglos con un solo elemento.
