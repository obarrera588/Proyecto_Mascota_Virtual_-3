#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// ======================= PARTE DE CARLOS =======================

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

// revisa todas las estadisticas de la mascota
void revisarLimites(Mascota &m) {
    limitar(m.hambre);
    limitar(m.felicidad);
    limitar(m.energia);
    limitar(m.sueno);
    limitar(m.higiene);
    limitar(m.salud);
}

// pide el nombre y el tamaño de la mascota nueva
void crearMascota(Mascota &m) {
    cout << "Nombre de tu mascota: ";
    getline(cin, m.nombre);

    while (m.nombre == "" || m.nombre[0] == ' ' || m.nombre.length() > 15) {
        if (cin.eof()) {
            m.nombre = "Mascota";
            return;
        }
        cout << "El nombre no puede estar vacio ni tener mas de 15 letras: ";
        getline(cin, m.nombre);
    }

    cout << "Tamaño de " << m.nombre << ":" << endl;
    cout << "1. Pequeño" << endl;
    cout << "2. Mediano" << endl;
    cout << "3. Grande" << endl;
    cout << "Opcion: ";
    m.tamano = leerNumero(1, 3);
}

// muestra una barra de 10 espacios segun el valor
void mostrarBarra(string texto, int valor) {
    cout << texto << " [";
    for (int i = 1; i <= 10; i++) {
        if (i <= valor / 10) {
            cout << "#";
        } else {
            cout << "-";
        }
    }
    cout << "] " << valor << "%" << endl;
}

// dibuja la mascota segun su tamaño y su estado de animo
void dibujarMascota(Mascota m) {
    string cara;

    if (m.salud <= 0) {
        cara = "(x_x)";
    } else if (m.salud < 30 || m.hambre > 80) {
        cara = "(T_T)";
    } else if (m.felicidad > 70) {
        cara = "(^_^)";
    } else {
        cara = "(o_o)";
    }

    if (m.tamano == 1) {
        cout << "   " << cara << endl;
    } else if (m.tamano == 2) {
        cout << "    _____" << endl;
        cout << "   |" << cara << "|" << endl;
        cout << "   |_____|" << endl;
    } else {
        cout << "    _______" << endl;
        cout << "   |       |" << endl;
        cout << "   | " << cara << " |" << endl;
        cout << "   |_______|" << endl;
    }
}

// muestra el dibujo y todas las barras
void mostrarEstado(Mascota m) {
    cout << endl;
    cout << "========== " << m.nombre << " - Dia " << m.diasVividos + 1 << " ==========" << endl;
    dibujarMascota(m);
    mostrarBarra("Salud    ", m.salud);
    mostrarBarra("Hambre   ", m.hambre);
    mostrarBarra("Energia  ", m.energia);
    mostrarBarra("Sueño    ", m.sueno);
    mostrarBarra("Felicidad", m.felicidad);
    mostrarBarra("Higiene  ", m.higiene);

    if (m.hambre >= 80) {
        cout << "Cuidado! " << m.nombre << " tiene mucha hambre" << endl;
    }
    if (m.salud <= 30) {
        cout << "Cuidado! " << m.nombre << " esta enfermo" << endl;
    }
}
