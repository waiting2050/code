#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//floyd除了能求最短距离还能判断从一个点能不能到另一个点 

const int N = 107;
bool a[N][N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y; cin >> x >> y;
		a[x][y] = 1;//为什么存储单向边：因为要明确强弱关系，如果存无向边的话就没有强弱关系了 
	}
	
	//判断能不能走的核心代码 
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				a[i][j] |= a[i][k] & a[k][j];
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int f = 1;
		//对每一个i枚举每一个对手，只要全部都有胜负关系，排名就能确定。 
		for(int j = 1; j <= n; j++)
		{
			if(i == j) continue;
			f = f & (a[i][j] | a[j][i]); 
		}
		ans += f;
	}
	
	cout << ans;
	
	return 0;
}

//5 5
//4 3
//4 2
//3 2
//1 2
//2 5
//
//2
