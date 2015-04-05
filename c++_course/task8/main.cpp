#include <iostream>
#include <iterator>
#include <list>
#include <vector>

#include "mString.h"
#include "tree.h"

using std::list;
using std::cout;
using std::cin;
using std::endl;
using std::copy;
using std::ostream_iterator;
using std::istream_iterator;
using std::iostream;
using std::front_inserter;
using std::vector;

template <typename T>
void swp(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
}

template <typename T>
void printC(const T& l) {
	typename T::const_iterator pos = l.begin();
	typename T::const_iterator end(l.end());
	for (; pos!=end; ++pos) {
		cout << *pos << ' ';
	}
}

template <typename T>
void print1(const list<T>& l) {
	copy(l.begin(), l.end(), ostream_iterator<T>(cout, " "));
}

template <typename T>
void print2(const list<T>& l) {
	list<T> t = l;
	while (!t.empty())
	{
		cout << t.front() << " ";
		t.pop_front();
	}
}

template <typename T>
void print1(const vector<T>& v) {
	copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
}

template <typename T>
void print2(const vector<T>& v) {
	for (size_t i = 0; i <v.size(); i++)
	{
		cout << v[i] << " ";
	}
}

int main()
{
	//2
	int a= 2,b=5;
	swp(a,b);

	//3
	SharedString s1 = "asv";
	SharedString s2 = "bsc";
	swp(s1,s2);

	//4
	list<int> l;
	l.push_back(1);
	l.push_back(2);
	l.push_back(3);
	printC(l);
	print2(l);

	//5
	Tree<int> t;
	t.add(1);
	t.add(2);
	t.add(5);
	t.printTree();
	int k = 0;
	cin >> k;
	ForEach<int>(&t, [=](int& x){ x*= k;});
	t.printTree();
	cout << endl;
	ForEach<int>(&t, [](int& x){ cout << (x > 2);});


	//	1
	list<int> ml; // task modified don't enter 0, enter EOF Windows: Ctrl+Z ; Unix :Ctrl+D
	copy(istream_iterator<int>( cin ), istream_iterator<int>(), front_inserter(ml));
	copy(ml.begin(), ml.end(), ostream_iterator<int>(cout, " "));

	return 0;
}

