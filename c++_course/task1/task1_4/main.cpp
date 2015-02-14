#include <iostream>

using namespace std;

int main()
{
	int a[10] = {1, 2, 2, 1, 3, 0};
	// first:
	int i(0);
	for(; i < 10; i++){
		if (a[i] == 0){
			break;
		}
	}
	cout << "answer: " << i << endl;

	// scnd:
	i = 0;
	int *p = a;
	while (*p != 0){
		p++;
		i++;
	}
	cout << "answer: " << i << endl;
	return 0;
}
