#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
using namespace std;

/**
 * Represents a single student's record.
 */
struct Student {
    int id{};
    string name;
    int age{};
    string major;
    string email;
};

/**
 * Manages a collection of students and provides menu-driven operations.
 */
class StudentDatabase {
private:
    vector<Student> students;

    static bool readInt(const string& prompt, int& out);
    static void showMenu();

    void addStudent();
    void displayStudents() const;
    void searchStudent() const;

public:
    void run();
};

#endif
