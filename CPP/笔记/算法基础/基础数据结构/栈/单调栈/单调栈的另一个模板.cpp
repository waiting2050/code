// Problem: 
//     P2947 [USACO09MAR] Look Up S
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2947
// Memory Limit: 500 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;
int a[N], ans[N];
stack<int> stk;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = n; i >= 1; i--)
	{
		while(stk.size() && a[stk.top()] <= a[i]) stk.pop();
		
		if(stk.size()) ans[i] = stk.top();
		stk.push(i);//stk里存放的是下标 
	}
	
	for(int i = 1; i <= n; i++) cout << ans[i] << '\n';
	
	return 0;
}
// 6
// 3
// 2
// 6
// 1
// 1
// 2
// 
// 3
// 3
// 0
// 6
// 6
// 0
