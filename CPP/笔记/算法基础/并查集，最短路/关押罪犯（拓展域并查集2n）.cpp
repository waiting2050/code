#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 1e5 + 7, N = 4e4 + 7;
struct P
{
	int u, v, w;
	
	bool operator < (const P& t) const
	{
		return w > t.w;
	}
}p[M];
int pre[N], ans;//ans初始化为0，因为有可能所有犯人被完美分开 

int find(int x)
{
	return pre[x] = (pre[x] == x ? x : find(pre[x]));
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	//因为[n+1,2n]的部分要存储[1,n]的敌人，所以初始化2n 
	for(int i = 1; i <= n << 1; i++) pre[i] = i;
	
	for(int i = 1; i <= m; i++) cin >> p[i].u >> p[i].v >> p[i].w;
	sort(p + 1, p + 1 + m);
	
	for(int i = 1; i <= m; i++)
	{
		int u = p[i].u, v = p[i].v, w = p[i].w;
		
		//同在一个集合相当于被关进同一个监狱 
		if(find(u) == find(v))
		{
			//只要影响最大的那一对，找到就break 
			ans = w;
			break;
		}
		
		//u、v不在一个监狱，将v(u)的敌人加入u(v)所在的集合（不和u在一起就只能和v在一起） 
		pre[find(u)] = find(v + n);
		pre[find(v)] = find(u + n);
	}
	
	cout << ans;
	
	return 0;
}

// 4 6
// 1 4 2534
// 2 3 3512
// 1 2 28351
// 1 3 6618
// 2 4 1805
// 3 4 12884
// 
// 3512
