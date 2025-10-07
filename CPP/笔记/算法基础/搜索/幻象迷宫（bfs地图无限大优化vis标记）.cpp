// Problem: Luogu P1363
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1363
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1.5e3 + 7;

struct P
{
	int x, y, lx, ly;
};
int n, m;
int dx[] = {0, 0, 0, -1, 1};
int dy[] = {0, 1, -1, 0, 0};
bitset<N> mt[N];
int vis[N][N][3];//注意这里一定要用int类型而不是bool类型 

//核心思想是只要能两次到达同一个点就说明可以到达无穷远处
//关键怎么区分是：跨过图以后再回到该点；还是在一个图里绕了一圈再回去。就需要用取模前后的坐标来区分。 
bool bfs(int x, int y, int lx, int ly)//x,y是取模后的点坐标，而lx，ly是没取模时候的点坐标 
{
	queue<P> q;
	q.push({x, y, lx, ly});
	
	while(q.size())
	{
		auto& [cx, cy, clx, cly] = q.front(); q.pop();
		
		//关键只要取模前后的横坐标或纵坐标不相等就说明已经跨过图了 
		if(vis[cx][cy][0] && (vis[cx][cy][1] != clx || vis[cx][cy][2] != cly))
		{
			cout << "Yes\n";
			return true;
		}
		
		for(int i = 1; i <= 4; i++)
		{
			int nx = (cx + dx[i] + n) % n;
			int ny = (cy + dy[i] + m) % m;
			int nlx = clx + dx[i], nly = cly + dy[i];
			
			if(!mt[nx][ny]) continue;
			if(!vis[nx][ny][0] || vis[nx][ny][1] != nlx || vis[nx][ny][2] != nly)
			{
				vis[nx][ny][0] = 1, vis[nx][ny][1] = nlx, vis[nx][ny][2] = nly;
				q.push({nx, ny, nlx, nly});
			}
		}
	}
	
	return false;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	while(cin >> n >> m)
	{ 
		int sx, sy;
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				char ch; cin >> ch;
				if(ch == '#') mt[i][j] = 0;//多组样例记得初始化 
				else if(ch == 'S')
				{
					mt[i][j] = 1;
					sx = i, sy = j;
				}
				else mt[i][j] = 1;
			}
		}
		
		memset(vis, 0, sizeof(vis));
		if(!bfs(sx, sy, sx, sy)) cout << "No\n";
	}
	
	return 0;
}

