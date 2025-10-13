#include "Vehicle.h"
#include <stdexcept>
#include <iomanip>

int Vehicle::vehicleCount = 0;



Vehicle::Vehicle() : make("Unknown"), model("Unknown"), year(2000), mileage(0.0) {
    ++vehicleCount;
}

Vehicle::Vehicle(const string& mk, const string& md, int yr, double mi)
    : make(mk), model(md), year(yr), mileage(mi)      {
    ++vehicleCount;
}

Vehicle::~Vehicle() {
    --vehicleCount;
    cout << "[Vehicle dtor] Destroying " << year << " " << make << " " << model << "\n";
}

string Vehicle::getMake() const { return make; }
string Vehicle::getModel() const { return model; }
int Vehicle::getYear() const { return year; }
double Vehicle::getMileage() const { return mileage; }

void Vehicle::setMake(const string& m) {
    this->make = m;
}
void Vehicle::setModel(const string& m) {
    this->model = m;
}
void Vehicle::setYear(int y) {
    this->year = y;
}
void Vehicle::setMileage(double m) {
    this->mileage = m;
}
void Vehicle::displayInfo() const {
    cout << year << " " << make << " " << model << " | Mileage: " << fixed << setprecision(0)
         << mileage << " km\n";
}
