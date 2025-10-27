#include "Library.h"
#include <iostream>

using namespace std;

void Library::addBook(const Book& book) {
    books.push_back(book);
}
 // remove book by title
void Library::remove_book(const string& title) {
    auto new_end = remove_if(books.begin(), books.end(),
                             [&](const Book& b){ 
    return b.title == title; });
    if (new_end != books.end()) {
        books.erase(new_end, books.end());
        cout << "Book removed successfully\n";
    } else {
        cout << "Book not found\n";
    }
}

// find book by title
Book* Library::find_book(const string& title) {
    for (size_t i = 0; i < books.size(); ++i) {
        if (books[i].title == title) {
            books[i].display();
            return &books[i];
        }
    }
    cout << "Book not found\n";
    return nullptr;
}

// find book by title using std::find
Book* Library::find_book_std_find(const string& title) {
    auto it = find_if(books.begin(), books.end(),
                      [&](const Book& b){ return b.title == title; });
    if (it != books.end()) {
        it->display();
        return &(*it);
    } else {
        cout << "Book not found\n";
        return nullptr;
    }
}

// find books by author using iterator
vector<Book> Library::find_books_by_author(const string& author) {
    vector<Book> result;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->author == author) {
            result.push_back(*it);
        }
    }
    return result;
}

// find books by genre using iterator
vector<Book> Library::find_books_by_genre(const string& genre) {
    vector<Book> result;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->genre == genre) {
            result.push_back(*it);
        }
    }
    return result;
}

// display all books using iterator
void Library::display_all_books_iterator() {
    for (auto it = books.begin(); it != books.end(); ++it) {
        it->display();
    }
}

// get books after year using ranges::filter
vector<Book> Library::get_books_after_year(int year) {
    vector<Book> result;
    for (const auto& bk : books // for loop to iterate through the books
                        | std::views::filter([&](const Book& b){ // use std::views::filter to filter the books
                              return b.year > year;
                          })) {
        result.push_back(bk); // add the filtered books to the result
    }
    return result;
}

void Library::sort_by_year_ascending() {
    sort(books.begin(), books.end(), // sort the books by year in ascending order
         [](const Book& a, const Book& b){
             return a.year < b.year; // compare the years of the books
         });
}

void Library::sort_by_year_descending() {
    sort(books.begin(), books.end(), // sort the books by year in descending order
         [](const Book& a, const Book& b){
             return a.year > b.year; // compare the years of the books
         });
}

