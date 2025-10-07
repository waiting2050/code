#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 107;
int a[N][N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	memset(a, 0x3f, sizeof(a));
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) a[i][i] = 0;
	for(int i = 1; i <= m; i++)
	{
		int x, y, w; cin >> x >> y >> w;
		a[x][y] = a[y][x] = w;
	}
	
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
	
	int ans = 2e9;
	//���贫���ſ���(i,j) 
	for(int i = 1; i <= n; i++)//ö��i 
	{
		for(int j = i + 1; j <= n; j++)//ö��j��ֻҪö��i+1������ͺã������ǶԳƵ� 
		{	
			int mi = 0;
			for(int x = 1; x <= n; x++)//x��y�ֱ�ö�������յ� 
			{
				for(int y = x + 1; y <= n; y++)
				{
					mi += min(a[x][y], min(a[x][i] + a[j][y], a[x][j] + a[i][y]));
				}
			}
			
			ans = min(ans, mi);
		}
	}
	
	cout << ans;
	
	return 0;
}

//4 5
//1 2 3
//1 3 6
//2 3 4
//2 4 7
//3 4 2
//
//14
