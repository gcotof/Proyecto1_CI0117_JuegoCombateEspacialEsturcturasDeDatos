/*
Teoría de Hash Set (Tabla de Dispersión)

1. Concepto y Funcionamiento
- Mapeo de Llaves:
  Se utiliza una función de hash (h) para calcular el índice o slot en un arreglo
  a partir de una llave (k), mapeando el universo de llaves U al rango [0, m-1].

- Tabla de Hash:
  Es un arreglo de tamaño m proporcional a la cantidad de llaves que se planea
  almacenar, optimizando el uso de memoria en comparación con el direccionamiento directo.

- La "Estrella de la Muerte":
  En el contexto del proyecto, se le denomina así porque su tiempo de búsqueda es
  constante (O(1)), lo que permite generar el máximo daño de ataque de forma casi instantánea.

2. Manejo de Colisiones
Dado que el universo de llaves es mayor que el número de slots, las colisiones son inevitables
y se resuelven mediante:

- Encadenamiento (Chaining):
  Los elementos que colisionan en el mismo índice se almacenan en una lista enlazada
  (preferiblemente doblemente enlazada para facilitar el borrado en O(1)).

- Direccionamiento Abierto (Open Addressing):
  Todos los elementos se guardan en la tabla misma. Si un slot está ocupado, se sigue
  una secuencia de sondeo (lineal, cuadrática o hash doble) hasta hallar un espacio vacío.

3. Eficiencia Asintótica
- Caso Promedio:
  Bajo la suposición de hash uniforme simple, el tiempo de búsqueda, inserción y borrado es O(1).

- Peor Caso:
  El tiempo puede degradarse a Theta(n) si todas las llaves colisionan en un mismo índice,
  convirtiendo la tabla en una lista lineal.

Bibliografía de Referencia

1. Cormen, T. H., Leiserson, C. E., Rivest, R. L. y Stein, C.
   Introduction to Algorithms, 3ra ed. MIT Press, 2009.
   Capítulo 11: Hash Tables (págs. 253-282).

2.  https://www.youtube.com/watch?v=-2cmf5eyu2s

3. https://www.youtube.com/watch?v=e-O7jiAUvos
*/