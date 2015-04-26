#include <iostream>
#include <memory>
#include <type_traits>

#include "mTime.h"
#include "holydays.h"

using namespace std;

unique_ptr<mTime> createPairTime(int i)
{
	unique_ptr<mTime> ptr(nullptr);
	switch (i) {
		case 1:
			ptr.reset(new mTime(9,30));
			break;
		case 2:
			ptr.reset(new mTime(11,15));
			break;
		case 3:
			ptr.reset(new mTime(13,40));
			break;
		case 4:
			ptr.reset(new mTime(15,25));
			break;
	}
	return ptr;
}


int main()
{
	//1
	//На самом деле, есть такой стандартный шаблон, можно просто его найти в документации и показать
	//, как он используется, это будет засчитано.
	cout << is_pointer<double>::value << " " << is_pointer<int*>::value << endl;

	//2 class AdrBook;

	//3 а
	unique_ptr<int> a[10];
	for (int i = 0; i<10;++i) {
		a[i].reset(new int(i)); // мой компилятор так и не смог разпознать make_unique хотя gcc4.9.2, но и так неплохо
	}
	for (int i = 0; i<10;++i) {
		cout << *a[i] << endl;
	}
	auto p = move(a[9]);
	for (int i = 9; i >0; --i) {
		a[i] = move(a[i-1]);
	}
	a[0] = move(p);
	for (int i = 0; i<10;++i) {
		cout << *a[i] << endl;
	}

	//3 b
	auto p1 = createPairTime(1);
	p1->print();
	cout << endl;

	//4
	f1();
	f2();
	f3();


	//6
	timeCollection tc;
	tc.add(new mTime(1,1));
	tc.add(new mTime(1,2));
	tc.add(new mTime(1,4));
	cout << endl << tc.hasTimeWithSec();
	tc.add(new time_with_sec(1,4,3));
	cout << endl << tc.hasTimeWithSec();
	return 0;
}

