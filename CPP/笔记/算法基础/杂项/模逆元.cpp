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

ll p = 998244353;

// ������ȡģ���������� (a^b) % c �Ľ��
ll qmi(ll a, ll b)
{
    a %= p;     // ��ͷ��ȡһ��ģ
    ll res = 1; // ��ʼ�����Ϊ1
    while (b) // ��ָ��b��Ϊ0ʱ����ѭ��
    {
        if (b & 1) // ���b�Ƿ�Ϊ���������λ�Ƿ�Ϊ1��
            res = res * a % p; // ������������򽫵�ǰ��a�˵�����У�����cȡģ

        a = a * a % p; // ��aƽ������cȡģ��׼����һ�ֵ���
        b >>= 1; // b����һλ���൱��b����2��������ָ��
    }

    return res; // �������յĽ��
}

// ����x��ģ��Ԫ������� x * inv(x) �� 1 (mod p)�����÷���С����inv(x) = x^(p-2) mod p
ll inv(ll x) { return qmi(x, p - 2); }

ll f(ll a, ll b, ll c, ll x)
{
    return (a * x % p + b)%p * inv(c * x % p) % p;
}

void solve()
{
    ll a, b, c, q; cin >> a >> b >> c >> q;
    while (q--)
    {
        ll x; cin >> x;
        cout << f(a, b, c, x) << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

//1
//7 1 17 3
//19
//25
//1
//
//6181080
//664713299
//528482305
