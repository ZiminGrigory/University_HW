#include <iostream>
#include <vector>
//2(1) -написать свой стек простейший

using ll = long long;

using namespace std;

class Error{};

class Stack{
public:
	Stack(): head(-1)
	{
		mStack.resize(100);
		mProductStack.resize(100);
	}

	void push(const ll a)
	{
		if (head++ >= mStack.size()) {
			mStack.resize(mStack.size()*2);
			mProductStack.resize(mStack.size());
		}
		mStack[head] = a;
		mProductStack[head] = head == 0 ? a : mProductStack[head-1]*a;
	}

	ll pop()
	{
		if (head == -1) {
			throw Error();
		}

		return mStack[head--];
	}

	ll& top()
	{
		if (head == -1) {
			throw Error();
		}

		return mStack[head];
	}

	ll product() //doesnt work with top
	{
		if (head == -1) {
			throw Error();
		}

		return mProductStack[head];
	}

private:
	ll head;
	vector<ll> mStack;
	vector<ll> mProductStack;
};

bool compare1(const char &s1, const char &s2)
{
	auto s1_ = s1;
	auto s2_ = s2;
	bool ans(true);
	while (ans && s1_ != '\0' && s2_ != '\0') {
		ans = s1_ == s2_, s1_++, s2_++;
	}
	return ans && s1_ == '\0' && s2_ == '\0';
}

bool compare2(const char* const s1, const char* const s2)
{
	auto s1_ = s1;
	auto s2_ = s2;
	bool ans(true);
	while (ans && *s1_ != '\0' && *s2_ != '\0') {
		ans = *s1_ == *s2_, s1_++, s2_++;
	}
	return ans && *s1_ == '\0' && *s2_ == '\0';
}

int main()
{
	//2(1)
	Stack a;
	a.push(4);
	a.push(3);
	a.push(2);
	a.push(1);
	std::cout << "task #2(1)" << endl;
	std::cout << a.pop() << endl;
	std::cout << a.pop() << endl;
	std::cout << a.pop() << endl;
	std::cout << a.pop() << endl;

	//3
	a.push(4);
	a.push(3);
	a.push(2);
	a.push(1);
	std::cout << "task #3" << endl;
	std::cout << ++a.top() << endl;
	std::cout << "before change " << a.top();
	a.top() = 42;
	std::cout << " after change " << a.top() << endl;

	//4
	char s1[100];
	char s2[100];
	cout << "enter couple lines pls\n";
	cin.getline(s1, 100);
	cin.getline(s2, 100);
	cout << " compare1 s1 s2 = " << compare1(*s1, *s2) << endl;
	cout << " compare2 s1 s2 = " << compare2(s1, s2) << endl;

	//5
	a.push(4);
	a.push(3);
	a.push(2);
	a.push(1);
	std::cout << "task #5" << endl << "product = " << a.product() << endl;
	a.push(0);
	std::cout << "task #5" << endl << "product after push(0) " << a.product() << endl;
	a.pop();
	std::cout << "task #5" << endl << "product after pop" << a.product() << endl;


	return 0;
}

