#include<iostream>
using namespace std;
//Assuming that the customer is booking a time slot of 30 minutes. We work through 
class person {
private:
	string name;
	int id, age;
public:
	person() {
		set_id(0);
		set_age(0);
		set_name("");

	}
	person(string n, int i, int a) {
		set_name(n);
		set_id(i);
		set_age(a);

	}
	//setters and getters

	void set_name(string a) { name = a; }
	string get_name() { return name; }

	void set_id(int i) {id = i; }
	int get_id() { return id; }

	void set_age(int a) { age = a; }
	int get_age() { return age; }

	//print function
	void printinfo() {
		cout << "Name is " << name << endl;
		cout << "Id is " << id << endl;
		cout << "Age is " << age << endl;
	}
	// struct for appointment
	struct appointment {
		int hours, mins;
		
	};
};

