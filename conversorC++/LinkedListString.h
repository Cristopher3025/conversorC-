#pragma once
#include <string>
#include <cstddef>
#include <stdexcept>

// Lista simplemente enlazada que almacena std::string


class LinkedListString {
private:
    struct Node {
        std::string data;
        Node* next;
        Node(const std::string& d) : data(d), next(nullptr) {}
    };

    Node* head;
    Node* tail;
    std::size_t n;

public:
    LinkedListString();
    ~LinkedListString();

    LinkedListString(const LinkedListString& other);
    LinkedListString& operator=(const LinkedListString& other);

    void pushBack(const std::string& x);
    void pushFront(const std::string& x);
    std::string popFront();
    bool empty() const { return n == 0; }
    std::size_t size() const { return n; }
    void clear();

    void print() const;
};
