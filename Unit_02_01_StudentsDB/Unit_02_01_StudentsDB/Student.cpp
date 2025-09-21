#include "Student.h"

// Safely read an integer with validation
bool StudentDatabase::readInt(const string& prompt, int& out) {
    cout << prompt;
    if (!(cin >> out)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cerr << "Invalid input. Please enter an integer.\n";
        return false;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear leftover newline
    return true;
}

// Print the main menu
void StudentDatabase::showMenu() {
    cout << "\n===== Student Records Manager =====\n"
         << "1. Add student\n"
         << "2. Display all students\n"
         << "3. Search student by ID\n"
         << "4. Exit\n"
         << "Choose an option: ";
}

// Add one student
void StudentDatabase::addStudent() {
    Student s;

    while (!readInt("Enter ID: ", s.id)) {}

    cout << "Enter name: ";
    getline(cin, s.name);

    while (!readInt("Enter age: ", s.age) || s.age < 0) {
        if (s.age < 0) cerr << "Age must be non-negative.\n";
    }

    cout << "Enter major: ";
    getline(cin, s.major);

    cout << "Enter email: ";
    getline(cin, s.email);

    students.push_back(s);
    cout << "Student added successfully!\n";
}

// Display all students as a table
void StudentDatabase::displayStudents() const {
    if (students.empty()) {
        cout << "No students to display.\n";
        return;
    }

    cout << left
         << setw(6)  << "ID"
         << setw(22) << "Name"
         << setw(6)  << "Age"
         << setw(18) << "Major"
         << setw(28) << "Email" << '\n';
    cout << string(80, '-') << '\n';

    for (const auto& s : students) {
        cout << left
             << setw(6)  << s.id
             << setw(22) << s.name
             << setw(6)  << s.age
             << setw(18) << s.major
             << setw(28) << s.email << '\n';
    }
}

// Search by ID and print the found record
void StudentDatabase::searchStudent() const {
    int searchId{};
    if (!readInt("Enter student ID to search: ", searchId)) return;

    for (const auto& s : students) {
        if (s.id == searchId) {
            cout << "\nFound student:\n"
                 << "ID: "    << s.id    << '\n'
                 << "Name: "  << s.name  << '\n'
                 << "Age: "   << s.age   << '\n'
                 << "Major: " << s.major << '\n'
                 << "Email: " << s.email << '\n';
            return;
        }
    }
    cout << "Student not found!\n";
}

// Run the interactive menu loop
void StudentDatabase::run() {
    while (true) {
        showMenu();

        int choice{};
        if (!readInt("", choice)) continue;

        switch (choice) {
            case 1: addStudent();      break;
            case 2: displayStudents(); break;
            case 3: searchStudent();   break;
            case 4:
                cout << "Exiting program...\n";
                return;
            default:
                cout << "Invalid choice, try again!\n";
                break;
        }
    }
}
