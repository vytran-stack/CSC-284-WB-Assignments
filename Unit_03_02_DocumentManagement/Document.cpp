#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Document {
private:
    string title;
    unique_ptr<string> content;


public:
    // Constructor 
    Document(const string& t, const string& c) {
        title = t;
        content = make_unique<string>(c);
        cout << "Document \"" << title << "\" created." << endl;
    }
    // Destructor
    ~Document() {
        cout << "Document \"" << title << "\" destroyed." << endl;    
    }
    // show()
    void show() const {
        cout << "Title: " << title << endl;
        cout << "Content: " << *content << endl;
    }

    // edit()
    void edit(const string& newContent) {
        *content = newContent;
    }
};
/*
* Implement helper functions
*/

    unique_ptr<Document> createDocument(const string& t, const string& c) {
    return make_unique<Document>(t, c);
    }

    shared_ptr<Document> createSharedDocument(const string& t, const string& c) {
    return make_shared<Document>(t, c);
    }


/*
* Main 
*/
int main() {
    cout << "=== Unique_ptr demonstration ===" << endl;
    auto doc1 = createDocument("My Unique Doc", "Initial content");
    doc1->show();

    // Transfer ownership
    auto doc1_owner = move(doc1);
    cout << "doc1 no longer owns the document" << endl;

    doc1_owner->edit("Updated content");
    doc1_owner->show();

    cout << endl << "=== Shared_ptr demonstration ===" << endl;
    auto viewer1 = createSharedDocument("Shared Doc", "Shared content");
    viewer1->show();

    {
        auto viewer2 = viewer1;           // share ownership
        viewer2->edit("Edited by viewer");
        viewer1->show();                  // viewer1 sees the updated content
    } // viewer2 goes out of scope, but viewer1 still exists

    cout << "End of main()" << endl;
    return 0;
}
