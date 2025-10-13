#include "Fleet.h"
#include <iostream>
#include <iomanip>

using namespace std;

Fleet::~Fleet() {
    cout << "[Fleet dtor] Deleting all vehicles in fleet...\n";
    for (Vehicle* v : vehicles) {
        delete v; // triggers proper derived dtors due to virtual ~Vehicle
    }
    cout << "[Fleet dtor] Done.\n";
}

void Fleet::addVehicle(Vehicle* v) {
    if (!v) return;
    vehicles.push_back(v);
}

void Fleet::displayAllVehicles() const {
    cout << "\n--- Fleet Vehicles ---\n";
    for (const Vehicle* v : vehicles) {
        v->displayInfo(); // polymorphic
    }
}

double Fleet::getAverageEfficiency() const {
    if (vehicles.empty()) return 0.0;
    double sum = 0.0;
    for (const Vehicle* v : vehicles) sum += v->getFuelEfficiency();
    return sum / static_cast<double>(vehicles.size());
}
