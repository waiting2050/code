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

int dfs(int x, int y)//���꣬����
{
	if(dp[x][y]) return dp[x][y];//���仯�����Ĺؼ����� 
	
	dp[x][y] = max(dp[x][y], 1);//��ʼ�� 
	
	for(int i = 1; i <= 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		
		if(inmp(nx, ny) && a[nx][ny] < a[x][y])
		{
			dfs(nx, ny);
			dp[x][y] = max(dp[x][y], dp[nx][ny] + 1);//����Ҫ���(x,y)���£�������(nx,ny)��dp��������֪��δ֪��dfs(nx,ny)��nx,ny������֪����
			//���ѡ�����dp[nx][ny]=max(dp[nx][ny],dp[x][y]+1)����ô��ǰ����(x,y)���൱��û�б���ȷ���¹�
			//���Ǵ�����Ƶ��յ㣬��Ϊ����dp��δ֪�ģ��㲻֪���������Ƿ��и�������ϸ���㡣��ֻҪĳ�������Χ�㶼������������dp=1���յ㡣 
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
	for(int i = 1; i <= r; i++) //�Ⲣ������ͨ������dp����Ϊ���µ�·�������ǲ�ȷ���ģ��������Һʹ������µĸ��·�ʽ�������� 
	{							//������dfs�Ӹ��������	
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
