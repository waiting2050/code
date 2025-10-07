// Problem: Luogu P1113
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1113
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 7;

int a[N], dp[N], rd[N]; 
vector<int> g[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int idx;
		cin >> idx >> a[idx];
		int t;
		while(cin >> t && t) g[t].push_back(idx), rd[idx]++;
	}
	
	queue<int> q;
	for(int i = 1; i <= n; i++)
	{
		if(!rd[i]) 
		{
			q.push(i);
			dp[i] = a[i];
		}
	}
	
	//ps（关于更新的逻辑）： 
	//    1.当一个点入度为0也就意味着这个点更新完毕了，这个点的dp一定是合法的dp，只有这样才能更新它的出点
	// 	  2.比如3要求1，2完成再转移，1，2并列，那么1会更新一次3，2也会更新一次3，两者取时间更长的那个 
	while(q.size())
	{
		int x = q.front(); q.pop();
		
		for(auto& y : g[x])
		{
			dp[y] = max(dp[y], dp[x] + a[y]);//注意这里要贪心，因为一个节点可能由若干个节点转移 
			rd[y]--;
			if(!rd[y]) q.push(y);
		}
	}
	
	cout << *max_element(dp + 1, dp + 1 + n);//dp[n]未必是最大的，比如n可能从1转移，而n-1由2->3->4->5转移过来 
	
	return 0;
}

//7
//1 5 0
//2 2 1 0
//3 3 2 0
//4 6 1 0
//5 1 2 4 0
//6 8 2 4 0
//7 4 3 5 6 0
//
//23
//
//
//10
//1 3 0
//2 9 1 0
//3 2 1 2 0
//4 2 1 2 3 0
//5 12 2 0
//6 1 1 2 3 4 5 0
//7 17 3 0
//8 7 1 2 3 4 5 6 7 0
//9 13 1 3 8 0
//10 2 1 2 3 4 5 6 7 8 9 0
//
//53
