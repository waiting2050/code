#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> v, a;	//a处理输入，v处理最长上升子序列

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int x;
	while(cin >> x) a.push_back(x);
	
 	 // 根据 Dilworth 定理，求子序列划分数也是求最长上升子序列 
	 // 根据狄尔沃斯定理（Dilworth's Theorem），在偏序集中，最小链划分的数量等于最大反链的大小。
	 // 最少数量的非严格递增子序列 来覆盖所有元素等价于找到 最长严格递减子序列 的长度。
	 // 最少数量的非严格递减子序列 来覆盖所有元素等价于找到 最长严格递增子序列 的长度。
	v.push_back(a[0]);
	for(int i = 1; i < a.size(); i++)
	{
		if(a[i] > v.back()) v.push_back(a[i]);
		else v[lower_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
	}
	int h = v.size();
	v.clear();
	
	reverse(a.begin(), a.end());//拦截大于等于的
	
	v.push_back(a[0]);
	for(int i = 1; i < a.size(); i++)
	{
		if(a[i] >=v.back()) v.push_back(a[i]);
		else v[upper_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
	}
	
	cout << v.size() << '\n' << h;
  	
  	return 0;
}

//389 207 155 300 299 170 158 65
//
//6
//2
