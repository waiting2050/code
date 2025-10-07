#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;
int a[N][N], l[N][N], r[N][N], up[N][N];//存储矩阵，左、右、上边界 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			char ch; cin >> ch;
			if(ch == 'F') a[i][j] = 1;//1代表空。0代表有障碍 
			if(a[i][j]) up[i][j] = 1;//因为之后上边界+1更新，左右边界直接赋值 
			l[i][j] = r[i][j] = j;
		}
	}
	
	//同一行更新 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 2; j <= m; j++)//从左往右 
			if(a[i][j] && a[i][j - 1]) l[i][j] = l[i][j - 1];
			
		for(int j = m - 1; j >= 1; j--)//从右往左 
			if(a[i][j] && a[i][j + 1]) r[i][j] = r[i][j + 1];
	}
	
	int ans = 0;
	//同一列更新 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] && a[i - 1][j])
			{
				up[i][j] = up[i - 1][j] + 1;
				l[i][j] = max(l[i][j], l[i - 1][j]);//同一列之中取左边界更靠右的 
				r[i][j] = min(r[i][j], r[i - 1][j]);//同一列之中取右边界更靠左的 
			}
			if(a[i][j]) ans = max(ans, up[i][j] * (r[i][j] - l[i][j] + 1));//记得+1 
		}
	}
	
	cout << ans * 3;
	
	return 0;
}

//5 6 
//R F F F F F 
//F F F F F F 
//R R R F F F 
//F F F F F F 
//F F F F F F
//
//45
