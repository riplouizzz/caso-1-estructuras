/*
Hecho por Luis Poveda Gutiérrez
c.2022085302

Tipo de list a usar:
Se utilizará una list doblemente enlazada, ya que estas permiten desplazarse de forma más fácil entre los nodos del array,
así como por la facilidad que representan estas para insertData y eliminar elementos.
*/

#include "classLista.h"
#include "lista.cpp"
#include <vector>
#include <iostream>
#include <algorithm>
#include <nlohmann/json.hpp>

using namespace std;
using json = nlohmann::json;

doublyLinked::doublyLinked() : head(nullptr), tail(nullptr) {}

doublyLinked::~doublyLinked() {
    News* current = head;
    while (current) {
        News* next = current->next;
        delete current;
        current = next;
    }
}

void doublyLinked::insertData(const std::string& title, int relevance) {
        News* newNews = new News{title, relevance, nullptr, nullptr};

    if (!head) {
        head = newNews;
        tail = newNews;
    } else {
        tail->next = newNews;
        newNews->previous = tail;
        tail = newNews;
    }
}

void doublyLinked::displayNews() {
    std::vector<News> arrangedNews;
    for (News* current = head; current; current = current->next) {
        arrangedNews.push_back(*current);
    }

    std::sort(arrangedNews.begin(), arrangedNews.end(), [](const News& a, const News& b) {
        return a.relevance > b.relevance;
    });

    for (int i = 0; i < arrangedNews.size(); ++i) {
        std::cout << "Position " << (i + 1) << ": " << arrangedNews[i].title << " (relevance: " << arrangedNews[i].relevance << ")\n";
    }
}

void doublyLinked::displayMostRelevant() {
    std::vector<News> arrangedNews;
    for (News* current = head; current; current = current->next) {
        arrangedNews.push_back(*current);
    }

    std::sort(arrangedNews.begin(), arrangedNews.end(), [](const News& a, const News& b) {
        return a.relevance > b.relevance;
    });

    int numNews = std::min(5, static_cast<int>(arrangedNews.size()));
    for (int i = 0; i < numNews; ++i) {
        std::cout << "Position " << (i + 1) << ": " << arrangedNews[i].title << " (relevance: " << arrangedNews[i].relevance << ")\n";
    }
}

void doublyLinked::searchByFilter(const std::string& keyword) {
    std::vector<std::string> words;
    std::istringstream iss(keyword);
    std::string word;
    
    while (std::getline(iss, word, ',')) {
        words.push_back(word);
    }

    News* current = head;
    while (current) {
        bool containsKeyword = false;
        for (const std::string& word : words) {
            if (current->title.find(word) != std::string::npos) {
                containsKeyword = true;
                break;
            }
        }
        if (!containsKeyword) {
            News* deleteData = current;
            if (deleteData->previous) {
                deleteData->previous->next = deleteData->next;
            } else {
                head = deleteData->next;
            }
            if (deleteData->next) {
                deleteData->next->previous = deleteData->previous;
            } else {
                tail = deleteData->previous;
            }
            delete deleteData;
            current = deleteData->next;
        } else {
            current = current->next;
        }
    }
}

void doublyLinked::searchByFilter(const std::string& keyword) {
    std::string keywords = keyword;
    std::vector<std::string> words;
    std::istringstream iss(keywords);
    std::string word;
    
    while (std::getline(iss, word, ',')) {
        words.push_back(word);
    }

    News* current = head;
    while (current) {
        bool containsKeyword = false;
        for (const std::string& word : words) {
            if (current->title.find(word) != std::string::npos) {
                containsKeyword = true;
                break;
            }
        }
        if (!containsKeyword) {
            News* deleteData = current;
            if (deleteData->previous) {
                deleteData->previous->next = deleteData->next;
            } else {
                head = deleteData->next;
            }
            if (deleteData->next) {
                deleteData->next->previous = deleteData->previous;
            } else {
                tail = deleteData->previous;
            }
            delete deleteData;
            current = deleteData->next;
        } else {
            current = current->next;
        }
    }
}

void doublyLinked::deleteByFilter(const std::string& keyword) {
    std::vector<std::string> keywords;
    std::istringstream iss(keyword);
    std::string word;
    
    while (std::getline(iss, word, ',')) {
        keywords.push_back(word);
    }

    News* current = head;
    while (current) {
        bool containsKeyword = false;
        for (const std::string& word : keywords) {
            if (current->title.find(word) != std::string::npos) {
                containsKeyword = true;
                break;
            }
        }
        if (containsKeyword) {
            News* deleteData = current;
            if (deleteData->previous) {
                deleteData->previous->next = deleteData->next;
            } else {
                head = deleteData->next;
            }
            if (deleteData->next) {
                deleteData->next->previous = deleteData->previous;
            } else {
                tail = deleteData->previous;
            }
            delete deleteData;
            current = deleteData->next;
        } else {
            current = current->next;
        }
    }
}

void doublyLinked::reorderTitle(int position, int newPosition) {
    if (position >= 1 && position <= newsArray.size()) {
        News* current = head;
        int i = 1;
        while (current && i < position) {
            current = current->next;
            i++;
        }
        if (current) {
            current->relevance += newPosition;
            if (newPosition > 0) {
                while (current->previous && current->relevance > current->previous->relevance) {
                    std::swap(current->relevance, current->previous->relevance);
                    std::swap(current->title, current->previous->title);
                    current = current->previous;
                }
            } else {
                while (current->next && current->relevance < current->next->relevance) {
                    std::swap(current->relevance, current->next->relevance);
                    std::swap(current->title, current->next->title);
                    current = current->next;
                }
            }
        }
    }
}

void doublyLinked::addTitle(const std::string& title, int relevance) {
    News* newNews = new News(title, relevance);
    newNews->next = head;
    if (head) {
        head->previous = newNews;
    }
    head = newNews;
    newNews->previous = nullptr;
}