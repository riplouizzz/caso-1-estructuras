/*
Hecho por Luis Poveda Gutiérrez
c.2022085302

Tipo de list a usar:
Se utilizará una list doblemente enlazada, ya que estas permiten desplazarse de forma más fácil entre los nodos del array,
así como por la facilidad que representan estas para insertData y eliminar elementos.
*/

#include "classLista.h"
#include "metodos.cpp"
#include "lista.cpp"
#include <iostream>

using namespace std;


int main() {
    doublyLinked list;

    list.insertData("Title 1", 10);
    list.insertData("Title 2", 8);
    list.insertData("Title 3", 12);

    std::cout << "Display all news:\n";
    list.displayNews();

    std::cout << "\nSearch by filter ('Title'):\n";
    list.searchByFilter("Title");
    list.displayNews();

    std::cout << "\nDelete by filter ('Title 2'):\n";
    list.deleteByFilter("Title 2");
    list.displayNews();
    
    std::cout << "\nReorder Title (position 1, +5):\n";
    list.reorderTitle(1, +5);
    list.displayNews();

    return 0;
}