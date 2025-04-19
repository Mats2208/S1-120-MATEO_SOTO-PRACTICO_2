/*
Registro de acciones en un editor de texto
En un editor de texto, el usuario realiza varias acciones (escribir, borrar, copiar,
pegar). El programa debe permitir que el usuario pueda "deshacer" las acciones
más recientes. Cada acción tiene un tipo y el contenido de la operación. Diseña un
programa que registre las acciones del usuario y permita deshacer las últimas
acciones realizadas
*/

#include <iostream>
#include "Stack.h"

using namespace std;

class Accion {
private:
    string tipo;
    string contenido;
    public:
    Accion(string _tipo = "desconocido" , string _contenido = "") {
        SetTipo(_tipo);
        SetContenido(_contenido);
    }

    void SetTipo(string _tipo) {
        tipo = _tipo;
    }

    void SetContenido(string _contenido) {
        contenido = _contenido;
    }

    string GetTipo() const {
        return tipo;
    }

    string GetContenido() const {
        return contenido;
    }

    void MostrarAccion() {
        cout << "Tipo: " << GetTipo() << ", ";
        cout << "Contenido: " << GetContenido() << endl;
    }
};

ostream& operator<<(ostream &os, const Accion &a) {
    os << "[ " << a.GetTipo() << " -> '" << a.GetContenido() << "' ]";
    return os;
}

class Notepad {
    private:
    Stack<Accion> acciones;

    public:

    void RealizarAccion(Accion p) {
        acciones.push(p);
        cout << "Accion guardada: ";
        p.MostrarAccion();
    }

    void MostrarUltimaAccion() {
        Accion temp;
        acciones.peek(temp);
        cout << "La ultima accion realizada fue: ";
        temp.MostrarAccion();
    }

    void MostrarHistorialAcciones() {
        cout << "HISTORIAL DE ACCIONES" << endl;
        cout << "----------------------------------------------------------------------" << endl;
        acciones.print();
        cout << "----------------------------------------------------------------------" << endl;
    }

    void deshacerAccion() {
        Accion ultima;
        if (acciones.pop(ultima)) {
            cout << "Deshacer: ";
            ultima.MostrarAccion();
        } else {
            cout << "No hay acciones para deshacer";
        }
    }
};

int main() {
    Notepad editor;

    editor.RealizarAccion(Accion("Escribir", "Hola"));
    editor.RealizarAccion(Accion("Borrar", "a"));
    editor.RealizarAccion(Accion("Pegar", "Mundo"));

    cout << "\nAcciones Realizadas" << endl;
    editor.MostrarHistorialAcciones();

    // Deshacer acciones
    cout << "Deshaciendo las acciones" << endl;
    editor.deshacerAccion();
    editor.deshacerAccion();
    editor.deshacerAccion();
    editor.deshacerAccion();  // Extra para probar cuando ya no hay acciones

    return 0;
}