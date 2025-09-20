#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

// Structure to represent a Student
struct Student {
    int id;
    string name;
    int age;
    string major;
    string email;
};

// Function to show the main menu
void showMenu() {
    cout << "\n===== Student Records Manager =====\n";
    cout << "1. Add student\n";
    cout << "2. Display all students\n";
    cout << "3. Search student by ID\n";
    cout << "4. Exit\n";
    cout << "Choose an option: ";
}

// Function to add a student to the list
void addStudent(vector<Student> &students) {
    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cin.ignore(); // clear input buffer
    cout << "Enter name: ";
    getline(cin, s.name);
    cout << "Enter age: ";
    cin >> s.age;
    cin.ignore();
    cout << "Enter major: ";
    getline(cin, s.major);
    cout << "Enter email: ";
    getline(cin, s.email);
    students.push_back(s);
    cout << " Student added successfully!\n";
}

// Function to display all students in a table
void displayStudents(const vector<Student> &students) {
    cout << left << setw(5) << "ID"
         << setw(20) << "Name"
         << setw(5) << "Age"
         << setw(15) << "Major"
         << setw(25) << "Email" << endl;
    cout << string(70, '-') << endl;
    for (const auto &s : students) {
        cout << left << setw(5) << s.id
             << setw(20) << s.name
             << setw(5) << s.age
             << setw(15) << s.major
             << setw(25) << s.email << endl;
    }
}

// Function to search for a student by ID
void searchStudent(const vector<Student> &students) {
    int searchId;
    cout << "Enter student ID to search: ";
    cin >> searchId;
    for (const auto &s : students) {
        if (s.id == searchId) {
            cout << "\nFound student:\n";
            cout << "ID: " << s.id << "\n"
                 << "Name: " << s.name << "\n"
                 << "Age: " << s.age << "\n"
                 << "Major: " << s.major << "\n"
                 << "Email: " << s.email << "\n";
            return;
        }
    }
    cout << "Student not found!\n";
}

int main() {
    vector<Student> students;
    int choice;

    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addStudent(students);
                break;
            case 2:
                displayStudents(students);
                break;
            case 3:
                searchStudent(students);
                break;
            case 4:
                cout << "Exiting program...\n";
                break;
            default:
                cout << "Invalid choice, try again!\n";
        }
    } while (choice != 4);

    return 0;
}

