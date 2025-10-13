#include <iostream>
#include <iomanip>
#include "Fleet.h"
#include "Car.h"
#include "Truck.h"
#include "Motorcycle.h"
using namespace std;

int main() {
    cout << "Vehicle Management System\n";
    cout << "\n";

    Fleet fleet;

    try {
        // Create several vehicles dynamically and add to fleet
        fleet.addVehicle(new Car("Toyota", "Corolla", 2020, 20000, 4, false));
        fleet.addVehicle(new Truck("Volvo", "FH16", 2018, 80000, 18.0));
        fleet.addVehicle(new Motorcycle("Honda", "CBR600", 2021, 5000, false));
        fleet.addVehicle(new Car("Tesla", "Model 3", 2022, 15000, 4, true));

        // Show all
        fleet.displayAllVehicles();

        // Show totals
        cout << "----------------------------------\n";
        cout << "Total vehicles: " << Vehicle::vehicleCount << "\n";
        cout << "Average fuel efficiency: " << fixed << setprecision(2)
             << fleet.getAverageEfficiency() << " km/l\n\n";
        cout << "----------------------------------\n";
    } catch (const exception& ex) {
        cerr << "Error: " << ex.what() << "\n";
    }

    cout << "Program ending... destructors will now be called automatically.\n";
    // Fleet destructor will delete vehicles, then Vehicle and derived destructors run
    return 0;
}
