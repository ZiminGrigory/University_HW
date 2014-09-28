#include "stack.h"
#include <stdlib.h>
#include <limits.h>
#include <iostream>
using namespace std;

Stack *createStack()
{
	Stack *stack = new Stack;
	stack->head = NULL;
	return stack;
}

bool isEmpty(Stack *stack)
{
	return stack->head == NULL;
}

void push(Stack *stack, char value)
{
	StackElement *temp = new StackElement;
	temp->value = value;
	temp->next = stack->head;
	stack->head = temp; 
}

char top(Stack *stack)
{
	if (isEmpty(stack))
		{
			cout << "Stack is empty :(" << endl;
			return INT_MAX;
	}
	else
		return stack->head->value;
}

char pop(Stack *stack)
{
	if (isEmpty(stack))
	{
		cout << "Warning! Stack is empty!!!\n";
		return 0;
	}
	char result = top(stack);
	StackElement *tmp = stack->head;
	stack->head = stack->head->next;
	delete tmp;
	return result;
}

