#include <iostream>
#include "holydays.h"

using namespace std;

void f1() {
	holydays h;
	cout << h.whatsHolydayToday(1,1) << endl;
}

void f2() {
	holydays h;
	cout << h.whatsHolydayToday(23,2) << endl;
}

void f3() {
	holydays h;
	cout << h.whatsHolydayToday(1,2) << endl;
}
