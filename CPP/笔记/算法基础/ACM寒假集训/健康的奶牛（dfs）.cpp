//https://www.luogu.com.cn/problem/P1460
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 30;
const int M = 20;

int cri[N], v, g, sum[N], mi = 1e9;
int dp[M][N], ans[M], temp[M];

bool check()//检查能不能喂饱牛
{
	bool flag = true;
	for(int i = 1; i <= v; i++)
	{
		if(sum[i] < cri[i])
		{
			flag = false;
			break;
		}
	}
	
	return flag;
}

void dfs(int dep, int t)//dep表示用了几种， t表示当前是第几种
{
	if(dep >= mi) return;
	
	if(check())
	{
		mi = dep;
		for(int i = 1; i <= dep; i++)
			ans[i] = temp[i];
		return;
	}
	
	if(t > g) return;//如果超过了可选择范围，返回
	
	temp[dep + 1] = t;
	for(int i = 1; i <= v; i++)
		sum[i] += dp[t][i];
	dfs(dep + 1, t + 1);//选择当前饲料
	
	for(int i = 1; i <= v; i++)
		sum[i] -= dp[t][i];
	dfs(dep, t + 1);//不选当前饲料
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> v;
	for(int i = 1; i <= v; i++) cin >> cri[i];
	
	cin >> g;
	for(int i = 1; i <= g; i++)//g表示有几种选择，v表示有几种维他命
		for(int j = 1; j <= v; j++)
			cin >> dp[i][j];
			
	dfs(0, 1);
	
	cout << mi << ' ';
	for(int i = 1; i <= mi; i++)
		cout << ans[i] << ' ';
	
	return 0;
}

// 4
// 100 200 300 400
// 3
// 50  50  50  50
// 200 300 200 300
// 900 150 389 399
// 
// 2 1 3
