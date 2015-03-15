#pragma once

#include <iostream>
#include <cmath>
#include <math.h>
#include <vector>
#include <algorithm>


using namespace std;

class Stack{
public:
	Stack(){}

	void push(int a)
	{
		mStack.push_back(a);
	}

	int pop()
	{
		if (mStack.size() == 0) {
			throw("stack is empty");
		}

		int ans = mStack.at(mStack.size() - 1);
		mStack.pop_back();
		return ans;
	}

	double maxSin() const {
		if (!mStack.size()) {
			throw("too few elems in stack");
		}

		if (maxS != -2. && mStack == checkStack) {
			return maxS;
		}

		checkStack.resize(mStack.size());
		int misMatchPos = -1;
		if (maxS != -2) {
			for (int j = 0; j < mStack.size(); j++) {
				misMatchPos++;
				if (checkStack[j] != mStack[j])
					break;
			}
		} else {
			misMatchPos = 0;
		}

		//try reuse maxSin
		products.resize(mStack.size());
		for (int i=misMatchPos; i < mStack.size(); i++) {
			double mmax = -1.;
			for (int j = 0; j <= i; j++) {
				mmax = max(mmax, sin(mStack[i] * mStack[j]));
			}
			products[i] = mmax;
		}

		for (int i=misMatchPos; i < mStack.size(); i++) {
			checkStack[i] = mStack[i];
		}

		maxS = *std::max_element(products.begin(), products.end());
		return maxS;
	}
private:
	vector<int> mStack;
	mutable vector<int> checkStack;
	mutable vector<double> products;
	mutable double maxS = -2;
};
