/*
*Gestión de consultas de soporte técnico
En una empresa de soporte técnico, las consultas de los clientes se procesan en el
orden en que se reciben. Cada consulta tiene un nombre del cliente y una
descripción del problema. Diseña un programa que gestione la fila de consultas y
permita saber cuál es la siguiente consulta a atender.
*/

#include <iostream>
#include "Queue.h"

using namespace std;

class consulta {
private:
    string name;
    string descripcion;

public:
    consulta(string _name = "", string _descripcion = "") {
        SetNombre(_name);
        SetDescripcion(_descripcion);
    }

    void SetNombre(string _name) {
        name = _name;
    }

    void SetDescripcion(string _descripcion) {
        descripcion = _descripcion;
    }

    string GetNombre() const {
        return name;
    }

    string GetDescripcion() const {
        return descripcion;
    }

    void MostrarDatos() {
        cout << "Cliente: " << GetNombre() << ", Problema: " << GetDescripcion() << endl;
    }
};

ostream& operator<<(ostream &os, const consulta &c) {
    os << "Cliente: " << c.GetNombre() << ", Problema: " << c.GetDescripcion() << endl;
    return os;
}

class SoporteTecnico {
private:
    Queue<consulta> filaConsultas;

public:
    void anadirConsulta(consulta c) {
        filaConsultas.push(c);
    }

    void mostrarConsultas() {
        filaConsultas.print();
    }

    void atenderConsulta() {
        consulta temp;
        if (filaConsultas.pop(temp)) {
            cout << "Atendiendo consulta de: " << temp.GetNombre() << endl;
            cout << "Descripcion del problema: " << temp.GetDescripcion() << endl;
        } else {
            cout << "No hay consultas pendientes" << endl;
        }
    }
};

int main() {
    // Crear consultas
    consulta C1("Mateo", "No puede acceder al correo");
    consulta C2("Lucas", "Problemas con la impresora");
    consulta C3("Thais", "Pantalla azul al iniciar");

    // Crear sistema de soporte técnico
    SoporteTecnico mesaAyuda;

    // Añadir consultas a la fila
    mesaAyuda.anadirConsulta(C1);
    mesaAyuda.anadirConsulta(C2);
    mesaAyuda.anadirConsulta(C3);

    // Mostrar fila de consultas
    cout << "CONSULTAS PENDIENTES:" << endl;
    mesaAyuda.mostrarConsultas();

    // Atender una consulta
    cout << "\nATENDIENDO CONSULTA..." << endl;
    mesaAyuda.atenderConsulta();

    // Mostrar fila actualizada
    cout << "\nCONSULTAS PENDIENTES:" << endl;
    mesaAyuda.mostrarConsultas();

    return 0;
}
