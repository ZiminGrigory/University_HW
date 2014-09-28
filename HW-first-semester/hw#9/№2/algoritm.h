#pragma once
#include <iostream>
#include <string>
using namespace std;

int *createMassifOfHash (string s, int n, int size);

int hashFunc (string s, int size);

int search (int pattern, int a[], string s, string sSec);

void destroy (int a[], string s, string sSec);