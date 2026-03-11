#include <iostream>
#include <random>
#include "NumberArray.h"
using namespace std;

int main()
{
    cout << "=== Default Constructor Test ===" << endl;
    NumberArray a;
    a.print();
    cout << "Size: " << a.getSize() << endl << endl;

    cout << "=== Parameterized Constructor Test ===" << endl;
    NumberArray b(5);
    b.print();
    cout << endl;

    cout << "=== setNumber() and getNumber() Tests ===" << endl;
    b.setNumber(0, 2.5);
    b.setNumber(2, 7.7);
    b.setNumber(4, 10.1);

    cout << "b[0] = " << b.getNumber(0) << endl;
    cout << "b[2] = " << b.getNumber(2) << endl;
    cout << "b[4] = " << b.getNumber(4) << endl;

    cout << "Invalid index tests:" << endl;
    b.setNumber(-1, 99.9);
    b.setNumber(5, 99.9);
    cout << "getNumber(-1) = " << b.getNumber(-1) << endl;
    cout << "getNumber(5)  = " << b.getNumber(5) << endl;
    cout << endl;

    cout << "=== Statistical Tests (Known Values) ===" << endl;
    NumberArray c(5);
    c.setNumber(0, 2.0);
    c.setNumber(1, 4.0);
    c.setNumber(2, 6.0);
    c.setNumber(3, 8.0);
    c.setNumber(4, 10.0);
    c.print();
    cout << "Min: " << c.getMin() << endl;
    cout << "Max: " << c.getMax() << endl;
    cout << "Avg: " << c.getAverage() << endl;
    cout << endl;

    cout << "=== Random Fill Test ===" << endl;
    NumberArray d(8);
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dist(0.0, 100.0);

    for (int i = 0; i < d.getSize(); i++)
        d.setNumber(i, dist(gen));

    d.print();
    cout << "Min: " << d.getMin() << endl;
    cout << "Max: " << d.getMax() << endl;
    cout << "Avg: " << d.getAverage() << endl;
    cout << endl;

    cout << "=== Destructor Scope Test ===" << endl;
    {
        NumberArray temp(3);
        temp.print();
    } // destructor should fire here

    cout << "Program complete." << endl;
    return 0;
}
