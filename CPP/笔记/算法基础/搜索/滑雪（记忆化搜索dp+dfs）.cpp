// Problem: Luogu P1434
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P1434
// Memory Limit: 125 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 107;

int a[N][N], dp[N][N], r, c;
int dx[] = {0, -1, 0, 1, 0};
int dy[] = {0, 0, -1, 0, 1};

bool inmp(int x, int y) {return x >= 1 && x <= r && y >= 1 && y <= c;}

int dfs(int x, int y)//坐标，长度
{
	if(dp[x][y]) return dp[x][y];//记忆化搜索的关键步骤 
	
	dp[x][y] = max(dp[x][y], 1);//初始化 
	
	for(int i = 1; i <= 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(inmp(nx, ny) && a[nx][ny] < a[x][y])
		{
			dfs(nx, ny);
			dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);//这里要针对(x,y)更新，而不是(nx,ny)：dp就是用已知推未知，dfs(nx,ny)后，nx,ny就是已知的了
			//如果选择更新dp[nx][ny]=max(dp[nx][ny],dp[x][y]+1)，那么当前坐标(x,y)就相当于没有被正确更新过
			//不是从起点推到终点，因为起点的dp是未知的，你不知道这个起点是否还有更优秀的上个起点。但只要某个点比周围点都矮，那他就是dp=1的终点。 
		}
	}
	
	return dp[x][y];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> r >> c;
	for(int i = 1; i <= r; i++)
		for(int j = 1; j <= c; j++)
			cin >> a[i][j];
	
	int mx = 0;
	for(int i = 1; i <= r; i++) //这并不是普通的线性dp，因为更新的路径方向是不确定的，从左往右和从上往下的更新方式并不适用 
	{							//所以用dfs从各方向更新	
		for(int j = 1; j <= c; j++)
		{
			mx = max(dfs(i, j), mx);
		}
	}
	
	cout << mx;
	
	return 0;
}

//5 5
//1 2 3 4 5
//16 17 18 19 6
//15 24 25 20 7
//14 23 22 21 8
//13 12 11 10 9
//
//
//25
