#include "Parser.h"
#include "TemplateLibrary.h"

// ----- Helpers locales (manuales) -----
static std::string toLowerCopy2(const std::string& text)
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

// ----- Busca substring de forma manual -----
static int indexOf(const std::string& haystack, const std::string& needle)
{
    if (needle.empty() || haystack.size() < needle.size()) return -1;
    for (unsigned int i = 0; i + needle.size() <= haystack.size(); ++i) {
        bool ok = true;
        for (unsigned int j = 0; j < needle.size(); ++j) {
            if (haystack[i + j] != needle[j]) { ok = false; break; }
        }
        if (ok) return static_cast<int>(i);
    }
    return -1;
}

// ----- Extrae un número simple desde el texto -----
static std::string extractFirstNumber(const std::string& textLower)
{
    std::string number;
    for (unsigned int i = 0; i < textLower.size(); ++i) {
        char c = textLower[i];
        if (c >= '0' && c <= '9') {
            number.push_back(c);
            unsigned int k = i + 1;
            while (k < textLower.size() && textLower[k] >= '0' && textLower[k] <= '9') {
                number.push_back(textLower[k]);
                ++k;
            }
            break;
        }
    }
    if (number.empty()) number = "10"; // valor por defecto
    return number;
}

// ----- Traducción básica por palabras clave → snippet -----
std::string translateLineToSnippet(const std::string& inputLine)
{
    const std::string lower = toLowerCopy2(inputLine);

    // Caso: "crear lista de N ..." → arreglo simple por ahora
    if (indexOf(lower, "crear lista") >= 0) {
        std::string sizeText = extractFirstNumber(lower);
        return makeArrayTemplate("lista1", sizeText);
    }

    // Caso: "pila" → esqueleto de pila
    if (indexOf(lower, "pila") >= 0) {
        return makeStackTemplate("miPila");
    }

    // Caso: "crear clase ... con pila ..."
    if (indexOf(lower, "crear clase") >= 0 && indexOf(lower, "pila") >= 0) {
        return makeClassWithStackTemplate("MiClase", "pilaInterna");
    }

    // Si no se reconoce, devolver cadena vacía
    return "";
}
