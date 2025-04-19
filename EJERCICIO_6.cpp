/*
Gestión de turnos en un banco
En un banco, los clientes reciben un número de turno al llegar, y son atendidos en
ese mismo orden. Cada cliente tiene un nombre y el tipo de transacción que desea
realizar (depósito, retiro, etc.). Crea un programa que gestione la fila de clientes y
los vaya atendiendo uno por uno
*/

#include <iostream>
#include "Queue.h"

using namespace std;

class cliente {
private:
    string name;
    string type;
    public:

    cliente(string _name = "Desconocido" , string _type = "NULL") {
        SetName(_name);
        SetType(_type);
    }

public:
    void SetName(string _name) {
        name = _name;
    }

    void SetType(string _type) {
        type = _type;
    }

    string GetName() const {
        return name;
    }

    string GetType() const {
        return type;
    }

    void MostrarDatosCliente() {
        cout << "===========================" << endl;
        cout << "Nombre: " << GetName() << endl;
        cout << "Type: " << GetType() << endl;
        cout << "===========================" << endl;
    }
};

ostream& operator<<(ostream &os, const cliente &cliente) {
    os << endl;
    cout << "--- ";
    cout << "Nombre: " << cliente.GetName() << ", ";
    cout << "Type: " << cliente.GetType();
    cout << " ---" << endl;
    return os;
}

class Banco {
private:
    Queue<cliente> clientes;

    public:

    void anadirCliente(cliente p) {
        clientes.push(p);
    }

    cliente SiguienteCliente() {
        cliente temp;
        clientes.peek(temp);
        return temp;
    }

    void MostrarFila() {
        clientes.print();
    }

    void Atencion() {
        cliente temp;
        clientes.pop(temp);
        cout << "El cliente: '" << temp.GetName() << "' entra a casilla unica" << endl;
    }

    int Size() {
        return clientes.getSize();
    }
};

int main() {
    //Crear clientes
    cliente C1("Mateo", "Deposito");
    cliente C2("Andres", "Retiro");
    cliente C3("Lucas", "Prestamo");
    cliente C4("Gabriel", "Deposito");
    cliente C5("Thais", "Retiro");

    Banco BMSC;
    //Pushear clientes a la cola
    BMSC.anadirCliente(C1);
    BMSC.anadirCliente(C2);
    BMSC.anadirCliente(C3);
    BMSC.anadirCliente(C4);
    BMSC.anadirCliente(C5);

    //Mostrar Cola
    BMSC.MostrarFila();

    //Atencion hasta que la Cola se acabe
    int contador = 1;
    while (BMSC.Size() > 0) {
        cout << "Cliente Numero N" << contador++ << endl;
        BMSC.Atencion();
    }

}