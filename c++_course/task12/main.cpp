#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main()
{
	//1 Текстовый файл abc.txt содержит английские буквы, пробелы и угловые скобки (символы '<' и '>')
	//. Сосчитать, сколько букв находятся внутри скобок. Например, если файл содержит текст
	//ab < c
	//d > efg <hijk>
	//то надо напечатать 6.
	//Можно считать, что скобки расставлены правильно и не вложены, т.е. после '<' всегда идет '>'.
	ifstream in("abc.txt");
	char c;
	int flag = 0;
	int answer = 0;
	while (in >> c) {
		if (c == '<') {
			flag++;
		} else if (c == '>') {
			flag--;
		} else if (c != '\n' && c != '\r' && flag) {
			answer++;
		}
	}

	in.close();
	cout << answer << endl;

	//2 Сосчитать, сколько единичных битов в данном int ?
	int i = 8;
	int count = 0;
	while (i != 0) {
		count++;
		i = i & (i-1);
	}

	cout << count << endl;
	//больше "магии", больше "разделения и властвования", не зря же у меня книжка Генри Уорена есть
	i = 8;
	i = (i & 0x55555555) + ((i >> 1) & 0x55555555);
	i = (i & 0x33333333) + ((i >> 2) & 0x33333333);
	i = (i & 0x0f0f0f0f) + ((i >> 4) & 0x0f0f0f0f);
	i = (i & 0x00ff00ff) + ((i >> 8) & 0x00ff00ff);
	i = (i & 0x0000ffff) + ((i >> 16) & 0x0000ffff);
	cout << i << endl;


	//Сосчитать, сколько единичных битов в массиве char (очень длинном, скажем 100000 символов.)
	// Замечание: Тут надо, чтобы решение было эффективным.
	// (надо придумать что-нибудь более эффективное, чем считать биты для каждого символа).
	int table[256]{0};
	for (int j = 1; j < 256; j++) {
		i = j;
		i = (i & 0x55) + ((i >> 1) & 0x55);
		i = (i & 0x33) + ((i >> 2) & 0x33);
		i = (i & 0x0f) + ((i >> 4) & 0x0f);
		table[j] = i;
	}
	char a[100000] = "asdasfsfasfafqwfseghghywaefvawefawekyfwaefrkwaevktaweeafvaewkfwae";
	int n = strlen(a);
	long long counter = 0;
	for (int j = 0; j < n; j++) {
		counter += table[static_cast<int>(a[j])];
	}
	cout << counter << endl;


	return 0;
}

