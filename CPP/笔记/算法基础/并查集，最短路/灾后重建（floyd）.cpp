#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 207;
int a[N][N], t[N], n;

//�����������k�൱����ö����ת��(����)
//floyd�ĺ���������ת�㣬���Ǵ��������⣬һ����Ҫ������ö��������ת�� 
void floyd(int k)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	memset(a, 0x3f, sizeof(a));
	
	int m; cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> t[i];	
	
	for(int i = 0; i < n; i++) a[i][i] = 0;
	for(int i = 0; i < m; i++)
	{
		int u, v, w; cin >> u >> v >> w;
		a[u][v] = a[v][u] = w;
	}
	
	int q; cin >> q;
	int now = 0;
	while(q--)
	{
		int x, y, j; cin >> x >> y >> j;
		while(t[now] <= j && now < n) floyd(now++);
		
		//���x��y����û�ؽ������޷���ͨ 
		if(t[x] > j || t[y] > j || a[x][y] == 0x3f3f3f3f) cout << -1 << '\n';
		else cout << a[x][y] << '\n';
	}
	
	return 0;
}

//4 5
//1 2 3 4
//0 2 1
//2 3 1
//3 1 2
//2 1 4
//0 3 5
//4
//2 0 2
//0 1 2
//0 1 3
//0 1 4
//
//-1
//-1
//5
//4
