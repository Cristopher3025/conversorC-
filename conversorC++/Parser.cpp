#include "Parser.h"
#include <string>


static std::string toLowerManual(const std::string& text) {
    std::string out;
    for (size_t i = 0; i < text.size(); i++) {
        char c = text[i];
        if (c >= 'A' && c <= 'Z') {
            c = char(c - 'A' + 'a');
        }
        out.push_back(c);
    }
    return out;
}


static bool containsWord(const std::string& text, const std::string& word) {
    if (word.size() > text.size()) return false;
    for (size_t i = 0; i + word.size() <= text.size(); i++) {
        bool ok = true;
        for (size_t j = 0; j < word.size(); j++) {
            if (text[i + j] != word[j]) {
                ok = false;
                break;
            }
        }
        if (ok) return true;
    }
    return false;
}


static void extractTwoNumbers(const std::string& text, std::string& n1, std::string& n2) {
    n1 = "";
    n2 = "";
    int found = 0;

    for (size_t i = 0; i < text.size(); i++) {
        char c = text[i];
        if (c >= '0' && c <= '9') {
            std::string num = "";
            while (i < text.size() && text[i] >= '0' && text[i] <= '9') {
                num.push_back(text[i]);
                i++;
            }
            if (found == 0) {
                n1 = num;
                found++;
            }
            else if (found == 1) {
                n2 = num;
                break;
            }
        }
    }
    if (n1 == "") n1 = "0";
    if (n2 == "") n2 = "0";
}

// ---- Traducción principal ----
std::string translateLineToSnippet(const std::string& inputLine) {
    std::string lower = toLowerManual(inputLine);

    // Crear lista
    if (containsWord(lower, "crear lista")) {
        return "int lista[10]; // ejemplo de lista";
    }

    // Crear pila
    if (containsWord(lower, "crear pila")) {
        return "// instancia de pila manual\nStack miPila;";
    }

    // Crear cola
    if (containsWord(lower, "crear cola")) {
        return "// instancia de cola manual\nQueue miCola;";
    }

    // Operaciones aritméticas
    if (containsWord(lower, "sumar")) {
        std::string a, b;
        extractTwoNumbers(lower, a, b);
        return "int resultado = " + a + " + " + b + ";";
    }
    if (containsWord(lower, "restar")) {
        std::string a, b;
        extractTwoNumbers(lower, a, b);
        return "int resultado = " + a + " - " + b + ";";
    }
    if (containsWord(lower, "multiplicar")) {
        std::string a, b;
        extractTwoNumbers(lower, a, b);
        return "int resultado = " + a + " * " + b + ";";
    }
    if (containsWord(lower, "dividir")) {
        std::string a, b;
        extractTwoNumbers(lower, a, b);
        return "int resultado = " + a + " / " + b + ";";
    }

    
    if (containsWord(lower, "imprimir")) {
        return "std::cout << resultado << std::endl;";
    }

    
    return "// instruccion no reconocida";
}

