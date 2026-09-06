# Búsqueda Binaria Recursiva (Binary Search) en C++

Implementación del algoritmo clásico de **Búsqueda Binaria** en C++ moderno, utilizando un generador de números pseudoaleatorios (`<random>`) para definir el valor objetivo de forma dinámica.

---

## Descripción

El programa selecciona aleatoriamente un número entero en el rango cerrado $[0, 100]$ y emplea búsqueda binaria recursiva para encontrarlo dividiendo el espacio de búsqueda a la mitad en cada paso.

### Características
* **Generación moderna de aleatorios:** Emplea `std::random_device`, `std::mt19937` (Mersenne Twister) y `std::uniform_int_distribution`.
* **Cálculo seguro del punto medio:** Usa `mid = low + (high - low) / 2` para evitar desbordamientos aritméticos (*overflow* de enteros).
* **Propagación recursiva estricta:** Retorna explícitamente las llamadas recursivas para garantizar que el valor fluya de regreso en la pila de ejecución.

---

## Complejidad

| Métrica | Complejidad | Detalle |
| :--- | :--- | :--- |
| **Tiempo (Peor / Promedio)** | $O(\log n)$ | El espacio de búsqueda se reduce a la mitad en cada iteración. |
| **Tiempo (Mejor caso)** | $O(1)$ | Ocurre si el elemento central inicial coincide con el objetivo. |
| **Espacio auxiliar** | $O(\log n)$ | Debido a la memoria utilizada por la pila de llamadas recursivas (*call stack*). |

---
}