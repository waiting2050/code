//描述
//
//
//输入三个自然数N，i，j （1 <= i <= N，1 <= j <= N），输出在一个N * N格的棋盘中，与格子（i，j）同行、同列、同一对角线的所有格子的位置。
//
//输入
//
//输入描述 :
//输入共三行，分别输入自然数N，i，j。其中保证N <= 24且1 <= i <= N，1 <= j <= N。
//输入样例 :
//4
//2
//3
//
//输出
//
//
//输出描述 :
//输出共四行。第一行为与格子（i，j）同行的所有格子的位置，第二行为与格子（i，j）同列的所有格子的位置，第三行为从左上到右下对角线上的格子的位置，
//第四行为从左下到右上对角线上的格子的位置。
//输出样例 :
//(2, 1) (2, 2) (2, 3) (2, 4)
//(1, 3) (2, 3) (3, 3) (4, 3)
//(1, 2) (2, 3) (3, 4)
//(4, 1) (3, 2) (2, 3) (1, 4)


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

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	int x, y; cin >> x >> y;

	for (int j = 1; j <= n; j++)
		printf("(%d,%d)", x, j);
	cout << '\n';

	for (int i = 1; i <= n; i++)
		printf("(%d,%d)", i, y);
	cout << '\n';

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i - j == x - y)
				printf("(%d,%d)", i, j);
	cout << '\n';

	for (int i = n; i >= 1; i--)
		for (int j = 1; j <= n; j++)
			if (i + j == x + y)
				printf("(%d,%d)", i, j);

	return 0;
}
