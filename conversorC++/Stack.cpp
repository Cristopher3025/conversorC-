#include "Stack.h"
#include <iostream>


Stack::Stack()
    : topNode(nullptr)
    , count(0)
{
}


Stack::~Stack()
{
    clear();
}


Stack::Stack(const Stack& other)
    : topNode(nullptr)
    , count(0)
{
    if (!other.topNode) return;

    
    Node* currentOther = other.topNode;
    Node* reversedCopy = nullptr;

    while (currentOther) {
        Node* newNode = new Node(currentOther->data);
        newNode->next = reversedCopy;
        reversedCopy = newNode;
        currentOther = currentOther->next;
    }

    
    while (reversedCopy) {
        push(reversedCopy->data);
        Node* temp = reversedCopy;
        reversedCopy = reversedCopy->next;
        delete temp;
    }
}


Stack& Stack::operator=(const Stack& other)
{
    if (this != &other) {
        clear();
        Stack temp(other);
        while (!temp.empty()) {
            push(temp.pop());
        }
    }
    return *this;
}


void Stack::push(const std::string& value)
{
    Node* newNode = new Node(value);
    newNode->next = topNode;
    topNode = newNode;
    ++count;
}


std::string Stack::pop()
{
    if (!topNode) {
        throw std::underflow_error("Stack is empty");
    }
    Node* removedNode = topNode;
    topNode = topNode->next;
    std::string removedValue = removedNode->data;
    delete removedNode;
    --count;
    return removedValue;
}


std::string Stack::top() const
{
    if (!topNode) {
        throw std::underflow_error("Stack is empty");
    }
    return topNode->data;
}


void Stack::clear()
{
    while (topNode) {
        Node* temp = topNode;
        topNode = topNode->next;
        delete temp;
    }
    count = 0;
}


void Stack::print() const
{
    const Node* currentNode = topNode;
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
