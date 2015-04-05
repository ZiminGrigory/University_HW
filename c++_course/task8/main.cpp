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
using std::back_inserter;
using std::vector;

template <typename T>
void swp(T& a, T& b) {
	T c = a;
	a = b;
	b = c;
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
//	//	1
//	list<int> ml; // task modified don't enter 0, enter EOF Windows: Ctrl+Z ; Unix :Ctrl+D
//	copy(istream_iterator<int>( cin ), istream_iterator<int>(), back_inserter(ml));
//	copy(ml.begin(), ml.end(), ostream_iterator<int>(cout, " "));

//	//2
//	int a= 2,b=5;
//	swp(a,b);
//	return 0;

//	//3
//	SharedString s1 = "asv";
//	SharedString s2 = "bsc";
//	swp(s1,s2);

//	//4
//	list<int> ml;
//	ml.push_back(1);
//	ml.push_back(2);
//	ml.push_back(3);
//	print1(ml);
//	print2(ml);

	//5
	Tree<int> t;
	t.add(1);
	t.add(2);
	t.add(5);
	t.printTree();
	ForEach<int>(&t, [](int& x){ x*= 2;});
	t.printTree();
	cout << endl;
	ForEach<int>(&t, [](int& x){ cout << (x > 2);});
}

