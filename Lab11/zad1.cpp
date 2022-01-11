#include <iostream>

using namespace std;




struct Circle {
	float x, y, radius;
	
	Circle() = default;
	
	Circle (float x_, float y_, float radius_) {
		x = x_;
		y = y_;
		radius = radius_;
	}
};

float getPerimeter(const Circle& pt) {
	return 2 * pt.radius * 3.14;
}

float getArea(const Circle& pt) {
	return pt.radius * pt.radius * 3.14;
}

int main() {
	
	Circle pt(2, 2.5, 3);

	cout << "Perimeter: " << getPerimeter(pt) << endl;
	
	cout << "Area: " << getArea(pt) << endl;
	
	return 0;
}
