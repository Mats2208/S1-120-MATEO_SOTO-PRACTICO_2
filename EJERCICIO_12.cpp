/*
Revisión de documentos en una oficina
En una oficina, los empleados reciben documentos para revisión, los cuales se
apilan en una bandeja en el orden en que llegan. Cada documento tiene un título y
una fecha de recepción. Los documentos deben ser revisados empezando por el
último que llegó. Diseña un programa que permita gestionar el apilado de los
documentos y su revisión en el orden correcto.
*/

#include <iostream>
#include "Stack.h"

using namespace std;

class documento {
private:
    string titulo;
    string fecha;

public:
    documento(string _titulo = "", string _fecha = "") {
        SetTitulo(_titulo);
        SetFecha(_fecha);
    }

    void SetTitulo(string _titulo) {
        titulo = _titulo;
    }

    void SetFecha(string _fecha) {
        fecha = _fecha;
    }

    string GetTitulo() const {
        return titulo;
    }

    string GetFecha() const {
        return fecha;
    }

    void Mostrar() {
        cout << "Titulo: " << GetTitulo() << ", Fecha: " << GetFecha() << endl;
    }
};

ostream& operator<<(ostream &os, const documento &d) {
    os << "Titulo: " << d.GetTitulo() << ", Fecha: " << d.GetFecha() << endl;
    return os;
}

class Oficina {
private:
    Stack<documento> bandeja;

public:
    void agregarDocumento(documento d) {
        bandeja.push(d);
    }

    void mostrarBandeja() {
        bandeja.print();
    }

    void revisarDocumento() {
        documento temp;
        if (bandeja.pop(temp)) {
            cout << "Revisando documento: " << temp.GetTitulo() << ", recibido el " << temp.GetFecha() << endl;
        } else {
            cout << "No hay documentos para revisar." << endl;
        }
    }
};

int main() {
    documento D1("Informe Anual", "2025-04-01");
    documento D2("Contrato Cliente", "2025-04-10");
    documento D3("Renuncia de Mateo", "2025-04-15");

    Oficina oficina;

    oficina.agregarDocumento(D1);
    oficina.agregarDocumento(D2);
    oficina.agregarDocumento(D3);

    cout << "DOCUMENTOS EN BANDEJA:" << endl;
    oficina.mostrarBandeja();

    cout << "\nREVISANDO DOCUMENTOS..." << endl;
    oficina.revisarDocumento();
    oficina.revisarDocumento();

    cout << "\nDOCUMENTOS RESTANTES:" << endl;
    oficina.mostrarBandeja();

    return 0;
}
