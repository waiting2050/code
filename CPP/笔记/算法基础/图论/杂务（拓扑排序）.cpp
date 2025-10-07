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
	
	//ps�����ڸ��µ��߼����� 
	//    1.��һ�������Ϊ0Ҳ����ζ��������������ˣ�������dpһ���ǺϷ���dp��ֻ���������ܸ������ĳ���
	// 	  2.����3Ҫ��1��2�����ת�ƣ�1��2���У���ô1�����һ��3��2Ҳ�����һ��3������ȡʱ��������Ǹ� 
	while(q.size())
	{
		int x = q.front(); q.pop();
		
		for(auto& y : g[x])
		{
			dp[y] = max(dp[y], dp[x] + a[y]);//ע������Ҫ̰�ģ���Ϊһ���ڵ���������ɸ��ڵ�ת�� 
			rd[y]--;
			if(!rd[y]) q.push(y);
		}
	}
	
	cout << *max_element(dp + 1, dp + 1 + n);//dp[n]δ�������ģ�����n���ܴ�1ת�ƣ���n-1��2->3->4->5ת�ƹ��� 
	
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
