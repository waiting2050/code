#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 107;
bool d[N][N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cin >> d[i][j];
		}
	}
	
	for(int k = 1; k <= n; k++)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				//ºËÐÄ¹«Ê½
				d[i][j] |= d[i][k] & d[k][j];
			}
		}
	}
	
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			cout << d[i][j] << " \n"[j == n];
		}
	}
	
	return 0;
}

//4
//0 0 0 1
//1 0 0 0
//0 0 0 1
//0 1 0 0
//
//1 1 0 1
//1 1 0 1
//1 1 0 1
//1 1 0 1
