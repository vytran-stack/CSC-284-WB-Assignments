#include "Car.h"
#include <stdexcept>
#include <iomanip>

Car::Car() : Vehicle(), numDoors(4), isElectric(false) {
}

Car::Car(const string& mk, const string& md, int yr, double mi,
         int doors, bool electric)
    : Vehicle(mk, md, yr, mi), numDoors(doors), isElectric(electric) {
    if (doors <= 0) throw invalid_argument("Number of doors must be positive");
}

Car::~Car() {
    cout << "[Car dtor] " << year << " " << make << " " << model << "\n";
}

int Car::getNumDoors() const { return numDoors; }
bool Car::getIsElectric() const { return isElectric; }

void Car::setNumDoors(int d) {
    if (d <= 0) throw invalid_argument("Number of doors must be positive");
    numDoors = d;
}

void Car::setIsElectric(bool e) { isElectric = e; }

double Car::getFuelEfficiency() const {
    // Simple sample model:
    // Electric -> 0 km/l in this sample format
    // Otherwise base around 14 to 18 depending on doors and age
    if (isElectric) return 0.0;
    double base = 16.0;
    if (numDoors > 4) base -= 1.0;
    if (year < 2010) base -= 1.0;
    return base > 8.0 ? base : 8.0;
}

void Car::displayInfo() const {
    Vehicle::displayInfo();
    cout << "Type: Car \n  Doors: " << numDoors
         << "\n   Electric: " << (isElectric ? "Yes" : "No") << "\n";
    cout << "Fuel Efficiency: " << fixed << setprecision(2)
         << getFuelEfficiency() << " km/l\n\n";
}
