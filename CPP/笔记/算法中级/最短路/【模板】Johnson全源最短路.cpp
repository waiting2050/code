#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e3 + 7;
const ll INF = 2e18;

struct Edge
{
	ll y, w;
	
	bool operator<(const Edge& p) const
	{
		return w > p.w;
	}
};

int n;
vector<Edge> g[N];
ll h[N], d[N][N];

bool spfa(int st)
{
	queue<int> q;
	bitset<N> inq;
	vector<int> cnt(n + 1);
	
	q.push(st);
	inq[st] = 1;
	for(int i = 1; i <= n; i++) h[i] = INF;
	h[st] = 0;
	
	while(q.size())
	{
		int x = q.front(); q.pop();
		inq[x] = 0;
		
		for(auto& [y, w] : g[x])
		{	
			if(h[x] + w < h[y])
			{
				if(++cnt[y] >= n) return false;
				h[y] = h[x] + w;
				if(!inq[y]) q.push(y), inq[y] = 1;
			}
		}
	}
	
	return true;
}

void dijkstra(int st, ll d[])
{
	priority_queue<Edge> pq;
	bitset<N> vis;
	
	for(int i = 1; i <= n; i++) d[i] = INF;
	pq.push({st, d[st] = 0});
	
	while(pq.size())
	{
		int x = pq.top().y; pq.pop();
		
		if(vis[x]) continue;
		vis[x] = 1;
		
		for(auto& [y, w] : g[x])
		{
			if(d[x] + w < d[y])
			{
				d[y] = d[x] + w;
				pq.push({y, d[y]});
			}
		}
	}
	
	for(int i = 1; i <= n; i++) //����ͨdijkstraΨһ�Ĳ�ͬ������Ҫ��ԭ 
		d[i] += -h[st] + h[i]; //��Ŀ���ȥԴ�� 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int  m; cin >> n >> m;
	while(m--)
	{
		ll x, y, z; cin >> x >> y >> z;
		g[x].push_back({y, z});
	}
	for(int i = 1; i <= n; i++) g[0].push_back({i, 0}); //��������Դ�� 
	
	if(!spfa(0)) //�Ȼ�ø����޸ĵı�Ȩ���� 
	{
		cout << "starrycoding";
		return 0;
	}
	
	for(int i = 1; i <= n; i++)
		for(auto& [y, w] : g[i]) //����һ��Ҫ&���ţ�����w�޷���ȷ�޸� 
			w += h[i] - h[y]; //�޸ı�Ȩ��ȷ��wһ���ǷǸ��� 
	
	for(int i = 1; i <= n; i++) dijkstra(i, d[i]);
	
	int q; cin >> q;
	while(q--)
	{
		int x, y; cin >> x >> y;
		if(d[x][y] >= INF >> 1) cout << "noway\n"; //��Ϊ��Ȩ��ԭ�����Ժ�d[x][y]���ܻ���С��INF������INF/2�ж� 
		else cout << d[x][y] << '\n';
	}
	
	return 0;
}

// 7 20
// 1 7 190
// 4 2 57
// 2 1 -78
// 1 5 81
// 7 6 -63
// 7 6 -78
// 2 1 -39
// 1 3 154
// 2 3 5
// 6 3 70
// 4 3 -30
// 1 3 144
// 2 3 14
// 5 3 158
// 1 6 128
// 1 3 110
// 7 1 -62
// 3 1 68
// 6 5 -75
// 1 3 94
// 3
// 3 7
// 3 1
// 2 6
// 
// 258
// 68
// 34
// 
// 
// 3 16
// 1 3 -91
// 2 1 92
// 1 3 13
// 2 3 173
// 3 1 104
// 1 2 75
// 1 3 -59
// 2 3 184
// 2 1 153
// 3 1 101
// 2 3 94
// 3 1 151
// 2 1 -24
// 3 1 2
// 1 3 -6
// 2 3 61
// 7
// 3 1
// 2 1
// 2 1
// 3 2
// 3 3
// 3 3
// 1 3
// 
// starrycoding
