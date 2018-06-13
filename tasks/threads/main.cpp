#include <iostream>
#include <progbase-cpp/console.h>
#include <mutex>
#include <thread>
#include <graphics.h>
#include <cmath>

using namespace std;
using namespace progbase::console;

void threadRectangle(double & length, double & width, int & period, CursorAttributes color, mutex & mutex);
void threadHexagon(double & length, int & period, double & amplitude, CursorAttributes color, mutex & mutex);

void clearRect(Vec2D location, Vec2D size);
void printRectangle(Vec2D & center, double & length, double & width, CursorAttributes color, double & radians);
void printHexagon(Vec2D & center, double & length, double & amplitude, CursorAttributes color, double & radians);

int main() {
	double length[] = {30, 10};
	double width = 10;
	int period[] = {100, 150};
	double amplitude = 5;
	CursorAttributes color[] = {CursorAttributes::BG_BLUE, CursorAttributes::BG_YELLOW};
	mutex mutex;

	Console::clear();
	Console::setSize(35, 130);
	Console::hideCursor();
	thread rectangle(threadRectangle , ref(length[0]), ref(width), ref(period[0]), ref(color[0]), std::ref(mutex));
	thread hexagon(threadHexagon , ref(length[1]), ref(period[1]), ref(amplitude), ref(color[1]), ref(mutex));
	while (!Console::isKeyDown());
	rectangle.detach();
	hexagon.detach();
	Console::reset();
	Console::showCursor();
	cout << endl;
	return EXIT_SUCCESS;
}

void threadHexagon(double & length, int & period, double & amplitude, CursorAttributes color, mutex & mutex) {
	Vec2D consoleCenter = {97, 18};
	int degrees = 0;
	while (true) {
		double radians = degrees * M_PI / 180.0;
		mutex.lock();
		clearRect((Vec2D){65,0}, (Vec2D){130, 35});
		printHexagon(consoleCenter, length, amplitude, color, radians);
		mutex.unlock();
		this_thread::sleep_for(chrono::milliseconds(period));
		degrees += 30;
	}
}

void threadRectangle(double & length, double & width, int & period, CursorAttributes color, mutex & mutex) {
	Vec2D consoleCenter = {37, 18};
	int degrees = 0;
	while (true) {
		double radians = degrees * M_PI / 180.0;
		mutex.lock();
		clearRect((Vec2D){0,0}, (Vec2D){65, 35});
		printRectangle(consoleCenter, length, width, color, radians);
		mutex.unlock();
		this_thread::sleep_for(chrono::milliseconds(period));
		degrees += 30;
	}
}

 void clearRect(Vec2D location, Vec2D size) {
 	for (int y = 0; y < size.y; y++) {
 		for (int x = 0; x < size.x; x++) {
 			Vec2D pos = { location.x + x, location.y + y };
 			Graphics_drawPixel(NULL, pos, CursorAttributes::BG_DEFAULT);
 		}
 	}
 }

void printRectangle(Vec2D & center, double & length, double & width, CursorAttributes color, double & radians) {
	Vec2D rotateVector = {1, 1};
	rotateVector = Vec2D_normalize(rotateVector);
	rotateVector = Vec2D_multByNumber(rotateVector, sqrt(pow(length, 2) + pow(width, 2)) / 2);
	rotateVector = Vec2D_rotate(rotateVector, radians);
	double angle = 2 * atan(width/length);
	for (int i = 0; i < 4; ++i) {
		angle = M_PI - angle;
		Vec2D startLinePos = Vec2D_add(center, rotateVector);
		rotateVector = Vec2D_rotate(rotateVector, angle);
		Vec2D endLinePos = Vec2D_add(center, rotateVector);
		Graphics_drawLine(NULL, startLinePos, endLinePos, color);
	}
}

void printHexagon(Vec2D & center, double & length, double & amplitude, CursorAttributes color, double & radians) {
	Vec2D rotateVector = {1, 1};
	double amp = amplitude * sin(radians);
	rotateVector = Vec2D_normalize(rotateVector);
	rotateVector = Vec2D_multByNumber(rotateVector, length + amp);
	rotateVector = Vec2D_rotate(rotateVector, M_PI / 12);

	for (int i = 0; i < 6; ++i) {
		Vec2D startLinePos = Vec2D_add(center, rotateVector);
		rotateVector = Vec2D_rotate(rotateVector, M_PI / 3);
		Vec2D endLinePos = Vec2D_add(center, rotateVector);
		Graphics_drawLine(NULL, startLinePos, endLinePos, color);
	}
}