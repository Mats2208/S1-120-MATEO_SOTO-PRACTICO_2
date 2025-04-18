/*
Atención de pacientes en una clínica
En una clínica, los pacientes llegan a la sala de espera y son atendidos en el orden
en que llegaron. Cada paciente tiene un nombre, edad y motivo de consulta. Los
pacientes son llamados por el médico uno a uno. Crea un programa que gestione la
llegada y atención de los pacientes de manera ordenada.
*/

#include <iostream>
#include "Queue.h"

using namespace std;

class paciente {
private:
    string nombre;
    int edad;
    string motivo;
    public:
    paciente(string _nombre = "Desconocido", int _edad = 0, string _motivo = "Sin Motivo") {
        SetNombre(_nombre);
        SetEdad(_edad);
        SetMotivo(_motivo);
    }

    void SetNombre(string _nombre) {
        nombre = _nombre;
    }

    void SetEdad(int _edad) {
        if (_edad < 0) {
            edad = 0;
            cout <<"La edad es invalida" << endl;
        } else {
            edad = _edad;
        }
    }

    void SetMotivo(string _motivo) {
        motivo = _motivo;
    }

    string GetNombre() {
        return nombre;
    }

    int GetEdad() {
        return edad;
    }

    string GetMotivo() {
        return motivo;
    }

    void ShowData() {
        cout << "Nombre: " << GetNombre() << ", ";
        cout << "Edad: " << GetEdad() << ", ";
        cout << "Motivo: " << GetMotivo() << endl;
    }
};

class clinica {
    private:
    Queue<paciente> pacientes;
    public:

    void anadirPaciente(paciente p) {
        pacientes.push(p);
    }

    paciente mostrarSiguientePaciente() {
        paciente temp;
        pacientes.pop(temp);
        return temp;
    }
    //Lo mejor era usa operator, pero queria hacerlo a mi manera LMAO
    void MostrarPacientes() {
        Queue<paciente> recibir;
        Queue<paciente> respaldo;
        paciente temp;

        while (!pacientes.isEmpty()) {
            pacientes.pop(temp);
            recibir.push(temp);
            respaldo.push(temp);
        }

        int contador = 1;

        while (!recibir.isEmpty()) {
            recibir.pop(temp);
            cout << contador << ". ";
            temp.ShowData();
            contador++;
        }

        while (!respaldo.isEmpty()) {
            respaldo.pop(temp);
            pacientes.push(temp);
        }
    }

};


int main() {
    //crear pacientes
     paciente p1("Mateo", 19, "Me duele la cabeza");
     paciente p2("Lucas", 16, "Tiene dolor muscular");
     paciente p3("Thais", 14, "No tiene energias");

    //Crear Clinica y anadir pacientes
    clinica Mats;
    Mats.anadirPaciente(p1);
    Mats.anadirPaciente(p2);
    Mats.anadirPaciente(p3);

    //Mostrar Pacientes
    cout << "Pacientes actuales:" << endl;
    Mats.MostrarPacientes();

    //Mostrar paciente siguiente
    cout << endl;
    cout << "El paciente siguiente es: " << endl;
    Mats.mostrarSiguientePaciente().ShowData();

    //Pacientes actuales
    cout << endl;
    cout << "Pacientes en cola actual:" << endl;
    Mats.MostrarPacientes();

    return 0;
}
