/*#include "point.h"
#include "circle.h"

void Circle::setCore(int x, int y) {
	point.setPoint(x, y);
}
void Circle::setr(int R) {
	r = R;
}
int Circle::getr() {
	return r;
}
Point Circle::getPoint() { //在一个类中可以让另一个类作为这个类的成员
	return point;
}

void Point::setPoint(int X, int Y) {
	x = X;
	y = Y;
}
int Point::getx() {
	return x;
}
int Point::gety() {
	return y;
}

void isInCircle(Circle& circle, Point& point) {
	int dx = circle.getPoint().getx() - point.getx();
	int dy = circle.getPoint().gety() - point.gety();
	int distance = dx * dx + dy * dy;
	int rdistance = circle.getr() * circle.getr();
	if (distance == rdistance) {
		cout << "点在圆上" << endl;
	}
	else if (distance > rdistance) {
		cout << "点在圆外" << endl;
	}
	else {
		cout << "点在圆内" << endl;
	}
}

int main() {
	Circle circle;
	circle.setCore(0, 0);
	circle.setr(10);
	cout << circle.getPoint().getx() << " ";
	cout << circle.getPoint().gety() << endl;

	Point point;
	point.setPoint(3, 5);
	cout << point.getx() << " ";
	cout << point.gety() << endl;

	isInCircle(circle, point);
}*/