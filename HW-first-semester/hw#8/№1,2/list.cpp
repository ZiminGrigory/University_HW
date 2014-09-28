#include "graph.h"

List **createAndFilling(int n, int m, ifstream &inp)
{
	List **a = new List *[n + 1];
	for (int i = 0; i <= n; i++)
		a[i] = NULL;
	int topFirst = 0;
	int topSec = 0;
	int weight = 0;
	for (int i = 1; i <= m; i++)
	{
		inp >> topFirst >> topSec >> weight;
		if (a[topFirst] == NULL)
		{
			a[topFirst] = new List;
			a[topFirst]->top = topSec;
			a[topFirst]->weight = weight;
			a[topFirst]->next = NULL;
		}
		else
		{
			List *temp = a[topFirst];
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new List;
			temp->next->top = topSec;
			temp->next->weight = weight;
			temp->next->next = NULL;
		}
		if (a[topSec] == NULL)
		{
			a[topSec] = new List;
			a[topSec]->top = topFirst;
			a[topSec]->weight = weight;
			a[topSec]->next = NULL;
		}
		else
		{
			List *temp = a[topSec];
			while (temp->next != NULL)
				temp = temp->next;
			temp->next = new List;
			temp->next->top = topFirst;
			temp->next->weight = weight;
			temp->next->next = NULL;
		}
	}
	return a;
}

void deleteWay(List *&way)
{
	List *temp = way;
	while (way != NULL)
	{
		temp = way;
		way = way->next;
		delete temp;
	}
}

void deleteGraph(List **&a, int n)
{
	for (int i = 1; i <= n; i++)
		deleteWay(a[i]);
	delete []a;
}

List **createListsOfWay(int n)
{
	List **way = new List *[n + 1];
	for (int i = 1; i <= n; i++)
		way[i] = NULL;
	return way;
}

void processingWays(List **&way, List **a, List *temp, int minIndex)
{
	deleteWay(way[temp->top]);
	way[temp->top] = NULL;
	List *tmp = way[minIndex];
	if (tmp != NULL)
		{
			way[temp->top] = new List;
			List *head = way[temp->top];
			way[temp->top]->top = tmp->top;
			tmp = tmp->next;
			way[temp->top]->next = NULL;
			while (tmp != NULL)
			{
				way[temp->top]->next = new List;
				way[temp->top]->next->top = tmp->top;
				way[temp->top] = way[temp->top]->next;
				tmp = tmp->next;
				way[temp->top]->next = NULL;
			}
			way[temp->top] = head;
		}
		if (way[temp->top] != NULL)
		{
			List *tmp = way[temp->top];
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new List;
			tmp->next->top = minIndex;
			tmp->next->next = NULL;
		}
		else
		{
			way[temp->top] = new List;
			way[temp->top]->top = minIndex;
			way[temp->top]->next = NULL;
		}
}