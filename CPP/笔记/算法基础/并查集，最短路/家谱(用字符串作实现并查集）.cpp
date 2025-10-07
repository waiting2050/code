#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<string, string> mp;

//把并查集的类型从int改为string 
string find(string x){return mp[x] = (mp[x] == x ? x : find(mp[x]));}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	char ch;
	string fa;
	while(cin >> ch && ch != '$')
	{
		string s; cin >> s;
		if(ch == '#')
		{
			fa = s;
			if(mp[s] == "") mp[fa] = fa;//如果当前字符串没有父节点，就自己作为一个根 
		}
		else if(ch == '+') mp[s] = fa;
		else cout << s << ' ' << find(s) << '\n';
	}
	
	return 0;
}

