#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//floyd����������̾��뻹���жϴ�һ�����ܲ��ܵ���һ���� 

const int N = 107;
bool a[N][N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= m; i++)
	{
		int x, y; cin >> x >> y;
		a[x][y] = 1;//Ϊʲô�洢����ߣ���ΪҪ��ȷǿ����ϵ�����������ߵĻ���û��ǿ����ϵ�� 
	}
	
	//�ж��ܲ����ߵĺ��Ĵ��� 
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				a[i][j] |= a[i][k] & a[k][j];
	
	int ans = 0;
	for(int i = 1; i <= n; i++)
	{
		int f = 1;
		//��ÿһ��iö��ÿһ�����֣�ֻҪȫ������ʤ����ϵ����������ȷ���� 
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
