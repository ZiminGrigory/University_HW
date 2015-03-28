#pragma once

#include <iostream>
#include <string.h>

using namespace std;


class SharedString {
public:
	SharedString(const char *s = "")
	{
		len = strlen(s);
		p = new char[len + 2];
		strcpy(p + 1, s);
		p[0] = static_cast<char>(1);
	}

	SharedString(const SharedString& from) : len(from.len)
	{
		p = from.p;
		p[0]++;
	}

	~SharedString() {
		delete [] p;
	}

	SharedString& operator=(const SharedString& from) {
		if (static_cast<int>(p[0]) == 1) {
			delete [] p;
		}

		len = from.len;
		p = from.p;
		from.p[0]++;

		return *this;
	}

	SharedString &operator+=(const SharedString &from) {
		char *p1 = new char[len + from.len + 2];
		strcpy(p1, p);
		cout << p1;
		if (static_cast<int>(p[0]) == 1) {
			delete [] p;
		} else {
			p[0]--;
		}

		strcpy(p1+len+1, from.p+1);
		cout << p1;

		p1[0] = static_cast<char>(1);
		p = p1;
		len += from.len;

		return *this;
	}

	void print() const {
		for (int i = 1; i <= len; i++) {
			cout << p[i];
		}
	}

protected:
	char *p;
	int len;
};
