#include <circle.h>
#include <vector>

int main(void) {
	vector<Circle *> array;
	char button;
	while (true) {
		cout << "1. Print Array\n2. Add Element\n3. Show element which has square less S" << endl;
		cout << "4. Exit\n" << endl;
		cin >> button;
		switch (button) {
			case '1': {
				for (int i = 0; i < (int)array.size(); i++) {
					cout << "Circle ( " << i + 1 << " )" << endl;
					array[i]->print();
				}
				break;
			}
			case '2': {
				string name;
				string color;
				double radius;
				cout << "Name : ";
				cin >> name;
				cout << endl << "Color : ";
				cin >> color;
				cout << endl << "Radius = ";
				cin >> radius;
				cout << endl;
				array.push_back(new Circle(radius, color, name));
				break;
			}
			case '3': {
				double maxSquare;
				cout << "MaxSquare = ";
				cin >> maxSquare;
				cout << endl;
				for (Circle * cur : array)
					if (cur->square() < maxSquare) cur->print();
				getchar();
				break;
			}
			case '4': {
				for (Circle * cur : array)
					delete cur;
				return EXIT_SUCCESS;
			}
			default: {
				break;
			}
		}
	}
}