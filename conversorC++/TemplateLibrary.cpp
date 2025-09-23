#include "TemplateLibrary.h"


static std::string toLowerCopy(const std::string& text)
{
    std::string out;
    out.reserve(text.size());
    for (unsigned int i = 0; i < text.size(); ++i) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') c = static_cast<char>(c - 'A' + 'a');
        out.push_back(c);
    }
    return out;
}


std::string makeArrayTemplate(const std::string& arrayName, const std::string& sizeText)
{
    std::string code;
    code += "// ----- Arreglo de enteros -----\n";
    code += "int " + arrayName + "[" + sizeText + "];\n";
    return code;
}


std::string makeListTemplate(const std::string& listName) {
    std::string code;
    code += "// ====== Definicion de Lista Simple ======\n";
    code += "struct NodeLista {\n";
    code += "    int data;\n";
    code += "    NodeLista* next;\n";
    code += "};\n\n";
    code += "struct Lista {\n";
    code += "    NodeLista* head;\n";
    code += "    Lista() { head = nullptr; }\n\n";
    code += "    void add(int val) {\n";
    code += "        NodeLista* nuevo = new NodeLista{val, nullptr};\n";
    code += "        if (!head) { head = nuevo; return; }\n";
    code += "        NodeLista* tmp = head;\n";
    code += "        while (tmp->next) tmp = tmp->next;\n";
    code += "        tmp->next = nuevo;\n";
    code += "    }\n";
    code += "};\n";
    return code;
}



std::string makeStackTemplate(const std::string& stackName) {
    std::string code;
    code += "// ====== Definicion de Pila ======\n";
    code += "struct NodePila {\n";
    code += "    int data;\n";
    code += "    NodePila* next;\n";
    code += "};\n\n";
    code += "struct Pila {\n";
    code += "    NodePila* top;\n";
    code += "    Pila() { top = nullptr; }\n\n";
    code += "    void push(int val) {\n";
    code += "        NodePila* nuevo = new NodePila{val, top};\n";
    code += "        top = nuevo;\n";
    code += "    }\n\n";
    code += "    int pop() {\n";
    code += "        if (!top) return -1;\n";
    code += "        int val = top->data;\n";
    code += "        NodePila* tmp = top;\n";
    code += "        top = top->next;\n";
    code += "        delete tmp;\n";
    code += "        return val;\n";
    code += "    }\n\n";
    code += "    bool isEmpty() { return top == nullptr; }\n";
    code += "};\n";
    return code;
}



std::string makeClassWithStackTemplate(const std::string& className, const std::string& stackFieldName)
{
    std::string code;
    code += "// ----- Clase con pila interna -----\n";
    code += "class " + className + " {\n";
    code += "private:\n";
    code += "    // TODO: reemplazar por tu pila manual real\n";
    code += "    // Stack " + stackFieldName + ";\n";
    code += "public:\n";
    code += "    " + className + "() {}\n";
    code += "    void pushItem(/*tipo x*/) { /* " + stackFieldName + ".push(x); */ }\n";
    code += "    void popItem() { /* " + stackFieldName + ".pop(); */ }\n";
    code += "};\n";
    return code;
}

std::string makeQueueTemplate(const std::string& queueName) {
    std::string code;
    code += "// ====== Definicion de Cola ======\n";
    code += "struct NodeCola {\n";
    code += "    int data;\n";
    code += "    NodeCola* next;\n";
    code += "};\n\n";
    code += "struct Cola {\n";
    code += "    NodeCola* front;\n";
    code += "    NodeCola* rear;\n";
    code += "    Cola() { front = rear = nullptr; }\n\n";
    code += "    void enqueue(int val) {\n";
    code += "        NodeCola* nuevo = new NodeCola{val, nullptr};\n";
    code += "        if (!rear) { front = rear = nuevo; return; }\n";
    code += "        rear->next = nuevo;\n";
    code += "        rear = nuevo;\n";
    code += "    }\n\n";
    code += "    int dequeue() {\n";
    code += "        if (!front) return -1;\n";
    code += "        int val = front->data;\n";
    code += "        NodeCola* tmp = front;\n";
    code += "        front = front->next;\n";
    code += "        if (!front) rear = nullptr;\n";
    code += "        delete tmp;\n";
    code += "        return val;\n";
    code += "    }\n\n";
    code += "    bool isEmpty() { return front == nullptr; }\n";
    code += "};\n";
    return code;
}

