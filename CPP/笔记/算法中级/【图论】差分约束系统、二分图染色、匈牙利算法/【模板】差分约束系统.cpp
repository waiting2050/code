#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//���ֵ���·����Сֵ�· 

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
				if(++cnt[y] >= n + 1) return false; //��Ϊ������һ������Դ�㣬���Ըĳ�n+1 
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
	
	for(int i = 1; i <= m; i++) //���ֻҪ�ж��Ƿ�����ѡ�����·/�·д������ 
	{													//����ѡ�������·д�� 
		int op; cin >> op;
		
		//���·Ҫ��С�ڳ��򣬰�w���ڴ���ָ���λ�á�����xi>=xj+w��С��ָ��xj����ô����xiָ��xj������Ϊ-w 
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
		else //����ǵ��ڣ��ͻ���ָ������Ϊ0 
		{
			int xi, xj; cin >> xi >> xj;
			g[xi].push_back({xj, 0}), g[xj].push_back({xi, 0});
		}
	}
	for(int i = 1; i <= n; i++) g[0].push_back({i, 0}); //��������Դ�㣬Ŀ����ʹ���е���ͨ 
	
	cout << (spfa(0) ? "YES\n" : "NO\n");
	//���Ҫ�����x1���ֵΪ0�����d[1]~d[n]���ֵ��Ҫ���d[i]-d[1]����Ϊx1=1�����Ϊd[i]-d[1]+1 
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
