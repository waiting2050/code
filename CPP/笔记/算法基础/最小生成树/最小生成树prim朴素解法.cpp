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

const int N = 1e3 + 9;  // ���峣�� N����ʾ���ڵ���
const ll inf = 4e18;    // ���峣�� inf����ʾ�����

ll a[N][N], d[N];       // a �洢ͼ���ڽӾ���d �洢intree��ĵ㵽���������ľ���
bitset<N> intree;       // bitset ��¼��Щ�ڵ��Ѿ�����������

void solve()
{
    int n, m; cin >> n >> m;  // ��ȡ�ڵ��� n �ͱ��� m

    memset(a, 0x3f, sizeof(a));  // ��ʼ���ڽӾ��� a�����бߵĳ�ʼ����Ϊ inf
    memset(d, 0x3f, sizeof(d));  // ��ʼ���������� d�����нڵ�ĳ�ʼ����Ϊ inf

    for (int i = 1; i <= n; i++) a[i][i] = 0;  // �Ի�����Ϊ 0

    for (int i = 1; i <= m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;  // ��ȡ�� (u, v) ��Ȩ�� w
        a[u][v] = min(a[u][v], w);  // �����ڽӾ��� a����ֹ���ر�
        a[v][u] = min(a[v][u], w);  // ����ͼ��˫�����
    }
    d[1] = 0;

    ll ans = 0;  // ��ʼ����С����������Ȩ��Ϊ 0

    for (int i = 1; i <= n; i++)
    {
        int u = -1;  // u ��Ҫ�ҵĵ���������������ĵ�
        for (int j = 1; j <= n; j++)
            if (!intree[j] && (u == -1 || d[j] < d[u])) u = j;  // �ҵ���������������Ľڵ� u
		
		if(d[u] >= inf) break;
        ans += d[u];
        intree[u] = true;  // ���ڵ� u ����������

        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], a[u][j]);  // ���½ڵ� j ����̾���
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t = 1; 
    while (t--) solve();

    return 0;
}

//5 7
//2 3 5
//5 3 4
//5 2 6
//1 2 1
//1 5 2
//4 5 3
//3 4 3
//
//9
