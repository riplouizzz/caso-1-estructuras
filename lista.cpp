/*
Hecho por Luis Poveda Gutiérrez
c.2022085302

Tipo de list a usar:
Se utilizará una list doblemente enlazada, ya que estas permiten desplazarse de forma más fácil entre los nodos del array,
así como por la facilidad que representan estas para insertData y eliminar elementos.
*/

#include "classLista.h"
#include <iostream>

using namespace std;

News* NewsManager::createNews(const std::string& title, int relevance) {
    News* newNews = new News{title, relevance, nullptr, nullptr};
    return newNews;
}

void NewsManager::deleteNews(News* arrayNews) {
    delete arrayNews;
}

void NewsManager::displayNewsArray(const News* newsArray) {
    std::cout << "Title: " << newsArray->title << "\n";
    std::cout << "Relevance: " << newsArray->relevance << "\n";
}