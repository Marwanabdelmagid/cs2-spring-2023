#include <iostream>
using namespace std;

class point {
private:
    float x, y;
public:
    //coonstructor
    point(){
        set_x(0);
        set_y(0);
    }
    //paramtriezed constructor
    point(float x1, float y1){
        set_x(x1);
        set_y(y1);
    }
    //setter
    void set_x(float x1) {
        x = x1;
    }
    //getter
    float get_x() {
        return x;
    }
    //setter
    void set_y(float y1) {
        y = y1;
    }
    float get_y() {
        return y;
    }
    //getter
    void displaycord() {
        cout << "(" << x << "," << y << ")" << endl;

    }
    //display corrodinates
    void displaycord(float x1, float y1) {
        cout << "(" << x1 << "," << y1 << ")" << endl;

    }
    //function used to get distance between point p and another point 
    float disttop(float x2, float y2) {
        float dist;
        dist = powf((x - x2), 2) + powf((y - y2), 2);
        return powf(dist, 0.5);
    }
};
