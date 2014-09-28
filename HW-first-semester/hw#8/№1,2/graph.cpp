#include <iostream>
#include <fstream>
#include <limits.h>
#include "graph.h"
#include "bubbleSort.h"
using namespace std;





void Dijkstra(List **a, int n, int m, ofstream &out)
{
	int *cost = new int [n + 1];
	bool *check = new bool [n + 1];
	check[1] = 0;
	cost[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		cost[i] = INT_MAX;
		check[i] = 0;
	}
	List **way = createListsOfWay(n);
	for (int i = 1; i <= n; i++)
	{
		int min = INT_MAX;
		int minIndex = 0;
		for (int j = n; j >= 1; j--)
			if ((cost[j] < min) && (check[j] == 0))
			{
				min = cost[j];
				minIndex = j;
			}
		if (a[minIndex] != NULL)
		{
			List *temp = a[minIndex];
			while(temp != NULL)
			{
				if (check[temp->top] != 1)
				{
					if (cost[temp->top] > temp->weight + cost[minIndex])
					{
						cost[temp->top] = temp->weight + cost[minIndex];
						processingWays(way, a, temp, minIndex);
					}
				}
				temp = temp->next;
			}
		}
		check[minIndex] = 1;
	}
	delete []check;
	int *top = new int [n + 1];
	for (int i = 1; i <= n; i++)
		top[i] = i;
	bubbleSort(cost, top, way, n + 1);
	for (int i = 2; i <= n; i++)
	{
		out<< "town" << top[i] << " cost " << cost[i] << " ";
		List *temp = way[i];
		out << "way from first to this town ";
		while (way[i] != NULL)
		{
			temp = way[i];
			out <<  way[i]->top << " ";
			way[i] = way[i]->next;
			delete temp;
		}
		out << endl;
	}
	delete way[1];
	delete []way;
	delete []cost;
	delete []top;
}

