#include <iostream>
#include "stack.h"
using namespace std;


bool isNumber(char i)
{
	if ((i != '+') && (i != '-') && (i != '*') && (i != '/') && (i != '(') && (i != ')'))
		return 1;
	else
		return 0;
}
bool isOperand(char i)
{
	return ((i == '+') || (i == '-') || (i == '*') || (i == '/'));
}
bool priorityFirst(char i, Stack *stack)
{
	if ((i == '+') || (i == '-'))
		return ((stack->head->value == '*') || (stack->head->value == '/') || (stack->head->value == '+') || (stack->head->value == '-'));
	else
		return 0;
}
bool prioritySecond(char i, Stack *stack)
{
	return (((i == '*') || (i == '/')) && ((stack->head->value == '*') || (stack->head->value == '/')));
}

int main()
{
	char string[20] = {};
	cout << "enter the formula \n";
	cin.getline(string, sizeof(string));
	int length = strlen(string);
	cout << "ANS = \n";
	int i = 0;
	Stack *stack = createStack();
	while (i != length)
	{
		if (isNumber(string[i]))
			cout << string[i];
		 
		if	((string[i] == '('))
			push(stack, string[i]); 
		
		if (string[i] == ')')
		{
			while (stack->head->value != '(')
				cout << pop(stack);
			pop(stack);
		}
		
		if	(isOperand(string[i]))
		{	
			while (!isEmpty(stack) && (priorityFirst(string[i], stack) || prioritySecond(string[i], stack)))
				cout << pop(stack);
			push(stack, string[i]);
		}
		i++;
	}
	while (!isEmpty(stack))
		cout << pop(stack);
	delete stack;
	int n = 0;
	cout << endl;
	std::cin >> n;
	cout << endl;
}