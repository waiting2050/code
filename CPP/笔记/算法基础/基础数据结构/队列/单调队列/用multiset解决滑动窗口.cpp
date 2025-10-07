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

const int N = 2e5 + 9;
int a[N], mx[N], mi[N];

void solve()
{
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	multiset<int> st;//st处理过程
	
	for (int i = 1; i <= n; i++)
	{
		st.insert(a[i]);
		if (i >= k) mi[i] = *st.begin(), mx[i] = *st.rbegin(), st.erase(st.find(a[i - k + 1]));//当起码遍历到第一个窗口，记录最大最小值，并且消除窗口最左边的元素
	}

	for (int i = k; i <= n; i++) cout << mx[i] << " \n"[i == n];//i!=n,输出空格，i==n输出换行
	for (int i = k; i <= n; i++) cout << mi[i] << " \n"[i == n];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//8 3
//0 3 1 0 - 5 2 1 8
//
//3 3 1 2 2 8
//0 0 - 5 - 5 - 5 1
