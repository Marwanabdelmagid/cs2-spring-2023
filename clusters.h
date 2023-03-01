#include <iostream>
using namespace std;

class point {
private:
	float x, y;
public:
	point(){
		x = 0;
		y = 0;
	}
	point(float x1, float y1){
		x = x1;
		y = y1;
	}
	void set_x(float x1) {
		x = x1;
	}
	float get_x() {
		return x;
	}
	void set_y(float y1) {
		y = y1;
	}
	float get_y() {
		return y;
	}
	void displaycord() {
		cout << "(" << x << "," << y << ")" << endl;

	}
	void displaycord(float x, float y) {
		cout << "(" << x << "," << y << ")" << endl;

	}
	float disttop(float x2, float y2) {
		float dist;
		dist = powf((x - x2), 2) + powf((y - y2), 2);
		return powf(dist, 0.5);
	}
};
