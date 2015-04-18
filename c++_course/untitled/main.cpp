#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <functional>

using namespace std;

int main()
{
	vector<vector<int>> vec{{1,23,5,1},{-1,-1,1},{1,0,0,0}};
	bool ans = all_of(vec.begin(), vec.end()
					  , [](vector<int> a)
						{return any_of(a.begin(), a.end(), [](int a){return a>0;})
				;});
	cout << ans;
	return 0;
}
