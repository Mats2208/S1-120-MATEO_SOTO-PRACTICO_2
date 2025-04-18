#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class LinkedList {
private:
    class Node {
    public:
        T data;
        Node *next;

        Node(const T &value, Node *next = nullptr) : data(value), next(next) {}
    };

    Node *head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        Node *current = head;
        while (current != nullptr) {
            Node *temp = current;
            current = current->next;
            delete temp;
        }
    }

    void pushFront(const T &value) {
        Node *newNode = new Node(value, head);
        head = newNode;
        size++;
    }

    void pushBack(const T &value) {
        Node *newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {

            Node *current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
        size++;
    }

    T at(int index) const {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        Node *current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }

    void remove(int index) {
        if (index < 0 || index >= size) {
            throw out_of_range("Índice fuera de rango");
        }
        if (index == 0) {
            Node *temp = head;
            head = head->next;
            delete temp;
        } else {
            Node *current = head;
            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }
            Node *temp = current->next;
            current->next = temp->next;
            delete temp;
        }
        size--;
    }

    int getSize() const {
        return size;
    }

    void print() const {
        Node *current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    void insert(int index, const T &value) {
        if (index < 0 || index > size) {
            throw out_of_range("Índice fuera de rango");
        }
        if (index == 0) {
            pushFront(value);
        } else {
            Node *current = head;
            for (int i = 0; i < index - 1; ++i) {
                current = current->next;
            }
            Node *newNode = new Node(value, current->next);
            current->next = newNode;
            size++;
        }
    }

    bool existe(T value) const {
        Node *current = head;
        while (current != nullptr) {
            if (current->data == value) {
                return true;
            }
            current = current->next;
        }
        return false;
    }

};

#endif // LINKEDLIST_H