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

int pre[N];  // ���鼯���飬���ڼ�¼ÿ���ڵ�ĸ��ڵ�

// ���Ҹ��ڵ㣬������·��ѹ��
int root(int x) {return pre[x] = (pre[x] == x ? x : root(pre[x])); }

// �߽ṹ�壬������� u���յ� v ��Ȩ�� w
struct Edge
{
    ll u, v, w;
    bool operator <(const Edge& m)const
    {
        return w < m.w;  // ����С���������ʹ�߰�Ȩ�ش�С��������
    }
};

void solve()
{
    int n, m; cin >> n >> m;  // ��ȡ�ڵ��� n �ͱ��� m

    vector<Edge> es;  // �洢���еı�

    for (int i = 1; i <= m; i++)
    {
        ll u, v, w; cin >> u >> v >> w;  // ��ȡ�� (u, v) ��Ȩ�� w
        es.push_back({ u, v, w });  // ������ӵ��ߵļ�����
    }

    sort(es.begin(), es.end());  // ��Ȩ�ضԱ߽�������

    ll ans = 0;  // ��ʼ����С����������Ȩ��Ϊ 0

    for (int i = 1; i <= n; i++) pre[i] = i;  // ��ʼ�����鼯��ÿ���ڵ�ĸ��ڵ����Լ�

    for (auto& ele : es)
    {
        ll u = ele.u, v = ele.v, w = ele.w;  // ��ȡ�ߵ���� u���յ� v ��Ȩ�� w

        if (root(u) == root(v)) continue;  // ��� u �� v ��ͬһ�������У�����������
        ans += w;  // ���ߵ�Ȩ�� w ���뵽��С����������Ȩ����
        pre[root(u)] = root(v);  // �ϲ� u �� v ���ڵļ���
    }

    // ����Ƿ����нڵ㶼��ͬһ����ͨ������
    for (int i = 1; i < n; i++) if (root(i) != root(i + 1)) ans = -1;

    cout << ans << '\n';  // �����С����������Ȩ�أ�����޷�������С����������� -1
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
