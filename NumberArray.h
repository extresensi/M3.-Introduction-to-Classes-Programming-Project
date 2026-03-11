#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

#include <iostream>

class NumberArray
{
private:
    int size;
    double* data;

    static const int MAX_SIZE = 10;   // default size

public:
    // Constructor & Destructor
    NumberArray(int size = MAX_SIZE);
    ~NumberArray();

    // Mutator
    void setNumber(int index, double value);

    // Accessor
    double getNumber(int index) const;

    // Statistical functions
    double getMin() const;
    double getMax() const;
    double getAverage() const;

    // Print function
    void print() const;

    // Getter for size (optional but useful)
    int getSize() const { return size; }
};

#endif
