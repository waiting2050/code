//2、模板题
//
//给定你一个长度为 n的整数数列。
//
//请你使用快速排序对这个数列按照从小到大进行排序。
//
//并将排好序的数列按顺序输出。
//
//输入格式
//输入共两行，第一行包含整数 n。
//
//第二行包含 n 个整数（所有整数均在 1~1e9范围内），表示整个数列。
//
//输出格式
//输出共一行，包含 n个整数，表示排好序的数列。
//
//数据范围
//1≤n≤100000
//
//输入样例：
//5
//3 1 2 4 5
//输出样例：
//1 2 3 4 5


#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
#include <map>
#include <set>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
ll a[N];

void quicksort(ll a[], int l, int r)
{
	if (l >= r) return;
	int x = a[(l + r) >> 1], i = l - 1, j = r + 1;
	while (i < j)
	{
		do i++;
		while (a[i] < x);
		do j--;
		while (a[j] > x);
		if (i < j) swap(a[i], a[j]);
	}

	quicksort(a, l, j);
	quicksort(a, j + 1, r);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	quicksort(a, 1, n);

	for (int i = 1; i <= n; i++) cout << a[i] << ' ';

	return 0;
}
