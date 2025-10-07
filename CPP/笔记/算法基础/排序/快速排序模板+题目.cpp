//2��ģ����
//
//������һ������Ϊ n���������С�
//
//����ʹ�ÿ��������������а��մ�С�����������
//
//�����ź�������а�˳�������
//
//�����ʽ
//���빲���У���һ�а������� n��
//
//�ڶ��а��� n �������������������� 1~1e9��Χ�ڣ�����ʾ�������С�
//
//�����ʽ
//�����һ�У����� n����������ʾ�ź�������С�
//
//���ݷ�Χ
//1��n��100000
//
//����������
//5
//3 1 2 4 5
//���������
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
