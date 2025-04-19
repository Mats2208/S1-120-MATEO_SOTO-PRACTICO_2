/*
Lavado de platos en un restaurante
En un restaurante, los platos sucios se apilan para ser lavados. Los platos se
colocan en una pila uno encima del otro. Los lavaplatos siempre lavan el plato que
está en la cima. Cada plato tiene un identificador y un tipo (hondo, llano, etc.).
Diseña un programa que gestione el apilado y lavado de los platos
*/

#include <iostream>
#include "Stack.h"

using namespace std;

class plato {
    private:
    int id;
    string type;
    public:

    plato(int _id = 0, string _type = "") {
        SetId(_id);
        SetType(_type);
    }

    void SetId(int _id) {
        if (_id < 0) {
            cout << "Error en la asignacion del ID" << endl;
        } else {
            id = _id;
        }
    }

    int GetId() const {
        return id;
    }

    void SetType(string _type) {
        type = _type;
    }

    string GetType() const {
        return type;
    }

    void MostrarDatos() {
        cout << "Id: " << GetId() << ", ";
        cout << "Type: " << GetType() << endl;
    }
};

//Ahora si uso el operator y no creo una funcion print desde 0
ostream& operator<<(ostream &os, const plato &p) {
    os << "Id: " << p.GetId() << ", Type: " << p.GetType();
    return os;
}


class Lavaplatos {
    private:
    Stack<plato> platos;

    public:
    void anadirPlato(plato p) {
        platos.push(p);
    }

    void MostrarPila() {
        platos.print();
    }

    void LavarPlato() {
        plato temp;
        platos.pop(temp);
        cout << "El plato: '" << temp << "' se esta lavando..." << endl;
    }

    plato MostrarPlato() {
        plato temp;
        platos.peek(temp);
        return temp;
    }
};



int main() {
    //Creo los platos
    plato p1(5, "Hondo");
    plato p2(2, "Plano");
    plato p3(10, "Postres");

    //Creo el lavaplatos
    Lavaplatos lavaplatos;

    //Pusheo los platos al lavaplatos
    lavaplatos.anadirPlato(p1);
    lavaplatos.anadirPlato(p2);
    lavaplatos.anadirPlato(p3);

    //Muestro la pila de platos
    cout << "La pila de platos es:" << endl;
    lavaplatos.MostrarPila();

    //Lavar plato
    cout << "\nPonemos a lavar el siguiente plato" << endl;
    lavaplatos.LavarPlato();

    //Revisamos la pila nuevamente
    cout << "\nLa pila quedo como: " << endl;
    lavaplatos.MostrarPila();
    return 0;
}