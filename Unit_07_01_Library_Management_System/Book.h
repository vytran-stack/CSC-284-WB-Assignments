#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>
using namespace std;

class Book {
public:
    string title;
    string author;
    int year;
    string genre;

    Book(const string& t, const string& a, int y, const string& g);

    void display() const;
};

#endif
