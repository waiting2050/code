// Problem:  Longest Subsequence
// Contest: Virtual Judge - CodeForces
// URL: https://vjudge.net/problem/CodeForces-632D#author=GPT_zh
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 7;
ll a[N], c[N], d[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	
	for(int i = 1; i <= n; i++) 
	{
		cin >> a[i];
		if(a[i] <= m)//�ӿ��ٶȣ���Ȼ�ᳬʱ 
			c[a[i]]++;
	}
	
	ll ans = 1, cnt = 0;//ע������һ��Ҫд1����Ȼ������������©
	for(int i = 1; i <= m; i++)//��ÿһ����������
	{
		for(int j = i; j <= m; j += i)//��ÿһ�����ܵ�lcm
		{
			d[j] += c[i];
			if(d[j] > cnt)
			{
				cnt = d[j];
				ans = j;
			}		
		}
	}
	
	cout << ans << ' ' << cnt << '\n';
	
	for(int i = 1; i <= n; i++)
	{
		if(ans % a[i] == 0)
			cout << i << ' ';
	}
	
	return 0;
}
7 8
6 2 9 2 7 2 3

6 5
1 2 4 6 7


6 4
2 2 2 3 3 3

2 3
1 2 3
