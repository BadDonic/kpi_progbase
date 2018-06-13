#include "taxidriver.h"

TaxiDriver::TaxiDriver()
{
    this->name = "";
    this->salary = 0;
    this->salary = 0.0;
}

TaxiDriver::TaxiDriver(string name, int age, double salary)
{
    this->name = name;
    this->age = age;
    this->salary = salary;
}

string TaxiDriver::getName() { return this->name; }
int TaxiDriver::getAge() { return this->age; }
double TaxiDriver::getSalary() { return this->salary; }
