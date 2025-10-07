// Problem: 
//     P8686 [蓝桥杯 2019 省 A] 修改数组
//   
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/P8686
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//本题思路：对数组里的每一个数，如果他指向自己，那么直接输出自身，并将其指向比他大1的数字的根；否则直接输出自己的根，
//并且指向比根大1的数字的根 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e6 + 7;
int a[N], f[N];

void init(void)
{
	for(int i = 1; i <= N; i++) f[i] = i;//注意这里的范围是N 
}

int find(int x) {return f[x] = (f[x] == x ? x : find(f[x]));}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	
	init();
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	for(int i = 1; i <= n; i++)
	{
		cout << find(a[i]) << ' ';
		f[find(a[i])] = find(find(a[i]) + 1);
	}
	
	return 0;
}

// 5
// 2 1 1 3 4
// 
// 2 1 3 4 5
