#ifndef TRAFFICLIGHT_H
#define TRAFFICLIGHT_H

#include <iostream>
#include <stdexcept>
using namespace std;

/**
 * Class TrafficLight
 * Simulates a traffic light using enum states:
 * RED → GREEN → YELLOW → RED ...
 */
class TrafficLight {
public:
    enum Color { RED, GREEN, YELLOW };

private:
    Color currentColor;

public:
    // Constructor: start at RED
    TrafficLight();

    // Convert enum to string for display
    string getColorName() const;

    // Display current color
    void displayCurrentColor() const;

    // Switch to the next color
    void changeToNextColor();

    // Run simulation for the specified number of steps
    void runSimulation(int steps);
};

#endif
