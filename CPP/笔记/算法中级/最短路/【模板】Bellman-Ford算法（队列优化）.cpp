#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 7;
const ll INF = 2e18;

struct Edge
{
	ll y, w;
};

vector<Edge> g[N];
ll d[N];
int n;

//�����ܷ������������и�������false�� 
bool spfa(int st)
{
	queue<int> q;
	bitset<N> inq;
	vector<int> c(n + 1);

	q.push(st);
	for(int i = 1; i <= n; i++) d[i] = INF;
	d[st] = 0;

	while(q.size())
	{
		int x = q.front(); q.pop(); inq[x] = 0;
		
		for(auto& [y, w] : g[x])
		{	
			if(d[x] + w < d[y]) //�ж��Ƿ����ɳ� 
			{
				if(++c[y] >= n) return false; //�ж��Ƿ��и��� 
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
	
	int m; cin >> n >> m;
	while(m--)
	{
		int x, y, z; cin >> x >> y >> z;
		g[x].push_back({y, z});
	}
	
	if(!spfa(1)) cout << -1;
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
