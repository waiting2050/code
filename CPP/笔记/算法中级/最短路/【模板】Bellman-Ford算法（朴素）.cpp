#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 7;
const ll INF = 2e18 + 7;

struct Edge
{
	ll y, w;
};

vector<Edge> g[N];
ll d[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 2; i <= n; i++) d[i] = INF; //初始化不要忘 
	
	while(m--)
	{
		int x, y, z; cin >> x >> y >> z;
		g[x].push_back({y, z});
	}
	
	//进行n轮松弛，并判断第n轮是否进行了松弛操作 
	bool flag = false;
	for(int i = 1; i <= n; i++)
	{
		flag = false;
		
		//进行一轮松弛 
		for(int x = 1; x <= n; x++)
		{
			for(auto& [y, w] : g[x])
			{
				if(d[x] + w < d[y])
				{
					flag = true;
					d[y] = d[x] + w;
				}
			}
		}
	}
	
	if(flag) cout << -1;
	else for(int i = 1; i <= n; i++) cout << d[i] << ' ';
	
	return 0;
}

// 5 5
// 1 2 1
// 2 3 -2
// 3 4 1
// 4 5 6
// 1 5 -5
// 
// 0 1 -1 0 -5 
