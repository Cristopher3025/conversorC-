#pragma once
#include <string>

// ----- TemplateLibrary: generadores de snippets de código -----


// ----- Plantillas básicas -----
std::string makeArrayTemplate(const std::string& arrayName, const std::string& sizeText);
std::string makeListTemplate(const std::string& listName);
std::string makeStackTemplate(const std::string& stackName);

// ----- Plantillas combinadas -----
std::string makeClassWithStackTemplate(const std::string& className, const std::string& stackFieldName);
