#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int MOD = 1e9 + 7;

map<int, vector<int>> mp;//数据可以到1e9，用map存 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, d; cin >> n >> d;
	for(int i = 1; i <= n; i++)
	{
		int x; cin >> x;
		mp[x].push_back(i);//国家x拥有编号i的选手（注意i是从小到大的，所以等会不用再sort排序了） 
	}
	
	ll ans = 1;
	for(auto& [x, v] : mp)
	{
		ll temp = v.size() + 1;//不选择该国家任何一名选手也是一种方案 
		for(int i = 0; i < v.size(); i++)
		{
			//找到编号大于当前选手且小于当前选手+d的个数（每一个个数代表一种方案），-1排除右边界，-i不计算左边界
			//重复计数是正常的，比如1,2,3,4,d=3:1+3=4,temp=1+2;2+3=5,temp=1+2+2。也就是说(1,2)(1,3)是两种方案，而(2,3)(2,4)是两种方案 
			ll add = upper_bound(v.begin(), v.end(), v[i] + d) - v.begin() - 1 - i;
			temp += add;
		}
		ans = (ans * temp) % MOD;
	}
	
	cout << ans - 1;//排除一个选手都不选的情况（某个国家的选手可以一个都不选，但是不能所有国家的选手都一个不选） 
	
	return 0;
}

//5 2
//1 2 1 2 2 
//
//23
