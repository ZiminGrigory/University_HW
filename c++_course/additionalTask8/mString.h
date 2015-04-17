#pragma once

#include <iostream>
#include <string.h>

using namespace std;
//
//Мне кажется, результат substr должен быть не типа mString а какого-то другого, вспомогательного типа "подстрока".
//И можно даже этот тип сделать private чтобы у нему нельзя было явно обратится.
//Понятно примерно, что я имею в виду, да? Попробуйте так написать, пожалуйста.
//Если не очень понятно, или вы не согласны, что так лучше, напишите, обсудим.

class mString {
private:
	void modify(int st, int b, const char *s, int nlen) {
		char* p1 = new char[len - (b-st+3) + nlen + 1];
		for (int i = 0; i < st; i++) {
			p1[i] = p[i];
		}
		char *back = new char[len-b];
		strcpy(back, p+b+2);
		for (int i = st; i < nlen + st; i++) {
			p1[i] = s[i-st];
		}
		strcpy(p1+nlen+st, back);
		p = p1;
	}

	class subString{
	public:
		subString(const char *s, int pos1, int pos2, mString *ancestor)
			: p(nullptr)
			, len(0)
			, pos1(pos1)
			, pos2(pos2)
			, anc(ancestor)
		{
			len = strlen(s);
			p = new char[len+1];
			strcpy(p, s);
		}

		operator mString() {
			return mString(p);
		}

		subString &operator=(const mString& from) {
			len = from.len;
			char* p1 = new char[len + 1];
			strcpy(p1, from.p);
			delete [] p;
			p = p1;
			anc->modify(pos1,pos2,p,len);
			return *this;
		}
	private:
		char *p;
		int len;
		int pos1, pos2;
		mString *anc;
	};


public:
	mString(const char *s = "")
		: p(nullptr)
		, len(0)
	{
		len = strlen(s);
		p = new char[len+1];
		strcpy(p, s);
	}

	mString(const mString& from)
		: p(nullptr)
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
		return *this;
	}

	subString substr(int st, int b) {
		char *res = new char[b-st+3];
		res[b-st+2] = '\0';
		for (int i = st; i <= b+1; i++) {
			res[i-st] = p[i];
		}
		return subString(res, st, b, this);
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
