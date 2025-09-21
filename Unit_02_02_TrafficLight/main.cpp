#include <iostream>
using namespace std;
#include "TrafficLight.h"

int main() {
    int numCycles;

    cout << "Enter number of steps to simulate: ";
    cin >> numCycles;

    TrafficLight light;
    light.runSimulation(numCycles);

    return 0;
}
