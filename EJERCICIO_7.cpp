/*
Control de inventario de productos perecederos
En un supermercado, los productos perecederos, como la leche, se almacenan en
cajas. Cada caja tiene una fecha de vencimiento y cantidad de unidades. Las cajas
se colocan en una estantería especial donde se deben sacar los productos más
antiguos antes de utilizar los más nuevos para evitar que se venzan. Diseña un
programa que gestione este inventario de productos perecederos.
*/

#include <iostream>
#include "Queue.h"

using namespace std;

class Caja {
private:
    int dia;
    int mes;
    int anio;
    int cantidad;
    public:
    Caja(int _dia = 0, int _mes = 0, int _anio = 0, int _cantidad = 0) {
        SetDia(_dia);
        SetMes(_mes);
        SetAnio(_anio);
        SetCantidad(_cantidad);
    }

    void SetDia(int _dia) {
        if (_dia < 0) {
            cout << "Error en el DIA introducido" << endl;
        } else {
            dia = _dia;
        }
    }
    void SetMes(int _mes) {
        if (_mes < 0) {
            cout << "Error en el MES introducido" << endl;
        } else {
            mes = _mes;
        }
    }

    void SetAnio(int _anio) {
        if (_anio < 0) {
            cout << "Error en el ANIO introducido" << endl;
        } else {
            anio = _anio;
        }
    }

    void SetCantidad(int _cantidad) {
        if (_cantidad < 0) {
            cout << "Error en el CANTIDAD introducido" << endl;
        } else {
            cantidad = _cantidad;
        }
    }

    int GetDia() const {
        return dia;
    }

    int GetMes() const{
        return mes;
    }

    int GetAnio() const{
        return anio;
    }

    int GetCantidad() const{
        return cantidad;
    }

    void mostrarDatos() {
        cout << "(DD/MM/AAAA)  (" << GetDia() << "/" << GetMes() << "/" << GetAnio() << ")"<<endl;
    }
};

ostream& operator<<(ostream &os, const Caja &c) {
    os << endl;
    cout << "(DD/MM/AAAA)  (" << c.GetDia() << "/" << c.GetMes() << "/" << c.GetAnio() << ")"<<endl;
    cout << "Cantidad de Stock en el paquete: " << c.GetCantidad() << endl;
    return os;
}
class inventario {
private:
    Queue<Caja> estanteria;

public:
    void anadirCaja(Caja P) {
        estanteria.push(P);
    }

    Caja MasCercanoAvencer() {
        Caja temp;
        estanteria.pop(temp);
        return temp;
    }

    void MostrarInvetario() {
        estanteria.print();
    }
};

int main() {
    //inventario de Leche
    //Crear Cajas
    Caja Leche1(10, 2,2025, 20);
    Caja Leche2(15, 2,2025, 15);
    Caja Leche3(17, 3,2025, 10);
    Caja Leche4(23, 4,2025, 10);
    Caja Leche5(04, 5,2025, 30);


    inventario leche;

    //Pushear Cajas
    leche.anadirCaja(Leche1);
    leche.anadirCaja(Leche2);
    leche.anadirCaja(Leche3);
    leche.anadirCaja(Leche4);
    leche.anadirCaja(Leche5);

    //Mostrar inventario FIFO (First in First out)
    cout << "Inventario actual" << endl;
    leche.MostrarInvetario();


    cout << "Sacando la caja mas antigua" << endl;
    cout << "---------------------------------" << endl;
    leche.MasCercanoAvencer().mostrarDatos();
    cout << "---------------------------------" << endl;

    cout << "\ninventario actual" << endl;
    leche.MostrarInvetario();
    return 0;
}