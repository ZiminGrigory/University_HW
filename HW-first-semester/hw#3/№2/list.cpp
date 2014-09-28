#include "list.h"
#include <stdlib.h>


List *createList()
{
	List *list = new List;
	list->head = NULL;
	return list;
}

