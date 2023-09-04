/*
Hecho por Luis Poveda Gutiérrez
c.2022085302

Tipo de list a usar:
Se utilizará una list doblemente enlazada, ya que estas permiten desplazarse de forma más fácil entre los nodos del array,
así como por la facilidad que representan estas para insertData y eliminar elementos.
*/

#ifndef CLASSLISTA_H
#define CLASSLISTA_H

#include <string>

using namespace std;

class News;

struct News {
    std::string title;
    int relevance;
    News* next;
    News* previous;
};

class doublyLinked {
public:
    doublyLinked();
    doublyLinked();
    void insertData(const std::string& title, int relevance);
    void displayNews();
    void displayMostRelevant();
    void searchByFilter(const std::string& keyword);
    void deleteByFilter(const std::string& keyword);
    void reorderTitle(int Position, int newPosition);

private:
    News* head;
    News* tail;
};

class NewsManager {
public:
    static News* createNews(const std::string& title, int relevance);
    static void deleteNews(News* newsArray);
    static void displayNewsArray(const News* newsArray);
};


#endif //CLASSLISTA_H