#pragma once
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

struct List{
 string s;
 List *next;
};

int hashFunc(string s, int n);

void deleteEl(List *&a, string s);

List **create(int n);

void addEl(List *&a, string s);

bool isExist(List *a, string s);

void meetWords(List *a[], int n, ofstream& out);

List **filling(ifstream& inp, int n);