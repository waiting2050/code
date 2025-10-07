#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//最大值最短路，最小值最长路 

const int N = 5e3 + 7;
const ll INF = 2e18;

struct Edge
{
	int y, w;
};

vector<Edge> g[N];
ll d[N], n;

bool spfa(int st)
{
	vector<int> cnt(n + 1);
	bitset<N> inq;
	queue<int> q;

	for(int i = 1; i <= n; i++) d[i] = INF;
	q.push(st);
	inq[st] = 1;
	
	while(q.size())
	{
		int x = q.front(); q.pop(); inq[x] = 0;
		
		for(auto& [y, w] : g[x])
		{
			if(d[x] + w < d[y])
			{
				if(++cnt[y] >= n + 1) return false; //因为增加了一个虚拟源点，所以改成n+1 
				d[y] = d[x] + w;
				if(!inq[y]) q.push(y), inq[y] = 1;
			}
		}
	}
	
	return true;
}

void solve()
{
	int m; cin >> n >> m;
	for(int i = 1; i <= n; i++) g[i].clear();
	
	for(int i = 1; i <= m; i++) //这边只要判断是否，所以选择最短路/最长路写法均可 
	{													//代码选择了最短路写法 
		int op; cin >> op;
		
		//最短路要找小于朝向，把w放在大于指向的位置。比如xi>=xj+w，小于指向xj，那么就让xi指向xj，距离为-w 
		if(op == 1)  
		{
			int xi, xj, w; cin >> xi >> xj >> w;
			g[xj].push_back({xi, w});
		}
		else if(op == 2) 
		{
			int xi, xj, w; cin >> xi >> xj >> w;
			g[xi].push_back({xj, -w});
		}
		else //如果是等于，就互相指，距离为0 
		{
			int xi, xj; cin >> xi >> xj;
			g[xi].push_back({xj, 0}), g[xj].push_back({xi, 0});
		}
	}
	for(int i = 1; i <= n; i++) g[0].push_back({i, 0}); //构建虚拟源点，目的是使所有点联通 
	
	cout << (spfa(0) ? "YES\n" : "NO\n");
	//如果要输出在x1最大值为0情况下d[1]~d[n]最大值，要输出d[i]-d[1]；改为x1=1，则变为d[i]-d[1]+1 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

// 2
// 
// 3 3
// 1 1 2 3
// 1 1 3 3
// 2 1 3 4
// 
// 3 3
// 1 1 2 3
// 1 1 3 3
// 2 1 3 3
// 
// 
// NO
// YES
