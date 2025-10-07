// Problem: С����xorͼ
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/115861/E
// Memory Limit: 2048 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//һ������Ϊ2�ļ�·����ֻҪ�м�ڵ㲻ͬ����һ����·������ABC��BAC����Ϊ�ڵ���Ȼһ�������Ƿ���ͬ����ABC��CBA��һ���ġ� 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7, P = 998244353;

vector<int> g[N];
int a[N];
ll ans;
bitset<N> vis;

void dfs(int x) //Ϊʲôdfs��д��dfs(x, pre)����Ϊ������ǿ����л��ģ���vis��ǲ��õ��Ļ� 
{
	if(vis[x]) return;
	vis[x] = 1;
	
	for(auto& y : g[x]) dfs(y);
	
	for(int i = 30; i >= 0; i--) //���ѭ�������棬c�������ֻ��2ά������ÿһλ���������нڵ� 
	{
		int c[2] = {0, 0};
		for(auto& y : g[x]) //���׷�������ÿ���½ڵ������Ľڵ�����ĵ�ǰλ�����ҳ��ֹ��Ķ�Ӧ�ڵ�����������㲢ͳ�� 
		{												//��Ӧ�ڵ㣺��ǰλ��1��������֡�1��Ŀ�����֣�ֻ��Ϊ1����Ҫ�޸� 
			int mask = a[x] >> i & 1;
			int cur = a[y] >> i & 1;
			cur ^= mask;
			
			ans = (ans + (1ll << i) * c[cur ^ 1]) % P; //ע��1���ȼ����⣬�������������ܵ��±�int 
			c[a[y] >> i & 1]++;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= m; i++)
	{
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
	}
	
	dfs(1);
	
	cout << ans;
	
	return 0;
}

// 5 5
// 1 2 3 4 5
// 1 3
// 1 5
// 1 2
// 2 5
// 2 4
// 
// 
// 35
