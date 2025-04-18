#include <iostream>
#include "Stack.h"

using namespace std;

class Book{
  private:
    string title;
    string Author;
    string editorial;

    public:
      Book(string _title = "", string _author = "", string _editorial = ""){
        SetTitle(_title);
        SetAuthor(_author);
        SetEditorial(_editorial);
      }

      void SetTitle(string _title){
        title = _title;
      }

      string GetTitle() const{
        return title;
      }

      void SetAuthor(string _author){
        Author = _author;
      }

      string GetAuthor() const{
        return Author;
      }

      void SetEditorial(string _editorial){
        editorial = _editorial;
      }

      string GetEditorial() const{
        return editorial;
      }
};

ostream& operator<<(ostream &os, const Book &book) {
  os << "Titulo: " << book.GetTitle()
     << ", Autor: " << book.GetAuthor()
     << ", Editorial: " << book.GetEditorial();
  return os;
}

class Temp{
  private:
    Stack<Book> Libreria;

   public:
     void addBook(Book L1){
       Libreria.push(L1);
     }

  Book getTop() {
       Book tope;
       if(Libreria.pop(tope)){
         return tope;
       } else {
         cout << "No hay valores a sacar" << endl;
       }
     }

    void MostrarTemporal() {
       Libreria.print();
     }

};

int main() {
  cout << "Recepcion y administracion de libros donados" << endl;

  Temp LibreriaTemporal;

  Book Libro1("Cien Anios de Soledad", "Gabriel Garcia Marquez", "Sudamericana");
  LibreriaTemporal.addBook(Libro1);

  Book Libro2("El Principito", "Antoine de Saint-Exupery", "Reynal & Hitchcock");
  LibreriaTemporal.addBook(Libro2);

  Book Libro3("1984", "George Orwell", "Secker & Warburg");
  LibreriaTemporal.addBook(Libro3);

  cout << "Contenido actual del stack:\n";
  LibreriaTemporal.MostrarTemporal();

  cout << "Sacando el ultimo libro ingresado:\n";
  Book extraido = LibreriaTemporal.getTop();
  cout << extraido << endl;

  cout << "Contenido del stack actualizado:\n";
  cout << endl;
  LibreriaTemporal.MostrarTemporal();

  return 0;
}