#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N], n, c;

int f(int mid)	//f���������ж��ڼ��midʱ���ܷ��¼�ͷţ
{
	int temp = 0, pre = -1e9;//preΪ��һ����ţ��ţ��λ�ã�Ҫ���õķǳ�С��ȷ����һ��λ�õ�a[1]�ᱻ��¼����Ȼ�𰸿��ܻ���1.		tempΪ�ܷż�ͷţ
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
		int mid = (l + r) >> 1;//mid��ö�ٵļ�����ӷǳ���ļ����ʼ
		if (f(mid) < c) r = mid;//����ŵ�ţ���ڱ�׼�������ұ߽���С���Ӷ���Сmid
		else l = mid;//��������߽���������mid
	}

	cout << l;

	return 0;
}
