#include <iostream>
using namespace std;
using ll = long long;

const int N = 2e5 + 10;
int c[N];

//��������
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	for (int i = 1; i <= n; i++)//���뼸��i��c[i]�ͼӼ�����������2��0����c[0]=2��
	{
		int x; cin >> x;
		c[x]++;
	}

	for (int i = 0; i <= 2e5; i++)//���������ֵ��Χ�ڱ���
	{
		for (int j = 0; j < c[i]; j++)//c[i]��i������м�������0����������м������������i
			cout << i << ' ';
	}

	cout << '\n';

	return 0;
}
