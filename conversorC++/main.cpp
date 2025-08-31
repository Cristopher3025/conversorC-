#include <iostream>
#include "LinkedListString.h"

int main() {
    std::cout << "Prueba LinkedListString\n";

    LinkedListString lst;
    lst.pushBack("hola");
    lst.pushBack("mundo");
    lst.pushFront("hey");

    lst.print(); // [hey, hola, mundo]

    std::string x = lst.popFront();
    std::cout << "popFront: " << x << "\n";
    lst.print(); // [hola, mundo]

    return 0;
}
