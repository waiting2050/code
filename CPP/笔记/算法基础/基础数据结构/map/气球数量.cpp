#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
#include <map>
using namespace std;
using ll = long long;

//假设有一个map<string, int> mp
//mp.count(key)会返回0或1表示key是否存在
//mp.find(key)会返回iterator表示key的位置。空的返回end()

void solve()
{
	map<string, int> mp;//mp[s]表示s的数量
	vector<string> v;//表示字符串出现顺序

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		if (mp.count(s)) mp[s]++;//也可以改成if(mp.find()!=mp.end())
		else v.push_back(s), mp[s] = 1;//也可以把mp[s] = 1改成mp.insert({s, 1})
	}

	for (auto& i : v) cout << i << ' ' << mp[i] << '\n';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t; cin >> t;
	while (t--) solve();

	return 0;
}
//2
//3
//red
//red
//blue
//5
//a
//b
//e
//d
//e

//red 2
//blue 1
//a 1
//b 1
//e 2
//d 1
