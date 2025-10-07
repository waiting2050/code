#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;
ll a[N], dp[N], dq[N];
int hh = 1, tt = 0;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		//队头合法性 
		while(tt >= hh && dq[hh] < i - k) hh++;//跟一般的单调栈不同的是这里把对队头和队尾的判断拆开，而将对数据的处理放在中间 
		//因为一般的题目里的“dp”是事先给的，而本题的dp是处理以后得到的 
		
		dp[i] = dp[dq[hh]] + a[i];
		
		//队尾单调性 
		while(tt >= hh && dp[i] >= dp[dq[tt]]) tt--;
		
		dq[++tt] = i;
	}
	
	ll ans = 0;
	for(int i = 1; i <= n; i++) ans += dp[i];
	cout << ans;
	
	return 0;
}

// 5 3
// 1 2 3 4 5
// 
// 35
