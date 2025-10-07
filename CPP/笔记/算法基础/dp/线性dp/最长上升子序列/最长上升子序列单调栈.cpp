#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;
int a[N];

vector<int> v;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	v.push_back(a[1]);
	
	for(int i = 2; i <= n; i++)
	{
		//因为并非严格单调递增，所以要添加等号
		if(v.back() <= a[i]) v.push_back(a[i]);
		//用upper_bound找到第一个大于新增数的元素（不能用lower_bound，否则可能替换相等的元素，导致长度偏小）
		else v[upper_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
	}
  	
  	cout << v.size();
  	
  	return 0;
}

// 6
// 1 5 3 3 7 6
// 
// 4
