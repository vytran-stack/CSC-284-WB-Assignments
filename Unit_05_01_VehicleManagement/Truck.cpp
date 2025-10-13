#include "Truck.h"
#include <stdexcept>
#include <iomanip>

Truck::Truck() : Vehicle(), loadCapacityTons(1.0) {
}

Truck::Truck(const string& mk, const string& md, int yr, double mi, double tons)
    : Vehicle(mk, md, yr, mi), loadCapacityTons(tons) {
    if (tons <= 0.0) throw invalid_argument("Load capacity must be positive");
}

Truck::~Truck() {
    cout << "[Truck dtor] " << year << " " << make << " " << model << "\n";
}

double Truck::getLoadCapacityTons() const { return loadCapacityTons; }

void Truck::setLoadCapacityTons(double tons) {
    if (tons <= 0.0) throw invalid_argument("Load capacity must be positive");
    loadCapacityTons = tons;
}

double Truck::getFuelEfficiency() const {
    // Simple model: heavier trucks are less efficient
    // Base 10 km/l then subtract 0.3 per ton, with a lower bound
    double eff = 10.0 - 0.3 * loadCapacityTons;
    if (year < 2010) eff -= 1.0;
    if (eff < 4.0) eff = 4.0;
    return eff;
}

void Truck::displayInfo() const {
    Vehicle::displayInfo();
    cout << "Type: Truck \n Load Capacity: " << fixed << setprecision(1)
         << loadCapacityTons << " tons\n";
    cout << "   Fuel Efficiency: " << fixed << setprecision(2)
         << getFuelEfficiency() << " km/l\n\n";
}
