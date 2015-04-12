#pragma once

#include <iostream>
#include <string.h>

using namespace std;


class mString {
public:
	mString(const char *s = "")
		: anc(nullptr)
		, substr1()
		, substr2()
		, p(nullptr)
		, len(0)
	{
		len = strlen(s);
		p = new char[len+1];
		strcpy(p, s);
	}

	// suppose that nay be only one substr, its copy - new str
	mString(const mString& from)
		: anc(nullptr)
		, substr1()
		, substr2()
		, p(nullptr)
		, len(from.len)
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
		if (anc) {
			anc->modify(substr1, substr2, p, len);
		}
		return *this;
	}

	 mString substr(int st, int b) {
		char *res = new char[b-st+3];
		res[b-st+2] = '\0';
		for (int i = st; i <= b+1; i++) {
			res[i-st] = p[i];
		}
		return mString(res,this,st,b);
	 }

	void print() const {
		for (int i = 0; i < len; i++) {
			cout << p[i];
		}
	}

protected:
	mString *anc;
	int substr1, substr2;

	void modify(int st, int b, const char *s, int nlen) {
		char* p1 = new char[len - (b-st+3) + nlen + 1];
		for (int i = 0; i < st; i++) {
			p1[i] = p[i];
		}
		char *back = new char[len-b];
		strcpy(back, p+b+2);
		for (int i = st; i < nlen + st; i++) {
			//p1[i] = 'c';
			p1[i] = s[i-st];
		}
		strcpy(p1+nlen+st, back);
		p = p1;
		if (anc) {
			anc->modify(substr1, substr2, p, len);
		}
	}

private:
	char *p;
	int len;

	mString(const char *s, mString *anc,int substr1,int substr2)
		: anc(anc)
		, substr1(substr1)
		, substr2(substr2)
		, p(nullptr)
		, len(0)
	{
		len = strlen(s);
		p = new char[len+1];
		strcpy(p, s);
	}

};
