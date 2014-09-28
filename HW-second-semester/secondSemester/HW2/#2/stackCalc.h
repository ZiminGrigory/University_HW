#pragma once
#include <iostream>
#include <string>
#include "stack.h"
using namespace std;

/**
       * @return solves the phrase entered in the postfix notation expression (example: 5 7 8 + / 5 +)
       */
double result(Stack &stack, string str);
