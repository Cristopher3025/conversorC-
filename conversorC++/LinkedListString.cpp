#include "LinkedListString.h"
#include <iostream>

// ----- Constructor: lista vacía -----
LinkedListString::LinkedListString()
    : head(nullptr)
    , tail(nullptr)
    , count(0)
{
}

// ----- Destructor -----
LinkedListString::~LinkedListString()
{
    clear();
}

// ----- Constructor de copia -----
LinkedListString::LinkedListString(const LinkedListString& other)
    : head(nullptr)
    , tail(nullptr)
    , count(0)
{
    Node* currentNode = other.head;
    while (currentNode) {
        pushBack(currentNode->data);
        currentNode = currentNode->next;
    }
}

// ----- Operador de asignación -----
LinkedListString& LinkedListString::operator=(const LinkedListString& other)
{
    if (this != &other) {
        clear();
        Node* currentNode = other.head;
        while (currentNode) {
            pushBack(currentNode->data);
            currentNode = currentNode->next;
        }
    }
    return *this;
}

// ----- Insertar al final -----
void LinkedListString::pushBack(const std::string& value)
{
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
    ++count;
}

// ----- Insertar al inicio -----
void LinkedListString::pushFront(const std::string& value)
{
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
    if (!tail) {
        tail = newNode;
    }
    ++count;
}

// ----- Eliminar del frente -----
std::string LinkedListString::popFront()
{
    if (!head) {
        throw std::underflow_error("LinkedListString is empty");
    }
    Node* removedNode = head;
    head = head->next;
    if (!head) {
        tail = nullptr;
    }
    std::string removedValue = removedNode->data;
    delete removedNode;
    --count;
    return removedValue;
}

// ----- Limpiar lista -----
void LinkedListString::clear()
{
    Node* currentNode = head;
    while (currentNode) {
        Node* nextNode = currentNode->next;
        delete currentNode;
        currentNode = nextNode;
    }
    head = tail = nullptr;
    count = 0;
}

// ----- Imprimir -----
void LinkedListString::print() const
{
    const Node* currentNode = head;
    std::cout << "[";
    bool first = true;
    while (currentNode) {
        if (!first) std::cout << ", ";
        std::cout << currentNode->data;
        first = false;
        currentNode = currentNode->next;
    }
    std::cout << "]\n";
}
