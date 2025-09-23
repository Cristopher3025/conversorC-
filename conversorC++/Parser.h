#ifndef PARSER_H
#define PARSER_H

#include <string>

// Flags que el main usa para inyectar las plantillas manuales
extern bool usarLista;
extern bool usarPila;
extern bool usarCola;


std::string translateLineToSnippet(const std::string& inputLine);

#endif
