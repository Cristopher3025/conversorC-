#pragma once
#include <string>
#include <cstddef>
#include <stdexcept>

class Queue {
private:
    struct Node {
        std::string data;
        Node* next;
        Node(const std::string& value) : data(value), next(nullptr) {}
    };

    Node* frontNode;
    Node* rearNode;
    std::size_t count;

public:
    Queue();
    ~Queue();
    Queue(const Queue& other);
    Queue& operator=(const Queue& other);

    void enqueue(const std::string& value);   // insertar al final
    std::string dequeue();                    // eliminar al frente
    std::string front() const;                // ver el frente

    bool empty() const { return count == 0; }
    std::size_t size() const { return count; }
    void clear();
    void print() const;
};
