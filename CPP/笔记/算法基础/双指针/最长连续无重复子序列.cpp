#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N], c[N], ans;//a是存储输入数字的数组，c是计数数组

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        ans = 0;
        for (int i = 1; i <= n; i++) c[a[i]] = 0;//重置c数组，只需要重置下标为a[i]的位置即可

        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 1, j = 0; i <= n; i++) //改变窗口左边界，i从1到n遍历
        {
            while (j < n && !c[a[j + 1]])c[a[++j]]++;   //改变窗口右边界（n+1），当j+1<=n，在c[a[j+1]]没有重复计数时，将c[a[j+1]]计数加一

            ans = max(ans, j - i + 1);  //j-i+1即序列长度，实际为(j+1)-i，j+1才是右边界
            c[a[i]]--;      //计算完长度后，将左边界的数字删去
        }

        cout << ans << '\n';
    }

    return 0;
}
