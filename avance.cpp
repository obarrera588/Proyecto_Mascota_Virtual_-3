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
// pone a dormir a la mascota
void dormir(Mascota &m) {
    if (m.sueno < 20) {
        cout << m.nombre << " no tiene sueño" << endl;
        return;
    }
    cout << m.nombre << " se durmio... zzz" << endl;
    m.sueno = 0;
    m.energia += 50;
    m.hambre += 10;
}

// baña a la mascota
void banar(Mascota &m) {
    if (m.higiene > 90) {
        cout << m.nombre << " ya esta limpio" << endl;
        return;
    }
    cout << "Bañaste a " << m.nombre << endl;
    m.higiene = 100;
    m.felicidad -= 5;
}

// le da medicina a la mascota
void darMedicina(Mascota &m) {
    if (m.salud > 80) {
        cout << m.nombre << " no esta enfermo" << endl;
        return;
    }
    cout << m.nombre << " se tomo la medicina" << endl;
    m.salud += 30;
    m.felicidad -= 10;
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
// guarda la partida en un archivo
void guardarPartida(Mascota m) {
    ofstream archivo("partida.txt");

    if (!archivo.is_open()) {
        cout << "No se pudo guardar la partida" << endl;
        return;
    }

    archivo << m.nombre << endl;
    archivo << m.tamano << endl;
    archivo << m.hambre << endl;
    archivo << m.felicidad << endl;
    archivo << m.energia << endl;
    archivo << m.sueno << endl;
    archivo << m.higiene << endl;
    archivo << m.salud << endl;
    archivo << m.turnos << endl;
    archivo << m.diasVividos << endl;
    archivo.close();

    cout << "Partida guardada" << endl;
}

// carga la partida del archivo, devuelve false si no se pudo
bool cargarPartida(Mascota &m) {
    ifstream archivo("partida.txt");

    if (!archivo.is_open()) {
        return false;
    }

    getline(archivo, m.nombre);
    archivo >> m.tamano >> m.hambre >> m.felicidad >> m.energia >> m.sueno;
    archivo >> m.higiene >> m.salud >> m.turnos >> m.diasVividos;

    // si el archivo esta mal escrito no se carga
    if (archivo.fail() || m.nombre == "" || m.tamano < 1 || m.tamano > 3 || m.salud <= 0) {
        archivo.close();
        return false;
    }
    archivo.close();

    revisarLimites(m);
    cout << "Partida cargada" << endl;
    return true;
}

// muestra como termino el juego
void mostrarFinal(Mascota m, int diasMeta) {
    cout << endl;
    dibujarMascota(m);

    if (m.salud <= 0) {
        cout << m.nombre << " se murio :(" << endl;
        if (m.hambre >= 100) {
            cout << "No le diste de comer..." << endl;
        }
    } else if (m.diasVividos >= diasMeta) {
        cout << "Ganaste! " << m.nombre << " sobrevivio " << diasMeta << " dias" << endl;
    } else {
        cout << "Adios! " << m.nombre << " te va a extrañar" << endl;
    }
    cout << "Dias vividos: " << m.diasVividos << endl;
}

// ======================= PROGRAMA PRINCIPAL =======================

int main() {
    Mascota m;
    int opcion;
    int diasMeta = 7;

    cout << "========== MASCOTA VIRTUAL ==========" << endl;
    cout << "Cuida a tu mascota durante " << diasMeta << " dias" << endl;
    cout << "1. Nueva mascota" << endl;
    cout << "2. Cargar partida" << endl;
    cout << "Opcion: ";
    opcion = leerNumero(1, 2);

    if (opcion == 2) {
        if (!cargarPartida(m)) {
            cout << "No hay partida guardada, vamos a crear una nueva" << endl;
            crearMascota(m);
        }
    } else {
        crearMascota(m);
    }

    do {
        mostrarEstado(m);
        cout << endl;
        cout << "1. Alimentar" << endl;
        cout << "2. Jugar" << endl;
        cout << "3. Dormir" << endl;
        cout << "4. Bañar" << endl;
        cout << "5. Dar medicina" << endl;
        cout << "6. Guardar partida" << endl;
        cout << "7. Salir" << endl;
        cout << "Opcion: ";
        opcion = leerNumero(1, 7);

        if (opcion == 1) {
            alimentar(m);
        } else if (opcion == 2) {
            jugar(m);
        } else if (opcion == 3) {
            dormir(m);
        } else if (opcion == 4) {
            banar(m);
        } else if (opcion == 5) {
            darMedicina(m);
        } else if (opcion == 6) {
            guardarPartida(m);
        }

        // guardar y salir no gastan turno
        if (opcion >= 1 && opcion <= 5) {
            revisarLimites(m);
            pasarTiempo(m);
            eventoDelDia(m);
        }

    } while (opcion != 7 && m.salud > 0 && m.diasVividos < diasMeta);

    mostrarFinal(m, diasMeta);

    return 0;
}
