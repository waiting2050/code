// 这一题思路简单，代码复杂。首先根据bfs求从起点到终点的最短步数w，如果该w与k奇偶性相同，那么只要w<=k就一定可以根据
// 若干次空跳（跳到某个合法点再回来）到达终点。但是只求一次最短路是不够的，得求步数为奇数时到达终点的w以及偶数时的w
// 这可由分层图bfs求得，再开一个pre记录起点到终点的路径。

// Problem: 小红玩马
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/121300/E
// Memory Limit: 1024 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define eb emplace_back
#define fi first
#define se second

const int N = 1e3 + 7;
const int INF = 0x3f3f3f3f;

struct P
{
	int x, y, w;
};

int dx[] = {0, 1, 2, 1, 2, -1, -2, -2, -1};
int dy[] = {0, 2, 1, -2, -1, 2, 1, -1, -2};
int d[N][N][2], n, m, k;
pair<int, int> pre[N][N][2];

bool inmp(int x, int y) {return x >= 1 && x <= n && y >= 1 && y <= m;}

void solve()
{
	cin >> n >> m >> k;
	int sx, sy, ex, ey; cin >> sx >> sy >> ex >> ey;
	
	queue<P> q;
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			for(int k = 0; k <= 1; k++)
				d[i][j][k] = INF;
	q.push({sx, sy, d[sx][sy][0] = 0});
	
	while(q.size())
	{
		auto[x, y, w] = q.front(); q.pop();
		
		for(int i = 1; i <= 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nw = w + 1;
			if(!inmp(nx, ny)) continue;
			if(d[nx][ny][nw & 1] == INF)
			{
				d[nx][ny][nw & 1] = nw;
				q.push({nx, ny, nw});
				pre[nx][ny][nw & 1] = {x, y};
			}
		}
	}
	
	int tm = k & 1;
	if(d[ex][ey][tm] == INF || d[ex][ey][tm] > k)
	{
		cout << "No";
		return;
	}
	
	vector<pair<int, int>> ans;
	int cx = ex, cy = ey, ct = tm;
	while(!(cx == sx && cy == sy))
	{
		ans.eb(cx, cy);
		int tx = cx, ty = cy;
		cx = pre[tx][ty][ct].fi;
		cy = pre[tx][ty][ct].se;
		ct ^= 1;
	}
	
	cx = -1, cy = -1;
	if(d[ex][ey][tm] < k)
	{
		for(int i = 1; i <= 8; i++)
		{
			int nx = sx + dx[i];
			int ny = sy + dy[i];
			if(!inmp(nx, ny)) continue;
			cx = nx, cy = ny;
			break;
		}
		
        // 这一步是必要的，否则下方第一组测试样例过不了
		if(cx == -1) 
		{
			cout << "No";
			return;
		}
	}
	
	int op = 0;
	while(ans.size() < k)
	{
		if(op) ans.eb(cx, cy);
		else ans.eb(sx, sy);
		op ^= 1;
	}
	
	reverse(ans.begin(), ans.end());
	cout << "Yes\n";
	for(auto& [x, y] : ans) cout << x << ' ' << y << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _ = 1;
	while(_--) solve();

	return 0;
}

// 1 1 2
// 1 1 1 1

// No


// 3 3 3
// 1 1 1 2

// Yes
// 2 3
// 3 1
// 1 2