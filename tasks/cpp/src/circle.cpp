#include <circle.h>

Circle::Circle(double radius, string color, string name) {
	this->name = name;
	this->color = color;
	this->radius = radius;
}

long double Circle::square(void) {
	return pow(this->radius, 2) * M_PI;
}

void Circle::print(void) {
	cout << "Name : " + this->name + ", Color : " + this->color + ", Radius = " << this->radius << endl;
}
