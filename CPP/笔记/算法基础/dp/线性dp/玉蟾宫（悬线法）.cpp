#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;
int a[N][N], l[N][N], r[N][N], up[N][N];//�洢�������ҡ��ϱ߽� 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			char ch; cin >> ch;
			if(ch == 'F') a[i][j] = 1;//1����ա�0�������ϰ� 
			if(a[i][j]) up[i][j] = 1;//��Ϊ֮���ϱ߽�+1���£����ұ߽�ֱ�Ӹ�ֵ 
			l[i][j] = r[i][j] = j;
		}
	}
	
	//ͬһ�и��� 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 2; j <= m; j++)//�������� 
			if(a[i][j] && a[i][j - 1]) l[i][j] = l[i][j - 1];
			
		for(int j = m - 1; j >= 1; j--)//�������� 
			if(a[i][j] && a[i][j + 1]) r[i][j] = r[i][j + 1];
	}
	
	int ans = 0;
	//ͬһ�и��� 
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= m; j++)
		{
			if(a[i][j] && a[i - 1][j])
			{
				up[i][j] = up[i - 1][j] + 1;
				l[i][j] = max(l[i][j], l[i - 1][j]);//ͬһ��֮��ȡ��߽�����ҵ� 
				r[i][j] = min(r[i][j], r[i - 1][j]);//ͬһ��֮��ȡ�ұ߽������� 
			}
			if(a[i][j]) ans = max(ans, up[i][j] * (r[i][j] - l[i][j] + 1));//�ǵ�+1 
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
