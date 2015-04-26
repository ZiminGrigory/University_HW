#include "holydays.h"

holydays::holydays()
{
	init();
}

holydays::~holydays()
{
}

string holydays::whatsHolydayToday(int day, int month) const
{
	return calendar[month][day];
}

void holydays::init()
{
	for (int i = 1; i <= 12; i++) {
		for (int j = 1; j <= 31; j++) {
			calendar[i][j] = "Солнце еще высоко";
		}
	}
	calendar[1][1] = "Новый Год";
	calendar[2][23] = "день защитника отечества";
	calendar[3][8] = "8 марта";
	calendar[5][1] = "День Труда";
	calendar[5][9] = "ДЕНЬ ПОБЕДЫ";
}

