#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;
char s[N];
ll dp[N];

// ��ȡ�ַ��� "loveday" �е�λ�ã���1��ʼ��Ӧ���������򷵻� -1��
int getidx(char ch)
{
    const char str[] = "0loveday";
    for(int i = 1; i <= 7; i++)
        if(str[i] == ch) return i;

    return -1;
}

void solve()
{
    // ������������ǵó�ʼ�� 
    memset(dp, 0, sizeof(dp));
    // ���ַ����ĵڶ����ַ���ʼ���루��һ���ַ��±�Ϊ1��
    cin >> s + 1;

    // ��ʼ��dp[0]Ϊ1����ʾ���ַ��������
    dp[0] = 1;
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++)
    {
        // ��ȡ��ǰ�ַ��� "loveday" �е�λ��
        int pos = getidx(s[i]);
        // ����ַ��� "loveday" ��
        if(pos != -1)
            // ����dp���飬�ۼ��Ե�ǰ�ַ���β�������и���
            dp[pos] += dp[pos - 1];
    }

    cout << dp[7] << '\n';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while(t--) solve();

    return 0;
}

//3
//loevday
//llaolveday
//lovedayay
//
//0
//2
//3
