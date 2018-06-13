#ifndef TAXIDRIVER_H
#define TAXIDRIVER_H

#include <iostream>

using namespace std;

class TaxiDriver
{
    string name;
    int age;
    double salary;
public:
    TaxiDriver();
    TaxiDriver(string name, int age, double salary);
    string getName();
    int getAge();
    double getSalary();
};

#endif // TAXIDRIVER_H
