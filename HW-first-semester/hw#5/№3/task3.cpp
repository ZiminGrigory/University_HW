#include <iostream>
#include <stdio.h>

using namespace std;
void checkAndWrite(FILE *inp){
	char s;
	bool endOfCom = 0;
	if (inp != 0x00000000)
	{
		
		cout << "ANS =\n";
		do
		{
			s = fgetc(inp);
			if (s == '"')
				do
					s = fgetc(inp);
				while (s != '"');
			if (s == '/')
			{
				s = fgetc(inp);
				if (s == '/')
				{
					cout << s;
					cout << s;
					do
					{
						s = fgetc(inp);
						if (s != '/')
							cout << s;
					}
					while ((s != '\n')&&(!feof(inp)));
				}
				else
					if (s == '*')
					{
						do
						{
							s = fgetc(inp);
							if (s == '*')
							{
								s = fgetc(inp);
								if (s == '/')
									endOfCom = 1;
							}
						}
						while ((!endOfCom) && (!feof(inp)));
					}
			}	
		}
		while (!feof(inp));
		fclose(inp);
	}
	else 
		cout << "file not exist!!!\n";
}
int main()
{
	FILE *inp = fopen("input.txt", "r");
	int s = 0;
	//fopen, fclose, fprintf, fscanf, fseek, ftell,
	//fgets - прочитать строку.
	//Режимы открытия файлов
	//w - писать
	//r - читать
	//a - открыть для добавления
	//r+ - открыть для чтения и записи
	//w+ - открыть для чтения и записи, и грохнуть, если файл есть
	//a+ - открыть для чтения и дополнения.
	//FILE * out = fopen("ololo.txt", "w");
	//fwrite("Ololo", 1, 6, out);
	checkAndWrite(inp);

	
	cin >> s;
	cout << endl;
}