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

// ������ȡģ���������� (a^b) % c �Ľ��
ll qmi(ll a, ll b, ll c)
{
    a %= c;     // ��ͷ��ȡһ��ģ
    ll res = 1; // ��ʼ�����Ϊ1
    while (b) // ��ָ��b��Ϊ0ʱ����ѭ��
    {
        if (b & 1) // ���b�Ƿ�Ϊ���������λ�Ƿ�Ϊ1��
            res = res * a % c; // ������������򽫵�ǰ��a�˵�����У�����cȡģ

		//ע�⣡���������ܸ�Ϊ*=���������ȼ��������� 

        a = a * a % c; // ��aƽ������cȡģ��׼����һ�ֵ���
        b >>= 1; // b����һλ���൱��b����2��������ָ��
    }

    return res; // �������յĽ��
}

void solve()
{
    ll a, b, c; cin >> a >> b >> c;

    cout << qmi(a, b, c) << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

    return 0;
}

//2
//3 4 100
//5 2 20
//
//81
//5
