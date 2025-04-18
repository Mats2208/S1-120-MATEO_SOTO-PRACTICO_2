/*
Gestión de inventario en una tienda
En una tienda de ropa, los empleados reciben paquetes con ropa que deben ser
almacenados temporalmente. Los paquetes tienen un identificador único y el tipo
de prenda que contienen (camisas, pantalones, etc.). Los paquetes se colocan en
el almacén en el orden en que llegan, pero deben ser sacados del almacén en el
mismo orden para evitar confusiones. Crea un programa que gestione la recepción
y salida de los paquetes
*/

#include <iostream>
#include "Queue.h"

using namespace std;

class Package {
private:
    int id;
    string type;
    public:
    Package(int _id = 0, string _type = "") {
        SetId(_id);
        SetType(_type);
    }

    void SetId(int _id) {
        if (_id < 0) {
            cout << "El numero es invalido" << endl;
        } else {
            id = _id;
        }
    }

    int GetId() {
        return id;
    }

    void SetType(string _type) {
        type = _type;
    }

    string GetType() {
        return type;
    }

    void MostrarDatosUnitarios() {
        cout << "Id: " << GetId() << " ";
        cout << "Type: " << GetType() << endl;
    }
};

class inventory {
private:
    Queue<Package> Stage;

public:
    void anadirElemento(Package NewP) {
        Stage.push(NewP);
    }

    Package tomaDeElemento() {
        Package recibir;
        Stage.pop(recibir);
        return recibir;
    }
    Package muestraDeElemento() {
        Package recibir;
        Stage.peek(recibir);
        return recibir;
    }

    //Lo mejor era usa operator, pero queria hacerlo a mi manera LMAO
    void MostrarDatos() {
        Queue<Package> recibir;
        Queue<Package> respaldo;
        Package temp;

        while (!Stage.isEmpty()) {
            Stage.pop(temp);
            recibir.push(temp);
            respaldo.push(temp);
        }

        while (!recibir.isEmpty()) {
            recibir.pop(temp);
            temp.MostrarDatosUnitarios();
        }

        while (!respaldo.isEmpty()) {
            respaldo.pop(temp);
            Stage.push(temp);
        }
    }

};

int main() {
    //Crear paquetes
    Package Objeto1(1, "Camisa");
    Package Objeto2(2, "Pantalones");
    Package Objeto3(3, "Shorts");
    Package Objeto4(4, "Blusas");
    Package Objeto5(5, "Poleras");

    //Crear tienda
    inventory tienda;
    tienda.anadirElemento(Objeto1);
    tienda.anadirElemento(Objeto2);
    tienda.anadirElemento(Objeto3);
    tienda.anadirElemento(Objeto4);
    tienda.anadirElemento(Objeto5);

    //Visualizar la Tienda
    tienda.MostrarDatos();

    //Peek del primer elemento
    cout << "El primer elemento en ser anadido es: ";
    tienda.muestraDeElemento().MostrarDatosUnitarios();

    //Pop (toma) del primer elemento
    cout << "El primer elemento en ser anadido es tomado de la Queue: ";
    tienda.tomaDeElemento().MostrarDatosUnitarios();

    //Queue luego de la toma del frontElement
    cout << "Queue actual" << endl;
    tienda.MostrarDatos();
}