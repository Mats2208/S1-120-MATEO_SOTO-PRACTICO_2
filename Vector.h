#include <iostream>
#include <stdexcept>

using namespace std;

template <typename T> class Vector {
  protected:
    T *items;
    int size;
    int capacity;

  public:
    Vector(int _capacity = 10) : size(0), capacity(_capacity)
    {
        items = new T[capacity];
    }

    ~Vector()
    {
        delete[] items;
    }

    //Constructores requeridos para ACT 7
    Vector(const Vector& other) : size(other.size), capacity(other.capacity) {
        items = new T[capacity];
        for (int i = 0; i < size; ++i) {
            items[i] = other.items[i];
        }
    }

    // 4. Operador de asignación (NUEVO)
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] items;
            size = other.size;
            capacity = other.capacity;
            items = new T[capacity];
            for (int i = 0; i < size; ++i) {
                items[i] = other.items[i];
            }
        }
        return *this;
    }
    //Nuevos Constructores

    void pushBack(const T &value)
    {
        if (size == capacity)
        {
            resize(capacity * 2);
        }
        items[size++] = value;
    }

    T at(int index)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Índice fuera de rango");
        }
        return items[index];
    }

    void set(int index, T value)
    {
        if (index < 0 || index >= size)
        {
            throw out_of_range("Índice fuera de rango");
        }
        items[index] = value;
    }

    int getSize()
    {
        return size;
    }

    int getCapacity()
    {
        return capacity;
    }

    void resize(int newCapacity)
    {
        if (newCapacity <= capacity)
            return;

        T *newItems = new T[newCapacity];
        for (int i = 0; i < size; i++)
        {
            newItems[i] = items[i];
        }
        delete[] items;
        items = newItems;
        capacity = newCapacity;
    }

    void removeAt(int index) { //Mas facil su implementacion desde aqui (Tarea N6)
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        for (int i = index; i < size - 1; ++i) {
            items[i] = items[i + 1];
        }
        size--;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << items[i] << " | ";
        }
        cout << endl;
    }
};