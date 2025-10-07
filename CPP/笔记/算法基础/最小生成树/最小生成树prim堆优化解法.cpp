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

const int N = 1e5 + 9;  // ���峣�� N����ʾ���ڵ���
const ll inf = 4e18;    // ���峣�� inf����ʾ�����

ll d[N];       // d �洢intree��ĵ㵽���������ľ���
bitset<N> intree;       // bitset ��¼��Щ�ڵ��Ѿ�����������

struct Edge
{
    ll x, w;  // x ��Ŀ��ڵ㣬w �Ǳߵ�Ȩ��
    bool operator <(const Edge& u)const
    {
        return w > u.w;  // ���ȶ��а�Ȩ�ش�С��������
    }
};
vector<Edge> g[N];  // �ڽӱ��洢ͼ�ı���Ϣ

void solve()
{
    int n, m; cin >> n >> m;  // ��ȡ�ڵ��� n �ͱ��� m

    memset(d, 0x3f, sizeof(d));  // ��ʼ���������� d�����нڵ�ĳ�ʼ����Ϊ inf

    for (int i = 1; i <= m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;  // ��ȡ�� (u, v) ��Ȩ�� w
        g[u].push_back({ v, w });  // ��ӱ� (u, v)
        g[v].push_back({ u, w });  // ��ӱ� (v, u)����Ϊͼ�������
    }

    ll ans = 0;  // ��ʼ����С����������Ȩ��Ϊ 0

    priority_queue<Edge> pq;  // ���ȶ��У����ڴ洢������Ľڵ㼰�����
    pq.push({ 1, 0 });  // �����ڵ� 1 �������ȶ��У���ʼ����Ϊ 0
    d[1] = 0;  // ���ڵ� 1 �ĳ�ʼ����Ϊ 0

    while (pq.size())
    {
        int x = pq.top().x;  // ��ȡ���ȶ��ж����Ľڵ�
        pq.pop();  // �������ȶ��ж����Ľڵ�

        if (intree[x]) continue;  // ����ڵ� x �Ѿ����������У�����
        intree[x] = true;  // ���ڵ� x ���Ϊ������������

        ans += d[x];  // ���ڵ� x �ľ��� d[x] ���뵽��С����������Ȩ����
        d[x] = 0;  // ���ڵ� x �ľ�����Ϊ 0����ѡ��������Ӱ������

        for (auto& ed : g[x])
        {
            auto y = ed.x, w = ed.w;  // ��ȡ���ڽڵ� y �ͱߵ�Ȩ�� w
            if (!intree[y] && w < d[y])
            {
                d[y] = w;  // ���½ڵ� y ����С����
                pq.push({ y, w });  // ���ڵ� y �������ȶ���
            }
        }
    }

    cout << ans << '\n';  // �����С����������Ȩ��
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
