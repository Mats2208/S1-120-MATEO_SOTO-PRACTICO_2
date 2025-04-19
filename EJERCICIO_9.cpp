/*
*Cola de pasajeros en una estación de tren
En una estación de tren, los pasajeros hacen fila para comprar boletos. Cada
pasajero tiene un nombre y el destino al que quiere viajar. El cajero atiende a los
pasajeros en el orden en que llegaron. Diseña un programa que gestione la cola de
pasajeros y los atienda en el orden correcto.
*/

#include <iostream>
#include "Queue.h"

using namespace std;

class pasajero {
private:
    string name;
    string destino;
public:
    pasajero(string _name = "", string _destino = "") {
        SetName(_name);
        SetDestino(_destino);
    }

    void SetName(string _name) {
        name = _name;
    }
    void SetDestino(string _destino) {
        destino = _destino;
    }

    string GetName() const {
        return name;
    }

    string GetDestino() const {
        return destino;
    }

    void MostrarDatos() {
        cout << "Nombre: " << GetName() << ", Destino: " << GetDestino() << endl;
    }
};

ostream& operator<<(ostream &os, const pasajero &p) {
    os << "Nombre: " << p.GetName() << ", Destino: " << p.GetDestino() << endl;
    return os;
}

class tren {
    private:
    Queue<pasajero> fila;
    public:
    void anadirPasajero(pasajero p) {
        fila.push(p);
    }

    void mostrarFila() {
        fila.print();
    }

    void Siguiente() {
        pasajero temp;
        fila.pop(temp);
        cout << "Entrando a recepcion el pasajero: "<< temp.GetName() << ", Con destino a " << temp.GetDestino()<< endl;
    }
};

int main() {
    pasajero P1("Mateo", "Beni");
    pasajero P2("Lucas", "La Paz");
    pasajero P3("Thais", "Tarija");

    //Creando el tren
    tren Polar;

    //Poniendo pasajeros a la fila
    Polar.anadirPasajero(P1);
    Polar.anadirPasajero(P2);
    Polar.anadirPasajero(P3);

    //Mostrando fila
    cout << "FILA ACTUAL:" << endl;
    Polar.mostrarFila();

    //Siguiente Pasajero
    cout << "Accediendo a ventanilla..." << endl;
    Polar.Siguiente();

    cout << "\nFILA ACTUAL:" << endl;
    Polar.mostrarFila();
}