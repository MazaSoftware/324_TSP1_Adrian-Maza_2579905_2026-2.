# TSP 1 - Computación III

Repositorio para la entrega del **Trabajo Práctico N° 1** de la asignatura **Computación III**


## 📁 Estructura del Repositorio
Este repositorio contiene la solución a los ejercicios prácticos de la evaluación:

* `Ejercicio 1/` - Implementación y solución del ejercicio 1.

El tipo abstracto de datos apropiado es el array que nos permite hacer operaciones mediante métodos

Esta vez deje las clases publica solo para efectos del ejercicio pero es buena practica hacerlo con métodos getters y que la clase quede privada para que el código en cuestion sea mas robusto ante errores de datos. 

* `Ejercicio 2/` - Implementación y solución del ejercicio 2.

Para resolver este ejercicio implementé una clase Nodo Ciudad que modela la estructura de la lista circular solicitada, añadiendo atributos para el identificador de la ciudad, la distancia al siguiente destino y un puntero de enlace. Luego, desarrollé la función Recorrido utilizando un ciclo do-while para recorrer dinámicamente los nodos enlazados, permitiendo imprimir la ruta completa, simular el regreso al origen y acumular de forma correcta la distancia total recorrida. Finalmente, en la función principal (main) configuré los nodos de prueba basados en el enunciado para verificar el funcionamiento del algoritmo y gestionar adecuadamente la memoria dinámica. 


* `Ejercicio 3/` - Implementación y solución del ejercicio 3.
Para resolver el ejercicio del sistema de colas de la oficina estatal, definí las clases Persona y Cola con nodos enlazados para el manejo dinámico de los datos. Posteriormente, implementé la función Distribuir, la cual extrae los elementos de la cola general de forma secuencial y los reubica condicionalmente en tres colas diferentes según el rango de su tipo de operación (1-3, 4-6 y 7-9). 

Se trata de un TAD de tipo cola, ademas implemente una función main que el ejercicio no pedía explícitamente pero lo hice para que el resultado se viera en la terminal.

* `Ejercicio 4/` - Implementación del Árbol Binario de Búsqueda (`ArbolBinarioBusqueda`).

Me enfoque en mantener el comportamiento característico de TAD árbol

Implementé un Árbol Binario de Búsqueda (ABB) con inserción recursiva y una función para hallar un nodo y calcular su grado (número de hijos), dando solución al objetivo planteado en la evaluación. El algoritmo busca el valor de forma recursiva, evalúa sus punteros izquierdo y derecho para determinar si su grado es 0, 1 o 2, y emite el mensaje reglamentario en caso de que el elemento no sea encontrado. 


---

##  Tecnologías Utilizadas
* **Lenguaje:** C++
* **Compilador:** g++ / MinGW
* **Entorno de Desarrollo:** Visual Studio Code
