#pragma once
#include <string>
#include <cstddef>
#include <stdexcept>


class Stack {
private:
    
    struct Node {
        std::string data;
        Node* next;
        Node(const std::string& value) : data(value), next(nullptr) {}
    };

   
    Node* topNode;
    std::size_t count;

public:
   
    Stack();
    ~Stack();
    Stack(const Stack& other);
    Stack& operator=(const Stack& other);

    
    void push(const std::string& value);
    std::string pop();
    std::string top() const;

    
    bool empty() const { return count == 0; }
    std::size_t size() const { return count; }
    void clear();
    void print() const;
};
