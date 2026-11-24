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
