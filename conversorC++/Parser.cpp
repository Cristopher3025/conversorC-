#include "Parser.h"
#include <string>


static std::string toLowerManual(const std::string& text) {
    std::string out;
    for (size_t i = 0; i < text.size(); i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') c = char(c - 'A' + 'a');
        out.push_back(c);
    }
    return out;
}

static bool containsWord(const std::string& text, const std::string& word) {
    if (word.size() > text.size()) return false;
    for (size_t i = 0; i + word.size() <= text.size(); i++) {
        bool ok = true;
        for (size_t j = 0; j < word.size(); j++) {
            if (text[i + j] != word[j]) { ok = false; break; }
        }
        if (ok) return true;
    }
    return false;
}

static void extractTwoNumbers(const std::string& text, std::string& n1, std::string& n2) {
    n1 = ""; n2 = ""; int found = 0;
    for (size_t i = 0; i < text.size(); i++) {
        char c = text[i];
        if (c >= '0' && c <= '9') {
            std::string num = "";
            while (i < text.size() && text[i] >= '0' && text[i] <= '9') {
                num.push_back(text[i]); i++;
            }
            if (found == 0) { n1 = num; found++; }
            else if (found == 1) { n2 = num; break; }
        }
    }
    if (n1 == "") n1 = "0";
    if (n2 == "") n2 = "0";
}


bool usarLista = false;
bool usarPila = false;
bool usarCola = false;


std::string translateLineToSnippet(const std::string& inputLine) {
    std::string lower = toLowerManual(inputLine);

    // Crear lista
    if (containsWord(lower, "crear lista")) {
        usarLista = true;
        return "Lista miLista;";
    }

    // Crear pila
    if (containsWord(lower, "crear pila")) {
        usarPila = true;
        return "Pila miPila;";
    }

    // Crear cola
    if (containsWord(lower, "crear cola")) {
        usarCola = true;
        return "Cola miCola;";
    }

    // Meter resultado en pila
    if (containsWord(lower, "meter resultado en pila")) {
        usarPila = true; // asegura que se inyecte la pila
        return "miPila.push(resultado);";
    }

    // Operaciones aritméticas
    std::string a, b;
    if (containsWord(lower, "sumar")) {
        extractTwoNumbers(lower, a, b);
        return "int resultado = " + a + " + " + b + ";";
    }
    if (containsWord(lower, "restar")) {
        extractTwoNumbers(lower, a, b);
        return "int resultado = " + a + " - " + b + ";";
    }
    if (containsWord(lower, "multiplicar")) {
        extractTwoNumbers(lower, a, b);
        return "int resultado = " + a + " * " + b + ";";
    }
    if (containsWord(lower, "dividir")) {
        extractTwoNumbers(lower, a, b);
        return "int resultado = " + a + " / " + b + ";";
    }

    // Ciclos
    if (containsWord(lower, "ciclo for")) {
        return "for (int i = 0; i < 5; i++) {\n    // acciones en ciclo\n}";
    }
    if (containsWord(lower, "ciclo while")) {
        return "while (resultado < 10) {\n    // acciones en ciclo\n    break;\n}";
    }

    // Condicionales
    if (containsWord(lower, "si no")) {
        return "else {\n    // acciones\n}";
    }
    if (containsWord(lower, "si")) {
        return "if (resultado > 0) {\n    // acciones\n}";
    }

    // Imprimir
    if (containsWord(lower, "imprimir")) {
        return "std::cout << resultado << std::endl;";
    }

    return "// instruccion no reconocida";
}

