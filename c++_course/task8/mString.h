#pragma once

#include <iostream>
#include <string.h>

using std::cout;


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
		if (static_cast<int>(p[0]) == 1) {
			delete [] p;
		} else {
			p[0]--;
		}
	}

	SharedString& operator=(const SharedString& from) {
		if (len == from.len && std::equal(p, p+len, from.p)) {
			return *this;
		}

		if (static_cast<int>(p[0]) == 1) {
			delete [] p;
		} else {
			p[0]--;
		}

		len = from.len;
		p = from.p;
		from.p[0]++;

		return *this;
	}

	SharedString &operator+=(const SharedString &from) {
		char *p1 = new char[len + from.len + 2];
		strcpy(p1, p);
		//cout << p1;

		strcpy(p1+len+1, from.p+1);
		//cout << p1;

		p1[0] = static_cast<char>(1);

		if (static_cast<int>(p[0]) == 1) {
			delete [] p;
		} else {
			p[0]--;
		}

		p = p1;
		len += from.len;
		return *this;
	}

	void print() const {
		for (int i = 1; i <= len; i++) {
			cout << p[i];
		}
	}

	friend void swp(SharedString& s1, SharedString& s2);
protected:
	char *p;
	int len;
};

void swp(SharedString& s1, SharedString& s2)
{
	char *tmp = s2.p;
	s2.p= s1.p ;
	s1.p = tmp;

	int tmpp = s1.len;
	s1.len = s2.len;
	s2.len= tmpp;
}
