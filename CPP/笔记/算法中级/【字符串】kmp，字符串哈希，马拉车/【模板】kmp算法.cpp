#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 7;

char s[N], t[N]; //s是目标串，t是模板串 
int nxt[N], n, m; //nxt数组表示前缀字符串和后缀字符串匹配的字符数，辅助快速定位的数组 

void kmp()
{
	for(int i = 2, j = 0; i <= m; i++) //求nxt 
	{
		while(j && t[j + 1] != t[i]) j = nxt[j];
		if(t[j + 1] == t[i]) j++;
		nxt[i] = j;
	}
	
	for(int i = 1, j = 0; i <= n; i++) //匹配两个串 
	{
		//t[1, j] == s[i - j, i - 1] 
		while(j && t[j + 1] != s[i]) j = nxt[j]; //如果不相等就回退 
		if(t[j + 1] == s[i]) j++; //相等就更进一步 
		if(j == m) cout << i - j + 1 << ' '; //完全匹配成功则记录答案 
	}
	cout << '\n';
	
	for(int i = 1; i <= m; i++) cout << nxt[i] << ' ';
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> s + 1 >> t + 1;
	n = strlen(s + 1), m = strlen(t + 1);
	s[n + 1] = 's', t[m + 1] = 'b'; //自己造一个使最后的字符不匹配 
	
	kmp();
	
	return 0;
}

// ABCABABA
// ABA
// 
// 4 6
// 0 0 1
