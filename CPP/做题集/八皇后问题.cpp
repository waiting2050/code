//描述
//
//八皇后问题，是一个古老而著名的问题，是回溯算法的典型案例。
//该问题是国际西洋棋棋手马克斯·贝瑟尔于1848年提出：在8X8格的国际象棋上摆放八个皇后，使其不能互相攻击，
//即任意两个皇后都不能处于同一行、同一列或同一斜线上，问有多少种摆法。
//高斯认为有76种方案。1854年在柏林的象棋杂志上不同的作者发表了40种不同的解，后来有人用图论的方法解出92种结果。
//要求你编程找出所有的92种放法。


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

const int N = 8;

//创建横竖，主副对角线数组
pair<int, int> r[100];
bool c[100], md[100], sd[100];//md主对角线,sd副对角线
//比如col一共8列，只需要判断某一列是否有放过就可以了，不用定义二维数组，节约空间和时间

void print()
{
	for (int i = 1; i <= N; i++)
		cout << "(" << r[i].first << "," << r[i].second << ")";
	cout << '\n';
}

void dfs(int dep)//dep是深度，也是第几排，比如第二层就是第二排
{
	if (dep > N)
	{
		print();
		return;
	}
	for (int j = 1; j <= N; j++)
	{
		if (!c[j] && !md[j - dep + N] && !sd[j + dep])
		{
			r[dep].first = dep, r[dep].second = j;
			c[j] = true, md[j - dep + N] = true, sd[dep + j] = true;

			dfs(dep + 1);

			c[j] = false, md[j - dep + N] = false, sd[dep + j] = false;
		}
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	dfs(1);

	return 0;
}
