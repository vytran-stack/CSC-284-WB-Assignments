#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include <string>
#include <ranges>
#include <algorithm>
#include "Book.h"
using namespace std;

class Library {
private:
    vector<Book> books;

public:
    void addBook(const Book& book);

    void remove_book(const string& title);

    Book* find_book(const string& title); 

    Book* find_book_std_find(const string& title); 

    vector<Book> find_books_by_author(const string& author); 
    vector<Book> find_books_by_genre(const string& genre);   

    void display_all_books_iterator();

    vector<Book> get_books_after_year(int year);
    void sort_by_year_ascending();
    void sort_by_year_descending();
};

#endif
