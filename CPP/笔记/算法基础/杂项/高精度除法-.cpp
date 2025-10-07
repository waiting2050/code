#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> div(vector<int>& a, int b)
{
	vector<int> c;
	int t = 0;
	for(int i = a.size() - 1; i >= 0; i--)//除法是从高位到低位的 
	{
		t = t * 10 + a[i];
		c.push_back(t / b);
		t %= b;
	}
	reverse(c.begin(), c.end());//反转以后c数组就从低位到高位了 
	while(c.size() > 1 && !c.back()) c.pop_back();
	
	return c;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	string ta; cin >> ta;
	int b; cin >> b;
	if(!b)
	{
		cout << -1 << '\n';
		return 0;
	}
	
	vector<int> a;
	for(int i = ta.size() - 1; i >= 0; i--) a.push_back(ta[i] - '0');
	
	vector<int> ans = div(a, b);
	for(int i = ans.size() - 1; i >= 0; i--) cout << ans[i];
	
	return 0;
}

