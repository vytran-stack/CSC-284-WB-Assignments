#include "TrafficLight.h"

// Constructor
TrafficLight::TrafficLight() : currentColor(RED) {}

// Convert enum to string
string TrafficLight::getColorName() const {
    switch (currentColor) {
        case RED: return "Red";
        case GREEN: return "Green";
        case YELLOW: return "Yellow";
        default:
            throw runtime_error("Invalid traffic light state!");
    }
}

// Display current color
void TrafficLight::displayCurrentColor() const {
    cout << getColorName() << endl;
}

// Switch to the next color
void TrafficLight::changeToNextColor() {
    if (currentColor == YELLOW)
        currentColor = RED;
    else
        currentColor = static_cast<Color>(currentColor + 1);
}

// Run simulation
void TrafficLight::runSimulation(int steps) {
    for (int i = 0; i < steps; i++) {
        displayCurrentColor();
        changeToNextColor();
    }
}

