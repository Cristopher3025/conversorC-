#include <iostream>
#include <fstream>
#include <string>
#include "LinkedListString.h"
#include "Tokenizer.h"
#include "Parser.h"

// ----- Programa principal -----
int main() {
    std::cout << "===== Conversor Lenguaje Natural a C++ =====\n";

    // ----- Leer archivo de entrada -----
    std::string fileName = "instrucciones.txt";
    std::ifstream inputFile(fileName);

    if (!inputFile.is_open()) {
        std::cout << "No se pudo abrir el archivo: " << fileName << "\n";
        return 1;
    }

    // ----- Procesar línea por línea -----
    std::string line;
    int lineNumber = 1;

    while (std::getline(inputFile, line)) {
        std::cout << "\nInstruccion " << lineNumber << ": " << line << "\n";

        // 1) Tokenizar (guardar en lista enlazada manual)
        LinkedListString tokens = tokenize(line);
        std::cout << "Tokens: ";
        tokens.print();

        // 2) Parsear → generar snippet C++
        std::string snippet = translateLineToSnippet(line);

        if (snippet.empty()) {
            std::cout << "No se pudo interpretar esta instruccion.\n";
        }
        else {
            std::cout << "Codigo generado:\n" << snippet << "\n";
        }

        lineNumber++;
    }

    inputFile.close();

    std::cout << "\n===== Fin de la demostracion =====\n";
    return 0;
}

