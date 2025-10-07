#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;

ll a[N], w[N], prefix[N];//a��ʾ�������0��1����w��ʾ����, prefix��ʾƫ����
					
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
		for (int i = 1; i <= n; i++) prefix[i] = prefix[i - 1] + (a[i] ? -1 : 1) * w[i];//a[i] = 0�������޸ĺ�Ҫ����������1������ѼѼ���޸ĺ��ȥ

		ll fix = 0, mi = 0;				//fix��ƫ������Ҳ���Ǹı������
		for (int i = 1; i <= n; i++)
		{
			fix = max(fix, prefix[i] - mi);//prefix[i] - mi��prefix[r] - prefix[l - 1],��һ���������ӵ����//r��Ӧ��prefixҪ���,l��Ӧ��Ҫ��С
			mi = min(mi, prefix[i]);			//��fix��mi�洢֮ǰ�ȽϺ�ı����������Ƚ�//��ѭ���У�fix��mi���ϸ��£����õ������ڱ仯���������С
		}

		cout << ess + fix << '\n';
	}

	return 0;
}
