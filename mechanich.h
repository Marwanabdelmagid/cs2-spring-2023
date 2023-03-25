#include<iostream>
using namespace std;

class mechanic : public person {
private:
	int counter;
	appointment mechapp[48];
	//Based on the assumption that each apppointment is 30 minutes, the mechanich can handle a maximum of 48 per day assuming he works 24 hours./
	//appointment *mechapp= new appointment[ud];(if i did not go with the previous assumption i would have declared it like this)

public:
	mechanic() {
		set_counter(0);
	}

	//setters and getters for counter
	void set_counter(int c)  { counter = c; }
	int get_counter() const { return counter; }

	//setters, getters and print for appointments.
	void set_app(int c, int h, int m) {
		if (c > 48)
		{
			cout << "Invalid entry, only 48 possible appointnments" << endl;
			return;
		}
		mechapp[c].hours = h;
		mechapp[c].mins = m;
		cout << "Appoitnment booked sucssefely at " << h << ":" << m <<", with "<<get_name()<< endl;
		counter++;
		return;

	}
	void print_app(int c) {
		int h = mechapp[c].hours;
		int m = mechapp[c].mins;
		cout << "Appoitnment is at " << h << ":" << m << endl;
		return;
	}
	//getter by refrence
	void get_app(int c, int& h, int& m) {
		h = mechapp[c].hours;
		m = mechapp[c].mins;
		//cout << "Appoitnment is at " << h << ":" << m << endl;
		return;
	}
	bool av;
	bool is_available(int h, int m) {
		if (h < 0 || h > 24 || m < 0 || m > 60) {
			cout << "Invalid time entered." << endl;
			return false;
		}
		for (int i = 0; i < counter; i++) {
			int h1 = mechapp[i].hours;
			int m1 = mechapp[i].mins;
			if (m < 31) 
				if (h1 == h && m1 <= m + 30 && m1 >= m) {
					cout << "Mechanic is not available at this time" << endl;
					return false;
					}
				else if (m >= 31) 
					if ((h1 == h && m1 >= 31) || (h1 == h + 1 && m1 <= m - 30)) {
						cout << "Mechanic is not available at this time" << endl;
						return false;
					}
			cout << "Mechanic is available" << endl;
			av = true;
			break;

		}
		if (av)return true;
			
	}

};