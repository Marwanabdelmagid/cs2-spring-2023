#include<iostream>
#include"person.h"

using namespace std;

class customer : public person {
private:
	int mechid;
	appointment custapp;
public:
	customer() {
		set_mechid(0);
		custapp.hours = 0;
		custapp.mins = 0;
		return ;
	}
	void set_mechid(int mi)  {
		mechid = mi;
		return ;
	}
	int get_mechid()const { return mechid;}
	void set_custapp(int h, int m) {
		custapp.hours = h;
		custapp.mins = m;
		return;
	}
	void print_custapp() {
		int h = custapp.hours;
		int m = custapp.mins;

		cout << "The time of the appointiment is " << h << ":" << m << endl;
	}
	void get_custapp(int *h,int *m) {
		 *h = custapp.hours;
		 *m = custapp.mins;

		//cout << "The time of the appointiment is " << h << ":" << m << endl;
	}
	 bool operator >(const customer& b)
	{
		if (custapp.hours>b.custapp.hours)
			return true;
		else if (custapp.mins>b.custapp.mins)
			return true;
		else return false;
	}
	 bool operator <(const customer& b)
	 {
		 if (custapp.hours > b.custapp.hours)
			 return false;
		 else if (custapp.mins > b.custapp.mins)
			 return false;
		 else return true;
	 }
	 bool operator==(const customer& b)
	 {
		 if (custapp.hours == b.custapp.hours && custapp.mins == b.custapp.mins)
			 return true;
		 else return false;
	 }
	/* void operator<<(const customer& b)
	 {
		 int h, m;
		 get_custapp(h, m);
		 cout << "Time is at " << h << " : " << m << endl;
		 
	 }
	 this was the answer i came up with but could not remove customer b, but did nit work
	 */
	 // got this answer online
	 friend ostream& operator<<(ostream& output,  customer c) {
		 int *h1, *m1;
		 c.get_custapp(h1, m1);
		 output << "Time is at : " <<* h1<< " : " <<*m1;
		 return output;
	 }
		
	
};