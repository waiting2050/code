#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N], n, c;

int f(int mid)	//f函数用来判断在间隔mid时，能放下几头牛
{
	int temp = 0, pre = -1e9;//pre为上一个放牛的牛棚位置，要设置的非常小，确保第一个位置的a[1]会被记录，不然答案可能会少1.		temp为能放几头牛
	for (int i = 1; i <= n; i++)
	{
		if (a[i] - pre >= mid) temp++, pre = a[i];
	}

	return temp;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	cin >> n >> c;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);

	int l = a[1], r = a[n];
	while (l + 1 != r)
	{
		int mid = (l + r) >> 1;//mid是枚举的间隔，从非常大的间隔开始
		if (f(mid) < c) r = mid;//如果放的牛少于标准，就让右边界缩小，从而缩小mid
		else l = mid;//否则让左边界增大，增大mid
	}

	cout << l;

	return 0;
}
