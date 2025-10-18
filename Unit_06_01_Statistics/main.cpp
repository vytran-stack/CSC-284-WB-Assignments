#include <iostream>
#include <iomanip>
#include <vector>
#include "Statistics.h"


int main() {
    Statistics<int> intStats;
    intStats.addValue(10);
    intStats.addValue(20);
    intStats.addValue(30);

    Statistics<double> doubleStats;
    doubleStats.addValue(3.14);
    doubleStats.addValue(2.71);
    doubleStats.addValue(4.5);

    std::cout << "Int Stats: Min = " << intStats.getMin()
              << ", Max = " << intStats.getMax()
              << ", Avg = " << intStats.getAverage() << "\n";

    std::cout << "Double Stats: Min = " << doubleStats.getMin()
              << ", Max = " << doubleStats.getMax()
              << ", Avg = " << doubleStats.getAverage() << "\n";

    return 0;
}

