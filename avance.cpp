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

// pide un numero entero entre min y max, si no es valido lo vuelve a pedir
int leerNumero(int min, int max) {
    int numero;
    while (!(cin >> numero) || cin.peek() != '\n' || numero < min || numero > max) {
        // si se cierra la entrada se regresa la ultima opcion
        if (cin.eof()) {
            return max;
        }
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Opcion invalida, ingrese un numero entre " << min << " y " << max << ": ";
    }
    cin.ignore(1000, '\n');
    return numero;
}

// hace que un valor no baje de 0 ni pase de 100
void limitar(int &valor) {
    if (valor > 100) {
        valor = 100;
    }
    if (valor < 0) {
        valor = 0;
    }
}

// ===================== PARTE DE OSWALDO ===================== //

// le da de comer a la mascota
void alimentar(Mascota &m) {
    int comida;

    if (m.hambre < 10) {
        cout << m.nombre << " no tiene hambre" << endl;
        return;
    }

    cout << "1. Manzana" << endl;
    cout << "2. Hamburguesa" << endl;
    cout << "3. Pastel" << endl;
    cout << "Que le quieres dar: ";
    comida = leerNumero(1, 3);

    if (comida == 1) {
        m.hambre -= 20;
        m.salud += 5;
    } else if (comida == 2) {
        m.hambre -= 40;
        m.salud -= 5;
    } else {
        m.hambre -= 25;
        m.felicidad += 15;
        m.salud -= 5;
    }
    cout << m.nombre << " comio. Nyam nyam!" << endl;
}
