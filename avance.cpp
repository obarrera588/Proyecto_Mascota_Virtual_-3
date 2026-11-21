#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// PARTE DE CARLOS

// Estructura de la mascota
struct Mascota {
    string nombre;
    int tamano = 2; // 1 = pequeño, 2 = mediano, 3 = grande
    int hambre = 20;
    int felicidad = 80;
    int energia = 80;
    int sueno = 20;
    int higiene = 80;
    int salud = 100;
    int turnos = 0;
    int diasVividos = 0;
};
