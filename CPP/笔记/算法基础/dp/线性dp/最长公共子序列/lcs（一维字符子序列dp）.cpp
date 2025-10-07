#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e3 + 7;
char s[N];
ll dp[N];

// 获取字符在 "loveday" 中的位置（从1开始对应，不存在则返回 -1）
int getidx(char ch)
{
    const char str[] = "0loveday";
    for(int i = 1; i <= 7; i++)
        if(str[i] == ch) return i;

    return -1;
}

void solve()
{
    // 多组测试样例记得初始化 
    memset(dp, 0, sizeof(dp));
    // 从字符串的第二个字符开始读入（第一个字符下标为1）
    cin >> s + 1;

    // 初始化dp[0]为1，表示空字符串的情况
    dp[0] = 1;
    int n = strlen(s + 1);
    for(int i = 1; i <= n; i++)
    {
        // 获取当前字符在 "loveday" 中的位置
        int pos = getidx(s[i]);
        // 如果字符在 "loveday" 中
        if(pos != -1)
            // 更新dp数组，累加以当前字符结尾的子序列个数
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
