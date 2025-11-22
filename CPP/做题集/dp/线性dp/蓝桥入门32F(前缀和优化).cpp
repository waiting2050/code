// Problem: 6. 行程规划【算法赛】
// Contest: Lanqiao
// URL: https://www.lanqiao.cn/problems/21195/learning/?contest_id=274
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// dp[i]表示到第i个位置有若干种合法划分的方案数。
// 考虑这么一种情况...LQQ...Q最后一位为Q时，此时能从哪里转移，既然题目要求至少有一个L，那就往前找最近的L，此时可以将
// 所有的Q都接到最近的L后面。再将该L与这些Q接起来，那么问题就变为了找上一段结束的位置，此时要加上前面所有合法的方案数
// 假如最后一个是L呢，那么它本身就合法了，它再往前接上所有合法方案数即可，也就是Σdp[j](j<last)，这个可以用前缀和优化。

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int P = 1e9 + 7, N = 1e5 + 7;

ll dp[N], pre[N];

void solve()
{
	int n; cin >> n;
	
	int last = 0;
	dp[0] = pre[0] = 1;
	for(int i = 1; i <= n; i++)
	{
		char ch; cin >> ch;
		if(ch == 'L') last = i;
		
		if(last) dp[i] = pre[last - 1];
		else dp[i] = 0;
		
		pre[i] = (pre[i - 1] + dp[i]) % P;
	}
	
	cout << dp[n];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 3
// LLL

// 4


// 3
// LQL

// 3