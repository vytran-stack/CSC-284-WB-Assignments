#ifndef TRUCK_H
#define TRUCK_H

#include "Vehicle.h"

class Truck : public Vehicle {
private:
    double loadCapacityTons{}; // in tons

public:
    Truck();
    Truck(const string& make, const string& model, int year, double mileage,
          double loadCapacityTons);
    ~Truck() override;

    double getLoadCapacityTons() const;
    void setLoadCapacityTons(double tons);

    void displayInfo() const override;
    double getFuelEfficiency() const override; // km per liter
};

#endif // TRUCK_H

