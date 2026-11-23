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
    // juega con la mascota
void jugar(Mascota &m) {
    int juego;

    if (m.energia < 20) {
        cout << m.nombre << " esta muy cansado para jugar" << endl;
        return;
    }
     cout << "1. Lanzar la pelota" << endl;
    cout << "2. Saltar la cuerda" << endl;
    cout << "Opcion: ";
    juego = leerNumero(1, 2);

     if (juego == 1) {
        cout << "Le lanzaste la pelota y " << m.nombre << " fue a traerla" << endl;
        m.felicidad += 20;
    } else {
        int saltos;
        cout << "Cuantos saltos va a dar? (1-10): ";
        saltos = leerNumero(1, 10);

        for (int i = 1; i <= saltos; i++) {
            cout << "Salto " << i << "!" << endl;
        }
        // entre mas saltos mas feliz pero mas cansado
        m.felicidad += saltos * 3;
        m.energia -= saltos;
    }
    m.energia -= 20;
    m.higiene -= 10;
} 


// parte de emilio    
}
// en cada turno la mascota tiene mas hambre, sueño y se ensucia
void pasarTiempo(Mascota &m) {
    m.hambre += 5 + m.tamano * 2; // entre mas grande mas hambre le da
    m.energia -= 5;
    m.sueno += 8;
    m.felicidad -= 5;
    m.higiene -= 5;

    // si no come se muere
    if (m.hambre >= 100) {
        m.salud -= 25;
    } else if (m.hambre >= 80) {
        m.salud -= 10;
    }
    if (m.higiene < 20) {
        m.salud -= 5;
    }
    if (m.sueno >= 100) {
        m.salud -= 10;
    }

    revisarLimites(m);

    // cada 3 turnos pasa un dia
    m.turnos++;
    if (m.turnos == 3) {
        m.turnos = 0;
        m.diasVividos++;
    }
}

// cuando empieza un dia nuevo pasa algo distinto
void eventoDelDia(Mascota &m) {
    if (m.turnos != 0) {
        return;
    }

    cout << endl << "--- Empieza un nuevo dia ---" << endl;
switch (m.diasVividos) {
        case 1:
            cout << m.nombre << " encontro una galleta en el suelo" << endl;
            m.hambre -= 15;
            break;
        case 2:
            cout << "Esta lloviendo y " << m.nombre << " se resfrio" << endl;
            m.salud -= 15;
            break;
        case 3:
            cout << m.nombre << " encontro un juguete nuevo" << endl;
            m.felicidad += 15;
            break;
        case 4:
            cout << m.nombre << " se revolco en el lodo" << endl;
            m.higiene -= 30;
            break;
        case 5:
            cout << m.nombre << " no pudo dormir bien anoche" << endl;
            m.sueno += 20;
            break;
        default:
            cout << m.nombre << " amanecio de buen humor" << endl;
            m.felicidad += 10;
    }
    revisarLimites(m);
}

