#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

vector<int>a;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		a.push_back(x);
	}

	sort(a.begin(), a.end());
	a.erase(unique(a.begin(), a.end()), a.end());//重点是这两行 

	for (auto& ele : a)  cout << ele << ' '; //引用了会快一点 

	return 0;
}
