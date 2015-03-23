#pragma once

#include <iostream>
#include <string.h>

using namespace std;


class mString {
public:
	mString(const char *s = "")
	{
		len = strlen(s);
		p = new char[len+1];
		strcpy(p, s);
	}

	mString(const mString& from) : len(from.len)
	{
		p = new char[len + 1];
		strcpy(p, from.p);
	}

	~mString() {
		delete [] p;
	}

	mString &operator=(const mString& from) {
		len = from.len;
		char* p1 = new char[len + 1];
		strcpy(p1, from.p);
		delete [] p;
		p = p1;
		return *this;
	}

	mString &operator+=(const mString &from) {
		char *p1 = new char[len + from.len + 1];
		strcpy(p1, p);
		for (int i = len; i < len + from.len; i++) {
			p1[i] = from.p[i - len];
		}
		p1[len + from.len] = '\0';
		delete []p;
		p = p1;
		len += from.len;
		return *this;
	}

	void print() const {
		for (int i = 0; i < len; i++) {
			cout << p[i];
		}
	}

private:
	char *p;
	int len;
};
