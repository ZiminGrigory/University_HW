#include "bubbleSort.h"
#include "graph.h"
#include <iostream>


void bubbleSort(int cost[],int top[], List **way, int n)
{
for (int i = n - 1; i > 1; i--)
	{
		for (int j = 1; j < i; j++)
		{
			if(cost[j] > cost[j + 1])
			{
				List *tmpThird = way[j];
				way[j] = way[j + 1];
				way[j + 1] = tmpThird;
				int tmpSec = cost[j];
				cost[j] = cost[j + 1];
				cost[j + 1] = tmpSec;
				int tmp = top[j];
				top[j] = top[j + 1];
				top[j + 1] = tmp;
			}
		}
	}
}