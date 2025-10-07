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
int vis[N][N][3];//ע������һ��Ҫ��int���Ͷ�����bool���� 

//����˼����ֻҪ�����ε���ͬһ�����˵�����Ե�������Զ��
//�ؼ���ô�����ǣ����ͼ�Ժ��ٻص��õ㣻������һ��ͼ������һȦ�ٻ�ȥ������Ҫ��ȡģǰ������������֡� 
bool bfs(int x, int y, int lx, int ly)//x,y��ȡģ��ĵ����꣬��lx��ly��ûȡģʱ��ĵ����� 
{
	queue<P> q;
	q.push({x, y, lx, ly});
	
	while(q.size())
	{
		auto& [cx, cy, clx, cly] = q.front(); q.pop();
		
		//�ؼ�ֻҪȡģǰ��ĺ�����������겻��Ⱦ�˵���Ѿ����ͼ�� 
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
				if(ch == '#') mt[i][j] = 0;//���������ǵó�ʼ�� 
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

