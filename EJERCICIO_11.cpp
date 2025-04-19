/*
Cálculo de promedio de notas
En una clase de matemáticas, los alumnos van entregando sus exámenes uno por
uno. El profesor debe calcular el promedio de las notas. Las notas se entregan una
tras otra. Diseña un programa que reciba las notas de los estudiantes y luego
calcule el promedio de todas las notas una vez que se hayan registrado todas.
*/

#include <iostream>
#include "Queue.h"

using namespace std;

class nota {
private:
    string nombre;
    float valor;

public:
    nota(string _nombre = "", float _valor = 0.0) {
        SetNombre(_nombre);
        SetValor(_valor);
    }

    void SetNombre(string _nombre) {
        nombre = _nombre;
    }

    void SetValor(float _valor) {
        valor = _valor;
    }

    string GetNombre() const {
        return nombre;
    }

    float GetValor() const {
        return valor;
    }

    void Mostrar() {
        cout << "Alumno: " << GetNombre() << ", Nota: " << GetValor() << endl;
    }
};

ostream& operator<<(ostream &os, const nota &n) {
    os << "Alumno: " << n.GetNombre() << ", Nota: " << n.GetValor() << endl;
    return os;
}

class Clase {
private:
    Queue<nota> filaNotas;

public:
    void agregarNota(nota n) {
        filaNotas.push(n);
    }

    void mostrarNotas() {
        filaNotas.print();
    }

    void calcularPromedio() {
        if (filaNotas.getSize() == 0) {
            cout << "No hay notas registradas." << endl;
        }

        float suma = 0;
        int total = 0;
        nota temp;

        while (!filaNotas.isEmpty()) {
            filaNotas.pop(temp);
            suma += temp.GetValor();
            total++;
        }

        float prom = suma / total;
        cout << "Promedio de la clase: " << prom << endl;
    }
};

int main() {
    // Crear notas
    nota N1("Mateo", 85.5);
    nota N2("Lucas", 78.0);
    nota N3("Thais", 92.3);

    // Crear clase
    Clase Matematicas;

    // Agregar notas
    Matematicas.agregarNota(N1);
    Matematicas.agregarNota(N2);
    Matematicas.agregarNota(N3);

    // Mostrar todas las notas
    cout << "NOTAS REGISTRADAS:" << endl;
    Matematicas.mostrarNotas();

    // Calcular promedio
    cout << "\nCALCULANDO PROMEDIO..." << endl;
    Matematicas.calcularPromedio();

    return 0;
}
