#include <iostream>
using namespace std;


struct NodoPila {
    int data;
    NodoPila* next;
    NodoPila(int v, NodoPila* n) : data(v), next(n) {}
};

struct Pila {
    NodoPila* top;
    Pila() : top(nullptr) {}
    void push(int v) { top = new NodoPila(v, top); }
    void pop() { if (top) { NodoPila* t = top; top = top->next; delete t; } }
    bool empty() { return top == nullptr; }
};

int main() {
    int resultado = 0;
    Pila miPila;
    int resultado = 7 + 2;
    miPila.push(resultado);
    for (int i = 0; i < 5; i++) {
    // acciones en ciclo
}
    std::cout << resultado << std::endl;
    return 0;
}
