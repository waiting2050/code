#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 10;
bool a[N][N];
ll ans;

bool check()
{
	int md = 0, sd = 0, r[N], c[N];
	memset(r, 0, sizeof(r));
	memset(c, 0, sizeof(c));
	
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			r[i] += a[i][j];
			c[j] += a[i][j];
			if(i == j) md += a[i][j];
			if(i + j == 4) sd += a[i][j];
		}
	}
	
	for(int i = 0; i < 5; i++)
		if(c[i] % 5 == 0 || r[i] % 5 == 0) return false;
		
	return md % 5 != 0 && sd % 5 != 0;//用%5计算的小技巧 
}

void dfs(int sum, int w, int b)
{
	//防止一直选一种颜色的棋子选满25个 
	if(w > 13 || b > 12) return;
	
	if(sum == 25)
	{
		if(check())
			ans++;
			
		return;
	}
	
	//计算坐标的核心
	int x = sum / 5, y = sum % 5;
	
	a[x][y] = 1;
	dfs(sum + 1, w + 1, b);//选白的 
	a[x][y] = 0;
	dfs(sum + 1, w, b + 1);//选黑的 
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	dfs(0, 0, 0);
	
	cout << ans;
	
	return 0;
}

