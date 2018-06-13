#ifndef CPP_CIRCLE_H
#define CPP_CIRCLE_H

#include <iostream>
#include <cmath>

using namespace std;

class Circle {
	double radius;
	string color;
	string name;
public:
	Circle(double radius, string color, string name);
	long double square(void);
	void print(void);
};

#endif //CPP_CIRCLE_H
