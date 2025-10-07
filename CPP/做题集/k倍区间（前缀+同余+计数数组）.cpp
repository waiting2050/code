#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e5 + 7;
int a[N], pre[N], c[N];

//同余定理：
// 如果a，b除以c的余数相同，就称a，b对于除数c来说是同余的，且有a与b的差能被c整除．（a，b，c均为自然数）
// 例如，7，16除以3的余数相同都为1，就称7，16对于除数3来说是同余的，且7与16的差能被3整除。（7，16，3均为自然数）

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, k; cin >> n >> k;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++) pre[i] = (pre[i - 1] + a[i]) % k;//运用同余定理 
	
	ll ans = 0;
	for(int i = 0; i <= n; i++)//为什么范围从0到n ：pre[0]一定等于0，等于先初始化c[0]=1，因为如果不初始化c[0]=1,而且前缀和本身就是k的倍数， 
		ans += c[pre[i]]++;//即pre[r]本身就是k的倍数，那么ans就会少统计。而当pre[i]不是直接为0时，只有起码出现两次相同余数的时候才会被统计+1。
		 
	//总结：可以理解为pre=0是特殊情况，不需要pre[l-1]辅助就可以被统计，而其他时候pre[r]-pre[l-1]必须得同余才能被统计 
	
	cout << ans;
	
	return 0;
}

// 6 3
// 1 1 4 5 1 4
// 
// 5
