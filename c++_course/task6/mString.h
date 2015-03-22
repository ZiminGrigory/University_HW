#pragma once

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;


class mString {
public:
	mString(const char *s = "")
	{
		str.assign(s, s + strlen(s));
	}

	mString(const mString& from)
	{
		str.assign(from.str.begin(), from.str.end());
	}

	~mString() {}

	mString &operator= (const mString &from) {
		str.assign(from.str.begin(), from.str.end());
		return *this;
	}

	mString &operator+= (const mString &from) {
		str.insert(str.end(), from.str.begin(), from.str.end());
		return *this;
	}

	void print() const {
		for (int i = 0; i < str.size(); i++) {
			cout << str[i];
		}
	}

private:
	vector<char> str;
};
