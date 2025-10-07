//����
//
//
//����������Ȼ��N��i��j ��1 <= i <= N��1 <= j <= N���������һ��N * N��������У�����ӣ�i��j��ͬ�С�ͬ�С�ͬһ�Խ��ߵ����и��ӵ�λ�á�
//
//����
//
//�������� :
//���빲���У��ֱ�������Ȼ��N��i��j�����б�֤N <= 24��1 <= i <= N��1 <= j <= N��
//�������� :
//4
//2
//3
//
//���
//
//
//������� :
//��������С���һ��Ϊ����ӣ�i��j��ͬ�е����и��ӵ�λ�ã��ڶ���Ϊ����ӣ�i��j��ͬ�е����и��ӵ�λ�ã�������Ϊ�����ϵ����¶Խ����ϵĸ��ӵ�λ�ã�
//������Ϊ�����µ����϶Խ����ϵĸ��ӵ�λ�á�
//������� :
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
