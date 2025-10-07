#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> a(107);
    int s = 0;
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        s = max(s, a[i]);
    }
    
    sort(a.begin() + 1, a.begin() + 1 + n);//按照木棍大小升序排列
    //一定要排序，因为之后要枚举最长边。如果不排序，比如[5,1,1,1]，那么之后枚举到1，1不是最长边，那么对答案合法性的验证就不成立了 
	//合法性：即最长边大于其余边之和 

    vector<int> dp(n * s + 1);
    dp[0] = 1;

    ll ans = 1e18;
    for(int i = 1; i <= n; i++)//将每一根木棍设置为最长木棍 
    {
        for(int j = a[i] + 1; j <= s * n; j++)//j为前面累积的可能出现的长度，和起码得比当前的最长边大（故以a[i]+1开始，两边之和大于第三边） 
        {//其实此时已经暗含了组成一个封闭图形起码三条边的条件了，当前面只有1条边时，不可能大于第2条边。当前面有两条边的时候，才会开始被考虑 
            if(dp[j])//如果有符合条件的情况 
            {
                ans = min(ans, a[i] + j + 0ll);//将当前最长边加入 
                break;
            }
        }
        for(int j = s * n; j >= a[i]; j--)//典型的01背包，枚举每一种长度的可能 
            dp[j] |= dp[j - a[i]];
    }

    if(ans > 1e17) ans = -1;
    cout << ans << endl;
}

int main() 
{
	int t; cin >> t;
	while(t--) solve();

    return 0;
}

//2
//8
//1 2 3 5 6 7 8 9
//3
//1 2 3
//
//11
//-1
