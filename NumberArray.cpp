#include "NumberArray.h"
#include <iostream>
#include <iomanip>
using namespace std;

// Constructor
NumberArray::NumberArray(int size)
{
    if (size <= 0)
        this->size = MAX_SIZE;
    else
        this->size = size;

    data = new double[this->size];

    for (int i = 0; i < this->size; i++)
        data[i] = 0.0;
}

// Destructor
NumberArray::~NumberArray()
{
    delete[] data;
    cout << "[Destructor] NumberArray memory released." << endl;
}

// Mutator
void NumberArray::setNumber(int index, double value)
{
    if (index >= 0 && index < size)
        data[index] = value;
    else
        cout << "[Warning] setNumber: Index out of bounds." << endl;
}

// Accessor
double NumberArray::getNumber(int index) const
{
    static double DEFAULT_VALUE = 0.0;

    if (index >= 0 && index < size)
        return data[index];

    cout << "[Warning] getNumber: Index out of bounds." << endl;
    return DEFAULT_VALUE;
}

// Minimum
double NumberArray::getMin() const
{
    double min = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] < min)
            min = data[i];
    return min;
}

// Maximum
double NumberArray::getMax() const
{
    double max = data[0];
    for (int i = 1; i < size; i++)
        if (data[i] > max)
            max = data[i];
    return max;
}

// Average
double NumberArray::getAverage() const
{
    double sum = 0.0;
    for (int i = 0; i < size; i++)
        sum += data[i];
    return sum / size;
}

// Print
void NumberArray::print() const
{
    cout << "Array contents: ";
    for (int i = 0; i < size; i++)
        cout << fixed << setprecision(2) << data[i] << " ";
    cout << endl;
}
