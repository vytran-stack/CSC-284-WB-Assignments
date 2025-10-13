#include "Motorcycle.h"
#include <iomanip>

Motorcycle::Motorcycle() : Vehicle(), hasSidecar(false) {
}

Motorcycle::Motorcycle(const string& mk, const string& md, int yr, double mi, bool sidecar)
    : Vehicle(mk, md, yr, mi), hasSidecar(sidecar) {
}

Motorcycle::~Motorcycle() {
    cout << "[Motorcycle dtor] " << year << " " << make << " " << model << "\n";
}

bool Motorcycle::getHasSidecar() const { return hasSidecar; }
void Motorcycle::setHasSidecar(bool v) { hasSidecar = v; }

double Motorcycle::getFuelEfficiency() const {
    // Motorcycles are efficient. Sidecar reduces efficiency a bit.
    double base = 30.0;
    if (hasSidecar) base -= 5.0;
    if ( year < 2010) base -= 2.0;
    if (base < 12.0) base = 12.0;
    return base;
}

void Motorcycle::displayInfo() const {
    Vehicle::displayInfo();
    cout << "Type: Motorcycle \n Sidecar: " << (hasSidecar ? "Yes" : "No") << "\n";
    cout << "Fuel Efficiency: " << fixed << setprecision(2)
         << getFuelEfficiency() << " km/l\n\n";
}
