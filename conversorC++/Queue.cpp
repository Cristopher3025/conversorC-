#include "Queue.h"
#include <iostream>

Queue::Queue() {
    frontNode = nullptr;
    rearNode = nullptr;
    count = 0;
}

Queue::~Queue() {
    clear();
}

Queue::Queue(const Queue& other) {
    frontNode = nullptr;
    rearNode = nullptr;
    count = 0;

    Node* current = other.frontNode;
    while (current) {
        enqueue(current->data);
        current = current->next;
    }
}

Queue& Queue::operator=(const Queue& other) {
    if (this != &other) {
        clear();
        frontNode = nullptr;
        rearNode = nullptr;
        count = 0;

        Node* current = other.frontNode;
        while (current) {
            enqueue(current->data);
            current = current->next;
        }
    }
    return *this;
}

void Queue::enqueue(const std::string& value) {
    Node* newNode = new Node(value);
    if (!rearNode) {
        frontNode = rearNode = newNode;
    }
    else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    ++count;
}

std::string Queue::dequeue() {
    if (!frontNode) {
        throw std::underflow_error("Queue is empty");
    }
    Node* removed = frontNode;
    frontNode = frontNode->next;
    if (!frontNode) rearNode = nullptr;
    std::string value = removed->data;
    delete removed;
    --count;
    return value;
}

std::string Queue::front() const {
    if (!frontNode) {
        throw std::underflow_error("Queue is empty");
    }
    return frontNode->data;
}

void Queue::clear() {
    while (frontNode) {
        Node* temp = frontNode;
        frontNode = frontNode->next;
        delete temp;
    }
    rearNode = nullptr;
    count = 0;
}

void Queue::print() const {
    const Node* current = frontNode;
    std::cout << "[";
    bool first = true;
    while (current) {
        if (!first) std::cout << ", ";
        std::cout << current->data;
        first = false;
        current = current->next;
    }
    std::cout << "]\n";
}
