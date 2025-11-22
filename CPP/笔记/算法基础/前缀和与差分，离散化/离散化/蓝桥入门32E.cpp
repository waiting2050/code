// Problem: 5. 搭雪人【算法赛】
// Contest: Lanqiao
// URL: https://www.lanqiao.cn/problems/21194/learning/?contest_id=274
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 显而易见运用差分，但是数据范围在1e9，无法直接开数组，因此选择用map记录差分的变化点，
// 然后遍历map，累加差分，记录当前差分的变化点，即可得到答案。
// 主要是你不需要关注没出现过的点，和离散化思路是一样的

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 1e5 + 7;

map<int, int> mp;
int ans[N];

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int l, r; cin >> l >> r;
		mp[l]++, mp[r + 1]--;
	}
	
	int sum = 0;
	for(auto& [x, y] : mp)
	{
		sum += y;
		if(!ans[sum]) ans[sum] = x;
	}
	
	for(int i = 1; i <= n; i++)
		cout << (ans[i] ? ans[i] : -1) << '\n';
	
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 3
// 1 1
// 2 2
// 3 3

// 1
// -1
// -1


// 2
// 1 3
// 2 4

// 1
// 2