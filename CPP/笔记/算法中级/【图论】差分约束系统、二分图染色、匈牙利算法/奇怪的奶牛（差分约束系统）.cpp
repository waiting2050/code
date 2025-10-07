#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;
const ll INF = 2e18;

struct Edge
{
	ll y, w;
};

vector<Edge> g[N];
ll d[N];
int n;

bool spfa(int st)
{
	queue<int> q;
	bitset<N> inq;
	vector<int> cnt(n + 1);
	
	for(int i = 2; i <= n; i++) d[i] = INF; //d[1]设置为0 
	q.push(st);
	inq[st] = 1;
	
	while(q.size())
	{
		int x = q.front(); q.pop(); inq[x] = 0;
		
		for(auto& [y, w] : g[x])
		{
			if(d[x] + w < d[y])
			{
				if(++cnt[y] >= n) return false;
				d[y] = d[x] + w;
				if(!inq[y]) q.push(y), inq[y] = 1;
			}
		}
	}
	
	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int t, r; cin >> n >> t >> r;
	
	while(t--)
	{
		int x, y, w; cin >> x >> y >> w;
		g[x].push_back({y, w});
	}
	while(r--)
	{
		int x, y, w; cin >> x >> y >> w;
		g[y].push_back({x, -w});
	}
	
	if(!spfa(1)) cout << -1;
	else cout << (d[n] == INF ? -2 : d[n] - d[1] + 1); //将d[1]基准值设定为1 
	
	return 0;
}

//4 2 1
//1 3 10
//2 4 20
//2 3 3
//
//28
