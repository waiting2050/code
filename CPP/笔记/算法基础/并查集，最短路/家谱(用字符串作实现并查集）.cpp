#include <bits/stdc++.h>
using namespace std;
using ll = long long;

map<string, string> mp;

//�Ѳ��鼯�����ʹ�int��Ϊstring 
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
			if(mp[s] == "") mp[fa] = fa;//�����ǰ�ַ���û�и��ڵ㣬���Լ���Ϊһ���� 
		}
		else if(ch == '+') mp[s] = fa;
		else cout << s << ' ' << find(s) << '\n';
	}
	
	return 0;
}

