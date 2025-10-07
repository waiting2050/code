#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define int ll

//一个动态的求区间最大值的问题 

const int N = 2e5 + 7;
const int mod = 1e9 + 7;
int a[N], b[N], mx[N], n;

int lowbit(int x) {return x & -x;}

//更新以i结尾，长度为lowbit(i)的一段区间的最大值
void update(int i, int x) {for(; i <= n; i += lowbit(i)) mx[i] = max(mx[i], x);}

//核心函数 ：能跨大步就大步，不然就小步 
int query(int l, int r)
{
	int res = 0;
	//直到把区间[l,r]遍历完成 
	while(l <= r)
	{
		//设start=r-lowbit(i), 如果start在l左边，就只检查r往左边的一个数 
		res = max(res, b[r]);//注意这里是b数组，不是mx数组
		r--;
		
		//如果start在l右边，说明长度为lowbit(i)的区间都在[l,r]里面 
		for(; r - lowbit(r) >= l; r -= lowbit(r))
			res = max(mx[r], res);
	}
	
	return res;
}

signed main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	b[1] = a[1];
	update(1, b[1]);
	
	for(int i = 2; i <= n; i++)
	{
		int l = max(1ll, i - a[i]);
		int temp = query(l, i - 1);//i-1：注意区间开闭
		b[i] = a[i] * temp % mod;
		update(i, b[i]);
	}
	
	for(int i = 1; i <= n; i++) cout << b[i] << ' ';
	
	return 0;
}

