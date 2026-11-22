#include <iostream>
using namespace std;



// ======================= PARTE DE OSWALDO =======================

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
