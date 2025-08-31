#include "LinkedListString.h"
#include <iostream>

// Constructor: lista vacía
LinkedListString::LinkedListString() : head(nullptr), tail(nullptr), n(0) {}

// Destructor: limpia toda la memoria
LinkedListString::~LinkedListString() { clear(); }

// Constructor de copia (para duplicar otra lista)
LinkedListString::LinkedListString(const LinkedListString& other)
    : head(nullptr), tail(nullptr), n(0) {
    Node* cur = other.head;
    while (cur) {
        pushBack(cur->data); // copia cada elemento
        cur = cur->next;
    }
}

// Operador de asignación (=)
LinkedListString& LinkedListString::operator=(const LinkedListString& other) {
    if (this != &other) {
        clear();
        Node* cur = other.head;
        while (cur) {
            pushBack(cur->data);
            cur = cur->next;
        }
    }
    return *this;
}

// Insertar al final
void LinkedListString::pushBack(const std::string& x) {
    Node* nd = new Node(x);
    if (!head) { head = tail = nd; }
    else { tail->next = nd; tail = nd; }
    ++n;
}

// Insertar al inicio
void LinkedListString::pushFront(const std::string& x) {
    Node* nd = new Node(x);
    nd->next = head;
    head = nd;
    if (!tail) tail = nd;
    ++n;
}

// Eliminar del frente
std::string LinkedListString::popFront() {
    if (!head) throw std::underflow_error("LinkedListString is empty");
    Node* nd = head;
    head = head->next;
    if (!head) tail = nullptr;
    std::string val = nd->data;
    delete nd;
    --n;
    return val;
}

// Limpiar toda la lista
void LinkedListString::clear() {
    Node* cur = head;
    while (cur) {
        Node* nx = cur->next;
        delete cur;
        cur = nx;
    }
    head = tail = nullptr;
    n = 0;
}

// Imprimir la lista (para depuración)
void LinkedListString::print() const {
    const Node* cur = head;
    std::cout << "[";
    bool first = true;
    while (cur) {
        if (!first) std::cout << ", ";
        std::cout << cur->data;
        first = false;
        cur = cur->next;
    }
    std::cout << "]\n";
}
