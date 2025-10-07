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

const int N = 300 + 7;
const ll inf = 4e18;//0x3f3f3f3f3f3f3f3f(8��3f)Լ����4.5e18,��inf����Ϊ4e18�Ѿ��㹻��
int n, m, q;
ll d[N][N];//d[i][j]��ʾ��i��j�ľ���
//floyd����������500���£���ȨʱҲ���������Դ����Դ���·���� 
void solve()
{
	cin >> n >> m >> q;
	memset(d, 0x3f, sizeof(d));//��ÿһ���ֽڳ�ʼ��Ϊ0x3f
	
	for (int i = 1; i <= m; i++)
	{
		ll u, v, w; cin >> u >> v >> w;//��Ϊ�����رߣ�����ȡ��С����һ��
		d[u][v] = min(d[u][v], w);
	}

	for (int i = 1; i <= n; i++) d[i][i] = 0;//��Ϊ�����Ի����߳�ʼ��d��0x3fδ���޸ĵ��´𰸴��󣨱���ѯ��1 1����Ӧ����0�� �������-1�������

		for (int k = 1; k <= n; k++)//�м�ڵ�
			for (int i = 1; i <= n; i++)//���
				for (int j = 1; j <= n; j++)//����
					d[i][j] = min(d[i][j], d[i][k] + d[k][j]);//ģ�壬����

		while (q--)
		{
			int u, v; cin >> u >> v;
			cout << (d[u][v] >= inf ? -1 : d[u][v]) << '\n';
		}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//3 3 2
//1 2 5
//2 3 2
//1 3 10
//1 3
//3 1
//
//7
//- 1

