#include "Library.h"
#include <iostream>
using namespace std;

int main() {
    Library lib;
    lib.addBook(Book("Doraemon", "Fujiko F. Fujio", 1970, "Manga"));
    lib.addBook(Book("Clean Code", "Robert C. Martin", 2008, "Programming"));
    lib.addBook(Book("The Pragmatic Programmer", "Andrew Hunt", 1999, "Programming"));

    cout << "=== Tất cả sách ===\n";
    lib.display_all_books_iterator();

    cout << "\n=== Tìm 'Clean Code' ===\n";
    lib.find_book("Clean Code");

    cout << "\n=== Sách sau năm 2000 ===\n";
    auto recent = lib.get_books_after_year(2000);
    for (auto &b : recent) b.display();

    return 0;
}
