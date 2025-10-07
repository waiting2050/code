//描述
//
//要求从键盘输入一批整数（不超过100个），对其从大到小排序，然后将它们输出。
//
//
//输入
//
//这批整数的个数 一批用空格分隔的整数（不超过100个）
//
//
//输出
//
//降序后输出


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
ll a[N], temp[N];

void merge_sort(ll a[], int l, int r)
{
	if (l >= r) return;
	int mid = (l + r) >> 1;

	merge_sort(a, l, mid);
	merge_sort(a, mid + 1, r);

	int i = l, j = mid + 1, k = 0;
	while (i <= mid && j <= r)
	{
		if (a[i] <= a[j]) temp[k++] = a[j++];
		else temp[k++] = a[i++];
	}
	while (i <= mid) temp[k++] = a[i++];
	while (j <= r) temp[k++] = a[j++];

	for (int m = l, n = 0; m <= r; m++, n++) a[m] = temp[n];
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];

	merge_sort(a, 1, n);

	for (int i = 1; i <= n; i++) cout << a[i] << ' ';

	return 0;
}
//15
//12 435 21 45 677 97 33 454 56 89 878 98 34 21 88
// 输出：
//878 677 454 435 98 97 89 88 56 45 34 33 21 21 12
