// Problem: Luogu P2196
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P2196
// Memory Limit: 128 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 27;

//d记录连通性，从i到j有没有路。dp[i]表示以i为结束最多能拿的地雷数。a记录地雷数。rem表示当前节点的前驱节点是谁。 
int d[N][N], dp[N], a[N], rem[N];

void print(int x)//x是当前节点 
{
	if(!rem[x])//如果前驱节点为0，就代表结束（节点范围为[1,n] 
	{
		cout << x;
		return;
	}
	
	print(rem[x]);//递归输出前一个节点 
	cout << ' ' << x;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i < n; i++)
	{
		for(int j = i + 1; j <= n; j++)
		{
			cin >> d[i][j];
		}
	}
	
	int ans = 0, lim = 0;
	for(int i = 1; i <= n; i++)//枚举终点 
	{
		dp[i] = a[i];//初始化，只选择当前节点 
		for(int j = 1; j <= i; j++)//枚举起点，j从i以前的所有结点出发，类似于最长上升子序列 
		{
			if(d[j][i] && dp[i] < dp[j] + a[i])//只要起点与终点联通，并且当前方案更优，就更新答案并记录路径 
			{
				dp[i] = dp[j] + a[i];
				rem[i] = j;
			}
		}
		
		if(dp[i] > ans) 
		{
			ans = dp[i];
			lim = i;//lim记录最后的一个节点 
		}
	}
	
	print(lim);//递归输出 
	cout << '\n';
	
	cout << ans;
	
	return 0;
}

//5
//10 8 4 7 6
//1 1 1 0
//0 0 0
//1 1
//1
//
//1 3 4 5
//27
//
//
//
//3
//10 20 5
//0 1
//0
//
//2
//20
