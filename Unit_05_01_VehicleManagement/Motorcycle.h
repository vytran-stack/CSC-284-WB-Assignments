#ifndef MOTORCYCLE_H
#define MOTORCYCLE_H

#include "Vehicle.h"

class Motorcycle : public Vehicle {
private:
    bool hasSidecar{};

public:
    Motorcycle();
    Motorcycle(const string& make, const string& model, int year, double mileage,
               bool hasSidecar);
    ~Motorcycle() override;

    bool getHasSidecar() const;
    void setHasSidecar(bool v);

    void displayInfo() const override;
    double getFuelEfficiency() const override; // km per liter
};

#endif // MOTORCYCLE_H
