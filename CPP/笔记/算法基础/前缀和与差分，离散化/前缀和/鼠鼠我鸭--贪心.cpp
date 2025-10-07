#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

ll a[N], w[N];//a��ʾ�������0��1����w��ʾ����, prefix��ʾƫ����
					
int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--)
	{
		int n; cin >> n;

		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) cin >> w[i];

		ll ess = 0;				//ess�ǻ�������Ҳ�����޸�ǰ��ѼѼ������
		for (int i = 1; i <= n; i++) ess += a[i] * w[i];

		ll fix = 0, mx = 0;			//fix��ƫ������Ҳ���Ǹı������
		for (int i = 1; i <= n; i++)
		{
			mx = max(0ll, mx + (a[i] ? -1 : 1) * w[i]);//���õ���̰�ĵ�˼�룬��ƫ�������μ��㣬һ���Ӻ�С��0������mx��0
			fix = max(fix, mx);							//��fix�������ƫ����
		}

		cout << ess + fix << '\n';
	}

	return 0;
}
