#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 5e3 + 10, M = 5e5 + 9;
int a[N];

void solve()
{
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	bitset<M> bs;
	bs[0] = 1;
	for (int i = 1; i <= n; i++) bs |= (bs << a[i]);//这里的左移并不是模拟加法，而是模拟可能性 

	cout << bs.count();
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//3
//1 1 5
//
//6
