#pragma once
#include <string>


using namespace std;

class holydays
{
public:
	holydays();
	~holydays();
	/// функция не будет ппроверять корректность данных, никто и не просил собственно
	/// и в 1 день не более 1 праздника может быть
	string whatsHolydayToday(int day, int month) const;
private:
	string calendar[13][32];

	void init();
};

void f1();
void f2();
void f3();
