#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

const int N = 1e7 + 7;

string s(N << 1, '\0'); //必须赋初值，大小起码为2*n+3 
int p[N << 1]; //P 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n >> s;
	s.insert(s.begin(), '?');
	
	for(int i = 2 * n + 1; i >= 1; i--)
	{
		if(i & 1) s[i] = '#'; //奇数放特殊符号 
		else s[i] = s[i >> 1]; //偶数放原字符串 
	}
	s[0] = '&', s[2 * n + 2] = '^'; //两边放不同的特殊字符 
	
	int C = 0, R = 0; //C是回文中心， R是右边界 
	for(int i = 1; i <= 2 * n + 1; i++) //R左侧都是更新过的，右侧是未知的 
	{
		p[i] = i < R ? min(p[2 * C - i], R - i) : 1; //复用信息
		while(s[i - p[i]] == s[i + p[i]]) p[i]++; //暴力扩展
		if(i + p[i] > R) C = i, R = i + p[i]; //若超出右边界，更新中心与边界（谁能管到更右边，就作为C） 
	}
	
	int ans = 0;
	for(int i = 1; i <= 2 * n + 1; i++) ans =  max(ans, p[i] - 1); //p[i]-1即为修改前的以当前字符为中心的回文串长度 
	
	cout << ans;
	
	return 0;
}

// 4
// abaa
// 
// 3
