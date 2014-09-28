#include "hasher.h"


int SimpleHasher::hashFunction(string line, int n)
{
    int resultMain = 0;
    int f = line.length();
    for (int i = 0; i < f; i++)
        resultMain = resultMain + line[i];
    return resultMain % n;
}

int NormalHasher::hashFunction(string line, int n)
{
    int resultMain = 0;
    int f = line.length();
    for (int i = 0; i < f; i++)
        resultMain = resultMain + (7 * line[i] * (line[i] % 3 + i));
    return resultMain % n;
}
