#ifndef FLEET_H
#define FLEET_H

#include <vector>
#include "Vehicle.h"

class Fleet {
private:
    std::vector<Vehicle*> vehicles; // owns these pointers

public:
    Fleet() = default;
    ~Fleet(); // deletes vehicles

    void addVehicle(Vehicle* v); // takes ownership
    void displayAllVehicles() const;
    double getAverageEfficiency() const;
    size_t size() const { return vehicles.size(); }
};

#endif // FLEET_H
