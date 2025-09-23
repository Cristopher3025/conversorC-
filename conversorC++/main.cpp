#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include <string>
#include "LinkedListString.h"
#include "Tokenizer.h"
#include "Parser.h"


extern bool usarLista;
extern bool usarPila;
extern bool usarCola;

#define DIRECCION_FUENTE "resources/arial.ttf"

// =================== Plantillas de estructuras ===================

const std::string listaTemplate = R"(
struct NodoLista {
    int data;
    NodoLista* next;
    NodoLista(int v) : data(v), next(nullptr) {}
};

struct Lista {
    NodoLista* head;
    Lista() : head(nullptr) {}
    void add(int v) {
        NodoLista* nuevo = new NodoLista(v);
        nuevo->next = head;
        head = nuevo;
    }
    bool empty() { return head == nullptr; }
};
)";

const std::string pilaTemplate = R"(
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
)";

const std::string colaTemplate = R"(
struct NodoCola {
    int data;
    NodoCola* next;
    NodoCola(int v) : data(v), next(nullptr) {}
};

struct Cola {
    NodoCola* front;
    NodoCola* rear;
    Cola() : front(nullptr), rear(nullptr) {}
    void enqueue(int v) {
        NodoCola* nuevo = new NodoCola(v);
        if (!rear) { front = rear = nuevo; }
        else { rear->next = nuevo; rear = nuevo; }
    }
    void dequeue() {
        if (front) {
            NodoCola* t = front;
            front = front->next;
            if (!front) rear = nullptr;
            delete t;
        }
    }
    bool empty() { return front == nullptr; }
};
)";

// =================== MAIN ===================

int main() {
    std::cout << "===== Conversor Lenguaje Natural a C++ =====\n";

    std::ifstream inputFile("../txt/instrucciones.txt");
    if (!inputFile.is_open()) {
        std::cout << "No se pudo abrir ../txt/instrucciones.txt\n";
        return 1;
    }

    std::ofstream outputFile("../salidas/output.cpp");
    if (!outputFile.is_open()) {
        std::cout << "No se pudo crear ../salidas/output.cpp\n";
        return 1;
    }

    // Cabecera general
    outputFile << "#include <iostream>\n";
    outputFile << "using namespace std;\n\n";

    std::string instruccionesLeidas;
    std::string codigoGenerado;
    std::string line;
    int lineNumber = 1;

    
    std::string snippetsAcumulados;

    while (std::getline(inputFile, line)) {
        instruccionesLeidas += std::to_string(lineNumber) + ": " + line + "\n";

        LinkedListString tokens = tokenize(line);
        std::string snippet = translateLineToSnippet(line);

        if (snippet.empty()) {
            codigoGenerado += "// No se pudo interpretar: " + line + "\n";
        }
        else {
            codigoGenerado += snippet + "\n";
            snippetsAcumulados += "    " + snippet + "\n";
        }

        lineNumber++;
    }

    codigoGenerado += "\n// Archivo 'output.cpp' exportado correctamente.\n";


    if (usarLista) outputFile << listaTemplate << "\n";
    if (usarPila)  outputFile << pilaTemplate << "\n";
    if (usarCola)  outputFile << colaTemplate << "\n";

 
    outputFile << "int main() {\n";
    outputFile << "    int resultado = 0;\n";
    outputFile << snippetsAcumulados;
    outputFile << "    return 0;\n";
    outputFile << "}\n";

    inputFile.close();
    outputFile.close();

    std::cout << "\n===== Fin de la demostracion =====\n";

    
    sf::RenderWindow window(sf::VideoMode(900, 700), "Conversor Lenguaje Natural a C++");
    sf::Font font;
    if (!font.loadFromFile(DIRECCION_FUENTE)) {
        std::cerr << "Error al cargar fuente: " << DIRECCION_FUENTE << std::endl;
    }

    sf::Text label1("Instrucciones (TXT):", font, 20);
    label1.setPosition(20, 20);

    sf::Text textIn(instruccionesLeidas, font, 16);
    textIn.setPosition(20, 60);
    textIn.setFillColor(sf::Color::Blue);

    sf::Text label2("Codigo Generado:", font, 20);
    label2.setPosition(20, 300);

    sf::Text textOut(codigoGenerado, font, 16);
    textOut.setPosition(20, 340);
    textOut.setFillColor(sf::Color::Black);

    while (window.isOpen()) {
        sf::Event ev;
        while (window.pollEvent(ev)) {
            if (ev.type == sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::White);
        window.draw(label1);
        window.draw(textIn);
        window.draw(label2);
        window.draw(textOut);
        window.display();
    }

    return 0;
}


