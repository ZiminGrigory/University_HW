#include <iostream>
#include <stack>
#include <stdexcept>

#include <Shape.h>
#include <List.h>

using namespace std;

class ErrorTimeParams{};

void f(stack<int>& s) // ok, we know that std::stack doesn't throws exceptions, but imagine this.
{
	int* p = new int[1000];
		 // … тут, допустим, мы что-то делаем с p и s
	try {
		s.pop(); // s.pop() is a void!! can't cout this
	} catch (...)
	{}
		// … а тут еще что-то делаем с p и s
	delete [] p;
	// Потенциальная утечка памяти: delete может и не вызваться!
}

class Time
{
public:
	Time(int h, int m) : hour(h), min(m)
	{
		if (!( 0 <= hour && hour <= 24) || !( 0 <= min && min <= 59))
			throw ErrorTimeParams();
	}
private:
	int hour, min;
};

int main()
{
	//1,2
	Rhombus r1(0,1,1,0);
	r1.draw();

	RhombusWithDiag r2(0,1,1,0);
	r2.draw();

	Shape* r3 = new Rhombus(0,1,1,0);
	cout << "r3 Area " << r3->area() << endl;
	cout << "r3 perim " << r3->perim() << endl;
	delete r3;

	Shape* c1 = new Circle(1);
	cout << "c1 Area " << c1->area() << endl;
	cout << "c1 perim " << c1->perim() << endl;
	delete c1;

	//3
	int n(0);
	cout << "\n\nenter n ->";
	cin >> n;
	List<int> list;
	for (int i = n; i >= 1; i--) {
		list.add(i);
	}
	cout << endl;
	Node<int>* p = list.getHead();
	while (p != nullptr) {
		 cout << p->value << " ";
		 p = p->next;
	}

	//4
	try {
		Time t(25, 1);
	} catch (ErrorTimeParams &) {
		cout << "\n\n wrong parameters \n";
	}

	return 0;
}

