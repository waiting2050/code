#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e4 + 7;
int dis[N][17];//i��ʾ�ڵ�����j��ʾʹ�õ���Ѿ�����

//�ֲ�ͼdijkstra������һ��cnt��ʾʹ���˵���Ѿ����� 
struct Edge
{
	int x, w, cnt;
	
	bool operator < (const Edge& p) const
	{
		return w > p.w;
	}
};
vector<Edge> g[N];
int n, m, k;

void dijkstra(int st)
{
	bitset<17> vis[N];//ע������N��һά��17�Ƕ�ά 
	priority_queue<Edge> pq;
	
	memset(dis, 0x3f, sizeof(dis));
	pq.push({st, dis[st][0] = 0, 0});
	
	while(pq.size())
	{
		int t = pq.top().x, ct = pq.top().cnt; pq.pop();
		
		if(vis[t][ct]) continue;
		vis[t][ct] = 1;
		
		for(auto& y : g[t])
		{
			//Ϊʲô����if:��Ϊ����ѡ���û���
			//���ı仯һ�����������һά����һ���Ƕ������if 
			if(ct < k && dis[y.x][ct + 1] > dis[t][ct] + 0)//���+0�����滻���������Ѹĳɰ�ۣ��ͱ��+y.w/2�� 
			{
				dis[y.x][ct + 1] = dis[t][ct] + 0;
				pq.push({y.x, dis[y.x][ct + 1], ct + 1});
			}
			if(dis[y.x][ct] > dis[t][ct] + y.w)
			{
				dis[y.x][ct] = dis[t][ct] + y.w;
				pq.push({y.x, dis[y.x][ct], ct});
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m >> k;
	int s, t; cin >> s >> t;
	
	for(int i = 1; i <= m; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		g[a].push_back({b, c});
		g[b].push_back({a, c});
	}
	
	dijkstra(s);
	
	int ans = 0x7f7f7f7f;
	for(int i = 0; i <= k; i++) ans = min(ans, dis[t][i]);//ע�������Ǵ�0��k 
	
	cout << ans;
	
	return 0;
}

