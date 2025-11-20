// Problem: 图
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/120455/F
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

// 本题为基环树的内向树，不过由于每个点只有一个出边，所以不需要用比较复杂的tarjan缩点，只需要计算树长以及环的长然后拼接即可
// 内向基环树指每个树是指向环的，外向基环树则相反

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define pb push_back

const int N = 1e6 + 7;

bitset<N> vis;
int rd[N], to[N], d[N];

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) d[i] = 1;
	
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		rd[x]++;
		to[i] = x;
	}

	// 拓扑排序求树长
	queue<int> q;
	for(int i = 1; i <= n; i++) if(!rd[i]) q.push(i);
	
	while(q.size())
	{
		int x = q.front(); q.pop();

		int nx = to[x];
		d[nx] = max(d[nx], d[x] + 1);
		
		rd[nx]--;
		if(!rd[nx]) q.push(nx);
	}
	
	// 求环长并进行拼接
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		if(rd[i] && !vis[i]) // 如果一个点在环上，哪怕跑完拓扑排序入度也不为0
		{					 // vis确保环上的每个点只走一次
			int cur = i;
			int clen = 0; // 即cycle_len环长
			int brc = 0; // branch分支，即树长
			
			while(!vis[cur])
			{
				vis[cur] = 1;
				clen++; 
				
				brc = max(brc, d[cur]);
				cur = to[cur];
			}
		
			ans = max(ans, brc + clen - 1); // -1因为有一个点既在环上也在树上
		}
	}
	
	cout << ans;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 3
// 2
// 3
// 2

// 3