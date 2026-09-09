# Coin Change en C++

Implementacion de dos estrategias para calcular el numero minimo de monedas o
billetes necesarios para entregar un cambio:

- **Greedy**: selecciona repetidamente la denominacion mas grande que no supera
  el cambio restante.
- **Programacion dinamica**: calcula la mejor solucion para cada monto desde
  `0` hasta el cambio solicitado.

El programa asume que cada denominacion esta disponible de forma ilimitada.

## Objetivo

Dados un conjunto de denominaciones positivas y un monto de cambio, encontrar
el menor numero de monedas o billetes cuya suma sea exactamente ese monto.

Por ejemplo, para las denominaciones `{1, 5, 10, 25}` y un cambio de `37`, la
solucion minima es `4` monedas:

```text
25 + 10 + 1 + 1 = 37
```

## Algoritmos

### Greedy

`greedyCoinChange` ordena las denominaciones y comienza con la mas grande.
Mientras sea posible, agrega esa denominacion y descuenta su valor del cambio.
Si ya no cabe, continua con la siguiente denominacion.

Este enfoque es rapido y produce la solucion optima en sistemas de monedas
canonicos, como muchas monedas reales. Sin embargo, no siempre encuentra el
minimo para un conjunto arbitrario de denominaciones.

Contraejemplo:

```text
Denominaciones: {1, 3, 4}
Cambio: 6

Greedy: 4 + 1 + 1 = 3 monedas
Optima: 3 + 3 = 2 monedas
```

Si no es posible formar el cambio exacto, devuelve `-1`.

### Programacion dinamica

`dynammicProgrammingCoinChange` guarda, para cada monto `i`, el minimo numero
de monedas necesario para formarlo. El estado inicial es:

```text
minCoinToMakeN[0] = 0
```

Para cada denominacion `coin` y cada monto alcanzable `i`, evalua la
transicion:

```text
mejor(i) = min(mejor(i), mejor(i - coin) + 1)
```

Esta estrategia encuentra la solucion optima para cualquier conjunto de
denominaciones positivas. Si el cambio no puede formarse, devuelve `-1`.

> Nota: el nombre de la funcion conserva `dynammic` para coincidir con la
> implementacion actual.

## Uso del programa

El ejecutable solicita, en este orden:

1. La cantidad de denominaciones.
2. El valor de cada denominacion.
3. El total de la compra.
4. La cantidad entregada por el cliente.

El cambio se calcula como:

```text
cambio = cantidad_entregada - total_compra
```

Despues se muestran los resultados de Greedy y programacion dinamica.

### Ejemplo de ejecucion

Entrada:

```text
Ingrese el numero de valores que va a meter: 4
Denominaciones: 1, 3, 4, 10
Total a pagar: 14
Cantidad entregada: 20
```

Salida relevante:

```text
El cambio a devolver es: {6}
Segun el approach Greedy: 3
Segun el approach Dp: 2
```

La diferencia muestra por que la programacion dinamica es necesaria cuando las
denominaciones no forman un sistema canonico.

## Complejidad

Sea `N` el numero de denominaciones y `C` el monto del cambio.

| Algoritmo             | Tiempo promedio      | Espacio          |
| :-------------------- | :------------------- | :--------------- |
| Greedy                | `O(N log N + C / m)` | `O(1)` adicional |
| Programacion dinamica | `O(N * C)`           | `O(C)`           |

`m` representa la denominacion positiva mas pequena. La complejidad espacial
de Greedy no cuenta la copia del vector ni el espacio usado internamente por
`std::sort`.

La implementacion de programacion dinamica utiliza `std::unordered_map` para
almacenar los estados. La complejidad indicada es la esperada, asumiendo
operaciones promedio de tiempo constante en el mapa.

## Requisitos

- Compilador compatible con C++17 o superior.
- CMake 4.2 o superior si se utiliza la configuracion del proyecto.

## Compilacion directa

Desde la raiz del repositorio:

```bash
g++ -std=c++17 c++/Greedy/CoinChange/main.cpp -o coinChange
```

En Windows:

```powershell
C:\msys64\ucrt64\bin\g++.exe -std=c++17 c++/Greedy/CoinChange/main.cpp -o coinChange.exe
```

## Compilacion con CMake

```bash
cmake -S . -B build
cmake --build build --target coinChange
```

El ejecutable se genera como `coinChange` en Linux/macOS o `coinChange.exe` en
Windows, dentro del directorio de compilacion correspondiente.

## Archivos

- `main.cpp`: implementacion de ambos algoritmos y programa interactivo.
- `README.md`: documentacion del problema, los algoritmos y su ejecucion.
