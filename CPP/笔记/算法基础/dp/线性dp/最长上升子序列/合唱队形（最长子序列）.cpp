#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 107;
int a[N];
int ldp[N], rdp[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	//分别找两个最长子序列
	for(int i = 1; i <= n; i++)
		for(int j = 0; j < i; j++)
			if(a[j] < a[i]) ldp[i] = max(ldp[i], ldp[j] + 1);
			
	//注意反过来求的时候i得从n-1开始（i更靠近中间）
	for(int i = n - 1; i >= 1; i--)
		for(int j = n; j > i; j--)
			if(a[i] > a[j]) rdp[i] = max(rdp[i], rdp[j] + 1);
		
	//枚举每一个人作为顶点	
	int ans = 0;
	for(int i = 1; i <= n; i++)
		ans = max(ans, ldp[i] + rdp[i]);
	
	cout << n - ans;
	
	return 0;
}
 
// 8
// 186 186 150 200 160 130 197 220
// 
// 4
