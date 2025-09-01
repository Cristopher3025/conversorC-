#pragma once
#include <string>
#include <cstddef>
#include <stdexcept>

// ----- Clase LinkedListString -----
class LinkedListString {
private:
    // ----- Nodo -----
    struct Node {
        std::string data;
        Node* next;
        Node(const std::string& value) : data(value), next(nullptr) {}
    };

    // ----- Atributos -----
    Node* head;
    Node* tail;
    std::size_t count;

public:
    // ----- Constructores y Destructor -----
    LinkedListString();
    ~LinkedListString();
    LinkedListString(const LinkedListString& other);
    LinkedListString& operator=(const LinkedListString& other);

    // ----- Funciones públicas -----
    void pushBack(const std::string& value);
    void pushFront(const std::string& value);
    std::string popFront();
    bool empty() const { return count == 0; }
    std::size_t size() const { return count; }
    void clear();
    void print() const;
};

