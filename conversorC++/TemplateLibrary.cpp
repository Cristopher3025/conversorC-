#include "TemplateLibrary.h"

// ----- toLower manual -----
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

// ----- Arreglo simple -----
std::string makeArrayTemplate(const std::string& arrayName, const std::string& sizeText)
{
    std::string code;
    code += "// ----- Arreglo de enteros -----\n";
    code += "int " + arrayName + "[" + sizeText + "];\n";
    return code;
}

// ----- Lista (esqueleto) -----
std::string makeListTemplate(const std::string& listName)
{
    std::string code;
    code += "// ----- Esqueleto de lista (manual) -----\n";
    code += "/* TODO: implementar estructura lista \"" + listName + "\" usando nodos y punteros */\n";
    return code;
}

// ----- Pila (esqueleto) -----
std::string makeStackTemplate(const std::string& stackName)
{
    std::string code;
    code += "// ----- Esqueleto de pila (manual) -----\n";
    code += "/* TODO: implementar pila \"" + stackName + "\" con nodos o arreglo circular */\n";
    code += "/* Operaciones: push, pop, top, empty */\n";
    return code;
}

// ----- Clase con pila interna -----
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
