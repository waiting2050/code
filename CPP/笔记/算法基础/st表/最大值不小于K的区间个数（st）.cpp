#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7, T = 20;
ll st[N][T], lg2[N];

// ��ȡ����[l, r]�ڵ����ֵ
ll get_max(int l, int r)
{
    int k = lg2[r - l + 1]; // �������䳤�ȶ�Ӧ�����2���ݴ�k
    return max(st[l][k], st[r - (1 << k) + 1][k]); // �Ƚ������ص���������ֵ
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); // ���I/O�������ٶ�
    
    // ���봦��
    ll n, k; cin >> n >> k; // ���������Сn�Ͳ�ѯ����k
    for(int i = 1; i <= n; i++) cin >> st[i][0]; // ��������Ԫ�أ�����ʼ��ST��ĵ�һ�У�j=0����ÿ��Ԫ���Լ���Ϊһ������
    
    // Ԥ����lg2���飬���ڿ��ٲ��Һ��ʵ�kֵ
    for(int i = 2; i <= n; i++) lg2[i] = lg2[i >> 1] + 1;
    
    // ����ST������ÿһ�����ܵ����䳤��2^j�����st����
    for(int j = 1; j <= T; j++)
    {
        for(int i = 1; i + (1 << j) - 1 <= n; i++)
        {
            st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]); // �����������ֵ
        }
    }
    
    ll ans = 0; // �𰸼�����
    for(int i = 1; i <= n; i++) // ö����˵�
    {
        int l = i - 1, r = n + 1; // ��ʼ�����������ı߽�
        while(l + 1 != r) // ���ֲ�����������������Ҷ˵�
        {
            int mid = (l + r) >> 1; // �����м�λ��
            if(get_max(i, mid) >= k) r = mid; // ����������ֵ�������������Ը�С���Ҷ˵�
            else l = mid; // ���򣬳��Ը�����Ҷ˵�
        }
        
        ans += n - r + 1; // ͳ��������������������
    }
    
    cout << ans; // �����
    
    return 0;
}

// 4 3
// 1 2 3 4
// 
// 7

