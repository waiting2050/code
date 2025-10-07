#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 1e6 + 7, M = 2e3 + 7;
int a[N], c[M];//存储输入数据和计数 

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	//l,r作为双指针，ll,rr存储答案，cnt，dis作为判断条件 
	int l = 0, r = 1, ll, rr, cnt = 0, dis = 1e9;
	while(r <= n)
	{
		c[a[r]]++;//每次移动完r后，让计数器更新 
		if(c[a[r]] == 1) cnt++;//如果新加入一个画家，就让cnt++；如果只是出现多次同画家作品就不管 
		
		while(cnt == m)//从循环出来以后cnt一定是小于m的 
		{
			c[a[l]]--;//满足条件以后考虑让左端点右移，看有没有更优秀的答案 
			if(!c[a[l]]) cnt--;//如果左端点移动后有一个画家没有作品展出，就让cnt-- 
			if(r - l + 1 < dis)//如果有满足题意且区间长度更短的情况，就更新（注意不要取等，否则左端点未必是最前面的） 
			{
				ll = l, rr = r;
				dis = rr - ll + 1;
			}
			l++;
		}
		r++;//只能往右继续扩大寻找范围 
	}
	
	cout << ll << ' ' << rr;
	
	return 0;
}

//12 5
//2 5 3 1 3 2 4 1 1 5 4 3
//
//2 7
