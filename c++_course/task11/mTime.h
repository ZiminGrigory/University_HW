#pragma once
#include <iostream>
#include <memory>
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
	virtual mTime* clone() const {
		return new mTime(hour, min);
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

	mTime* clone() const override{
		return new time_with_sec(hour, min, sec);
	}

private:
	int sec;
};

class timeCollection
{
public:
	timeCollection(){}
	~timeCollection(){}

	void add(mTime *t) {
		times.push_back(unique_ptr<mTime>(t));
	}

	void print() const {
		for (const auto &t : times) {
			t->print();
		}
	}

	bool hasTimeWithSec() const {
		for (auto &a : times) {
			if (dynamic_cast<time_with_sec*>(a.get())) {
				return true;
			}
		}
		return false;
	}

private:
	vector<unique_ptr<mTime>> times;
};
