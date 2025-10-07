#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//重要性质：a^b=x => a^x=b 

const int N = 1e5 + 7;

ll d[N];//定义两个符合题意的数叫数对(a,b)(默认a<b)，d为[1,n]里所有数对中a下标最大的那个下标 
//例如对于样例1 2 3 4，d[1]=0(只有1不构成数对),d[2]=0(1,2异或不等于x),d[3]=2(2^3=x，且数字2的下标是2)，d[4]=2(本身不构成数对，继承上一个数对位置而来) 
map<ll, ll> mp;//作为哈希表存储a^x=b中的b最后一次出现的位置（如果b多次出现，当然位置越靠右越好） 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll n, m, x; cin >> n >> m >> x;
	for(int i = 1; i <= n; i++)
	{
		ll y; cin >> y;
		mp[y] = i;
		d[i] = max(d[i - 1], mp[y ^ x]);//是当前新增的（如果有）更好还是之前的 
	}
	
	while(m--)
	{
		int l, r; cin >> l >> r;
		if(d[r] >= l) cout << "yes\n";
		else cout << "no\n";
	}
	
	return 0;
}

//4 4 1
//1 2 3 4
//1 4
//1 2
//2 3
//3 3
//
//yes
//no
//yes
//no
