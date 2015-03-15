#include <iostream>

#include "Complex.h"
#include "tree.h"
#include "mTime.h"
#include "mStack.h"

using namespace std;


int main()
{
//	//1
//	cout << "Hello World!" << endl;
//	Complex c1(1,1), c2(2,2);
//	Complex c3 = c1 * c2;
//	c1 *= c2;

//	//2
//	Tree<int> t;
//	int a(-1);
//	while (a) {
//		cin >> a;
//		if (a) {
//			t.add(a);
//		}
//	}

//	t.printTree();

//	//3
//	timeCollection tc;	// tc – набор данных о времени
//	tc.add(new mTime(8, 30));
//	tc.add(new time_with_sec(10, 00, 15));
//	tc.add(new mTime(12, 10));
//	tc.print();		// Напечатать 8:30  10:0.15  12:10

	//4
	Stack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);

	st.maxSin();
	st.maxSin();

	st.pop();
	st.push(1);
	st.push(2);
	st.push(3);
	st.maxSin();
	cout << endl;

	return 0;
}

