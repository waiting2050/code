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

//������һ��map<string, int> mp
//mp.count(key)�᷵��0��1��ʾkey�Ƿ����
//mp.find(key)�᷵��iterator��ʾkey��λ�á��յķ���end()

void solve()
{
	map<string, int> mp;//mp[s]��ʾs������
	vector<string> v;//��ʾ�ַ�������˳��

	int n; cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s; cin >> s;
		if (mp.count(s)) mp[s]++;//Ҳ���Ըĳ�if(mp.find()!=mp.end())
		else v.push_back(s), mp[s] = 1;//Ҳ���԰�mp[s] = 1�ĳ�mp.insert({s, 1})
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
