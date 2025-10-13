#ifndef VEHICLE_H
#define VEHICLE_H

#include <string>
#include <iostream>
using namespace std;

class Vehicle {
    protected:
    string make;
    string model;
    int year{};
    double mileage{};

public:
    // Tracks the number of live Vehicle objects
    static int vehicleCount;

    Vehicle();
    Vehicle(const string& make, const string& model, int year, double mileage);
    virtual ~Vehicle(); // virtual for safe polymorphic deletion

    // Accessors
    string getMake() const;
    string getModel() const;
    int getYear() const;
    double getMileage() const;

    // Mutators with validation
    void setMake(const string& m);
    void setModel(const string& m);
    void setYear(int y);
    void setMileage(double m);

    // Polymorphic API
    virtual void displayInfo() const;
    virtual double getFuelEfficiency() const = 0; // pure virtual
};

#endif
 