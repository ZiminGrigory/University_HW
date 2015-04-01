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
	timeCollection(const timeCollection& from) {
		for (size_t i=0; i<from.times.size(); i++)
			times.push_back(from.times[i]->clone());
	}

	~timeCollection() {
		for (size_t i=0; i<times.size(); i++)
			delete times[i];
	}

	timeCollection& operator=(const timeCollection& from) {
		if (&from == this) {
			return *this;
		}
		times.clear();
		for (size_t i=0; i<from.times.size(); i++)
			times.push_back(from.times[i]->clone());
		return *this;
	}

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
