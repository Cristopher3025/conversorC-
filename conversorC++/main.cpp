#include <iostream>
#include <fstream>
#include <string>
#include "LinkedListString.h"
#include "Tokenizer.h"
#include "Parser.h"
#include "Stack.h"
#include "Queue.h"

int main() {
    std::cout << "===== Conversor Lenguaje Natural a C++ =====\n";

    // Archivo de entrada (instrucciones en lenguaje natural)
    std::ifstream inputFile("../txt/instrucciones.txt");
    if (!inputFile.is_open()) {
        std::cout << "No se pudo abrir ../txt/instrucciones.txt\n";
        return 1;
    }

    // Archivo de salida (código C++ generado)
    std::ofstream outputFile("../salidas/output.cpp");
    if (!outputFile.is_open()) {
        std::cout << "No se pudo crear ../salidas/output.cpp\n";
        return 1;
    }

    // Cabecera básica del archivo C++
    outputFile << "#include <iostream>\n";
    outputFile << "using namespace std;\n\n";
    outputFile << "int main() {\n";

    std::string line;
    int lineNumber = 1;

    while (std::getline(inputFile, line)) {
        std::cout << "\nInstruccion " << lineNumber << ": " << line << "\n";

        // Tokenizar con tu lista enlazada
        LinkedListString tokens = tokenize(line);
        std::cout << "Tokens: ";
        tokens.print();

        // Parsear a código
        std::string snippet = translateLineToSnippet(line);

        if (snippet.empty()) {
            std::cout << "No se pudo interpretar esta instruccion.\n";
        }
        else {
            std::cout << "Codigo generado:\n" << snippet << "\n";
            outputFile << "    " << snippet << "\n"; // escribe en ../salidas/output.cpp
        }

        lineNumber++;
    }

    // Cierre del main en output.cpp
    outputFile << "    return 0;\n";
    outputFile << "}\n";

    inputFile.close();
    outputFile.close();

    std::cout << "\n===== Fin de la demostracion =====\n";
    std::cout << "Archivo '../salidas/output.cpp' generado.\n";

    return 0;
}


