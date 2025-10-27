#include "Book.h"
using namespace std;

Book::Book(const string& t, const string& a, int y, const string& g)
    : title(t), author(a), year(y), genre(g) {}

void Book::display() const {
    cout << title << " by " << author
         << " (" << year << ") [" << genre << "]\n";
}
