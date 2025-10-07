#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;

void solve()
{
	set<int> st;
	int n; cin >> n;

	for (int i = 0; i < n; i++)
	{
		int x; cin >> x;
		st.insert(x);
	}

	for (auto& ele : st) cout << ele << ' ';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
