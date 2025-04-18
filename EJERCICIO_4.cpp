/*
Procesar tareas en una impresora
Una impresora recibe trabajos de impresión de diferentes computadoras
conectadas en red. Los trabajos tienen un número de páginas y el nombre del
archivo. Los trabajos de impresión deben procesarse en el orden en que llegaron.
Diseña un programa que gestione la cola de trabajos de impresión y permita saber
cuál es el siguiente trabajo a imprimir.
 */

#include <iostream>
#include "Queue.h"

using namespace std;

class trabajos {
private:
 int page;
 string name;

 public:
 trabajos(string _name = "Desconocido", int _page = 0) {
  SetName(_name);
  SetPage(_page);
 }

 void SetName(string _name) {
  name = _name;
 }

 string GetName() {
  return name;
 }

 void SetPage(int _page) {
   if (_page < 0) {
    cout << "Error en la asignacion de paginas" << endl;
   } else {
    page = _page;
   }
 }

 int GetPage() {
  return page;
 }

 void MostrarDatos() {
  cout << "Nombre del archivo: " << GetName() << endl;
  cout << "Numero de paginas: " << GetPage() << endl;
 }
};

class impresora {
private:
 Queue<trabajos> paginas;

 public:
 void anadirTrabajo(trabajos p) {
  paginas.push(p);
 }

 trabajos siguiente() {
  trabajos recibir;
  paginas.peek(recibir);
  return recibir;
 }

 //Lo mejor era usa operator, pero queria hacerlo a mi manera LMAO
 void ColaDeTrabajos() {
  Queue<trabajos> recibir;
  Queue<trabajos> respaldo;
  trabajos temp;

  while (!paginas.isEmpty()) {
   paginas.pop(temp);
   respaldo.push(temp);
   recibir.push(temp);
  }

  int contador = 1;
  while (!recibir.isEmpty()) {
   cout << contador << ". ";
   recibir.pop(temp);
   temp.MostrarDatos();
   contador++;
  }

  while (!respaldo.isEmpty()) {
   respaldo.pop(temp);
   paginas.push(temp);
  }
 }

 void ImprimirTrabajo() {
  trabajos temp;
  paginas.pop(temp);
  cout << temp.GetName() << " a sido impreso" << endl;
 }
};

int main() {
 trabajos P1("Informe Vector.h", 10);
 trabajos P2("Contabilidad de costos", 5);
 trabajos P3("Calculo II", 2);

 impresora EPSONL5190;
 EPSONL5190.anadirTrabajo(P1);
 EPSONL5190.anadirTrabajo(P2);
 EPSONL5190.anadirTrabajo(P3);

 //Cola de impresion
 cout << "Elementos actuales en la cola" << endl;
 EPSONL5190.ColaDeTrabajos();

 cout << "\nElemento siguiente a imprimir" << endl;
 EPSONL5190.siguiente().MostrarDatos();

 cout << "\nImprimiendo primer elemento en la cola..." << endl;
 EPSONL5190.ImprimirTrabajo();

 cout << "\nLa cola actual es:" << endl;
 EPSONL5190.ColaDeTrabajos();

}