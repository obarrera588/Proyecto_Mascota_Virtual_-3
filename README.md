# Mascota Virtual

Proyecto en C++ para desarrollar una mascota virtual.

## Estado actual

El proyecto está en desarrollo. Por ahora, `avance.cpp` solo incluye la biblioteca de entrada y salida de C++; todavía no contiene una función `main` ni funcionalidades implementadas.

## Requisitos

- Un compilador de C++, como g++ o MinGW.

## Próximos pasos

Agregar el punto de entrada del programa y desarrollar las funcionalidades de la mascota virtual.


### Oswaldo: interfaz de consola (⁠ interfaz.h ⁠, ⁠ interfaz.cpp ⁠)

Oswaldo se encarga de todo lo que el jugador ve y escribe.

•⁠  ⁠Pantalla de inicio: título del juego, pedir el nombre de la mascota o elegir "Cargar partida".
•⁠  ⁠Mostrar el menú de acciones y leer la opción del jugador.
•⁠  ⁠Validar la entrada: si el jugador escribe una letra o un número fuera del menú, mostrar un error y volver a preguntar sin que el programa se caiga.
•⁠  ⁠Mostrar las estadísticas con barras, por ejemplo ⁠ Hambre    [######----] 60 ⁠.
•⁠  ⁠Dibujar la mascota en ASCII con una cara distinta según su estado de ánimo (feliz, triste, dormida, enferma).
•⁠  ⁠Pantalla de fin de juego con los días que sobrevivió la mascota.


### Emilio: el ciclo del juego

Emilio se encarga de que el juego avance y de unir las partes de los tres.

•⁠  ⁠Programar el ciclo principal: mostrar el estado, leer la acción, aplicarla, avanzar el tiempo y revisar si la mascota sigue viva.
•⁠  ⁠Programar el paso del tiempo, que cambia las estadísticas en cada turno y cuenta los días.
•⁠  ⁠Agregar eventos aleatorios, por ejemplo que la mascota se enferme o encuentre un juguete.
•⁠  ⁠Guardar la partida en un archivo de texto y poder cargarla después.
•⁠  ⁠Unir el código de los tres y compilar el proyecto completo.