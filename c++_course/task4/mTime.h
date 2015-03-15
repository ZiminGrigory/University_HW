#pragma once
#include <iostream>
#include <vector>

using namespace std;

class mTime
{
public:
	mTime(int hour, int min) : hour(hour), min(min)
	{}
	virtual void print() const{
		cout << hour << ":" << min << endl;
	}

protected:
	int hour, min;
};


class time_with_sec : public mTime
{
public:
	time_with_sec(int h, int m, int s) : mTime(h, m), sec(s)
	{}

	void print() const override {
		cout << hour << ":" << min << "." << sec << endl;
	}

private:
	int sec;
};

class timeCollection
{
public:
	void add(mTime *t) {
		times.push_back(t);
	}
	void print() const {
		for (const auto &t : times) {
			t->print();
		}
	}
private:
	vector<mTime *> times;
};
