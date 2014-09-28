#include <iostream>
#include <string>
#include "algoritm.h"
using namespace std;

int *createMassifOfHash (string s, int n, int size)
{
	int x = 3;
	int deg = 1;
	int simpleWithX = 7;
	int *massifOfHash = new int [n - size + 2];
	for (int i = 1; i <= n - size + 1; i++)
		massifOfHash[i] = 0;
	for (int i = 0; i < size; i++)
	{
		massifOfHash[1] += s[i]*x;
		x *= 3;
	}
	int index = -1;
	int xSec = x / 3;
	x = 3;
	for (int i = 2; i <= (n - size + 1); i++)
	{
		index += 1;
		massifOfHash[i] = (massifOfHash[i - 1] / x) - s[index] + (s[index + size] * xSec);
	}
	return massifOfHash;
}

int hashFunc (string s, int size)
{
	int x = 3;
	int deg = 1;
	int answer = 0;
	for (int i = 0; i < size; i++)
	{
		answer += s[i]*x;
		x *= 3;
	}
	return answer;
}

int search(int pattern, int a[], string s, string sSec)
{
	int answer = 0;
	int k = s.size() - sSec.size() + 1;
	int size = sSec.size();
	for (int i = 1; i <= k; i++)
	{
		if (a[i] == pattern)
		{
			string test = "";
			for (int j = 0; j < size; j++)
				test = test + s[j + i - 1];
			if (test == sSec)
				answer++;
		}
	}

	return answer;
}

void destroy (int a[], string s, string sSec)
{
	int k = s.size() - sSec.size() + 1;
	for (int i = 1; i <= k; i++)
		a[i] = NULL;
	delete []a;
}