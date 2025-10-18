#ifndef STATISTICS_H
#define STATISTICS_H

#include <vector>
#include <stdexcept>
using namespace std;



// Return the smallest value in the vector
template <typename T>
T getMin(const vector<T>& values) {
    if (values.empty())
        throw invalid_argument("vector is empty");

    T minVal = values[0];
    for (size_t i = 1; i < values.size(); ++i) {
        if (values[i] < minVal)
            minVal = values[i];
    }
    return minVal;
}

// Return the largest value in the vector
template <typename T>
T getMax(const vector<T>& values) {
    if (values.empty())
        throw invalid_argument("vector is empty");

    T maxVal = values[0];
    for (size_t i = 1; i < values.size(); ++i) {
        if (values[i] > maxVal)
            maxVal = values[i];
    }
    return maxVal;
}

// Return the average (mean) of all values in the vector
// Always returns a double regardless of T
template <typename T>
double getAverage(const vector<T>& values) {
    if (values.empty())
        throw invalid_argument("vector is empty");

    double sum = 0.0;
    for (const T& val : values)
        sum += static_cast<double>(val);

    return sum / static_cast<double>(values.size());
}



template <typename T>
class Statistics {
private:
    vector<T> data; // container to store numeric values

public:
    // Add a new value to the data vector
    void addValue(const T& value) {
        data.push_back(value);
    }

    // Compute minimum value using global function
    T getMin() const {
        return ::getMin(data);
    }

    // Compute maximum value using global function
    T getMax() const {
        return ::getMax(data);
    }

    // Compute average value using global function
    double getAverage() const {
        return ::getAverage(data);
    }

};

#endif // STATISTICS_H
