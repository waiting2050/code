// 题目是说对一个[1,k]的子数组，要找这个数组里某个i，有a[i]>a[i+1,k]，然后求这些i的异或和。先根据样例模拟，发现新进入的数必然产生一次贡献
// 然后再找i,a[i]一定大于新加入的数，其实就是找从新加入的这个数开始的严格单调递增的序列。单调栈完美符合这样的性质，但是要注意这里的异或和是针对下标。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 1e5 + 7;

int stk[N], top, pre, a[N];

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		while(top && a[stk[top]] <= a[i]) pre ^= stk[top--];
		pre ^= i;
		cout << pre << '\n';
		stk[++top] = i;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 5
// 2 1 3 5 4

// 1
// 3
// 3
// 4
// 1