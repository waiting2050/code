#include <iostream>
#include <cstdio>
#include <string>
#include <climits>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 15;
int a[N], dep, n;//a是1~n，dep是层数

bitset<N> vis;

void dfs(int dep)
{
	if (dep == n + 1) //如果满足条件就输出答案
	{
		for (int i = 1; i <= n; i++) cout << a[i] << " \n"[n == i];
		return;
	}

	for (int i = 1; i <= n; i++)//遍历所有子节点,i是从1到n，所以会由小到大输出
	{
		if (vis[i]) continue;//用标志变量判断
		vis[i] = true;//修改标志变量
		a[dep] = i;

		dfs(dep + 1);//搜索子节点，经常为x+1

		//还原标志变量，表示可转移
		vis[i] = false;
		a[dep] = 0;
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n;
	dfs(1);

	return 0;
}
