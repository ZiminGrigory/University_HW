#include <iostream>
#include <vector>
#include <math.h>
#include <string.h>
#include <mTime.h>

using namespace std;

int getDistance(int a1, int b1, int a2, int b2) {
	return (a1-a2)*(a1-a2)+(b1-b2)*(b1-b2);
}

bool checkDivisions(const vector<int>& a, int el) {
	for (size_t i = 0; i < a.size(); i++) {
		if (a[i]%el) {
			return false;
		}
	}
	return true;
}

int main()
{
//	1
	cout << "Hello World!" << endl;
	int a,b;
	vector<pair<int,int> > coords;
	int mmax = -1;
	cin >> a >> b;
	while (a!=0 && b!=0) {
		for (size_t i = 0; i < coords.size(); i++) {
			mmax = max(mmax, getDistance(a,b,coords[i].first, coords[i].second));
		}
		coords.push_back(make_pair(a,b));
		cin >> a >> b;
	}
	cout << sqrt(mmax);

//	2
	char *str = "aaaaabbb";
	int mmin = 100000000;
	vector<int> counts(1, 1);
	char c = str[0];
	for (int i = 1; i < strlen(str); i++) {
		char c2 = str[i];
		if (c == c2) {
			counts.back()++;
		} else {
			c = c2;
			mmin = min(mmin, counts.back());
			counts.push_back(1);
		}
	}

	if (counts.size() == 1 && mmin >= 2) {
		cout << "yes";
	} else {
		if (mmin >= 2) {
			bool ans;
			for (int i = 2; i <= mmin; i++) {
				if (!(mmin % i)) {
					if (ans = checkDivisions(counts, i))
						break;
				}
			}
			if (ans) {
				cout << "YES";
			} else {
				cout << "no";
			}
		} else {
			cout << "no";
		}
	}


	//3
	timeCollection tc;
	tc.add(new mTime(2,15));
	tc.add(new time_with_sec(2,15,24));
	timeCollection tc2(tc);
	tc = tc2;


	return 0;
}

