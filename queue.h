#include <iostream>
using namespace std;

const int max_size = 100;
template <class t>
class queue {
private:
    t stack[max_size];
    int front;
    int end;

public:
    queue() {
        front = -1;
        end = -1;
    }

    void push(t num) {
        if (end == max_size - 1) {
            cout << "Error stack is full" << endl;
            return;
        } else if (front == -1) {
            front = 0;
        }
        end++;
        stack[end] = num;
    }

    void pop() {
        if (front == -1) {
            cout << "Error stack is empty" << endl;
            return;
        }
        front++;
        if (front > end) {
            front = -1;
            end = -1;
        }
    }

    void printall() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }
        for (int i = front; i <= end; i++) {
            //cout << stack[i] << " ";
            
        }
        
        
    }
    void printallc() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        for (int i = front; i <= end; i++) {
            //cout << stack[i] << " ";
        }
    }

};

