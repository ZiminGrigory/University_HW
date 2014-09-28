#pragma once
#include <string.h>
#include <string>
using namespace std;

class Hasher
{
public:
    virtual int hashFunction(string line, int n) = 0;
};

class SimpleHasher :public Hasher
{
public:
    int hashFunction(string line, int n);
};

class NormalHasher : public Hasher
{
public:
    int hashFunction(string line, int n);
};
