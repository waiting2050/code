#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//排序不等式：
//顺序积之和>=乱序积之和>=逆序积之和
//容易证明当两个数组最大值对最大值，次大值对次大值，最小值对最小值的时候为所求 

const int N = 1e5 + 7, MOD = 1e8 - 3;
struct P
{
	//v记录值，idx为一种映射后的下标 
	int v, idx;
	
	bool operator < (const P& t) const
	{
		return v < t.v;
	}
};
P a[N], b[N];//处理两个数组的输入 
int c[N], t[N], n;//t为树状数组，c将a,b数组联系起来 

int lowbit(int x) {return x & -x;}

void update(int k, int x) {for(int i = k; i <= n; i += lowbit(i)) t[i] = (t[i] + x) % MOD;}

int getsum(int k)
{
	int res = 0;
	for(int i = k; i > 0; i -= lowbit(i)) res = (res + t[i]) % MOD;
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	//先按照1,2,3,4...来排，那么记升序排列（对于下标）后的数组即为原始态 
	for(int i = 1; i <= n; i++) cin >> a[i].v, a[i].idx = i;
	for(int i = 1; i <= n; i++) cin >> b[i].v, b[i].idx = i;
	
	//按值排序（升序），因为乱序不方便去一一对应 
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
	
	//按值排序后下标变为被打乱状态，再用桶c将a变为升序，此时只要再把桶中的b变为升序，那么就相当于是一一对应上了
	//ps：让b下标从无序变有序，相当于从目标态变为原始态（下标的目标态无序，但是值有序；相对的，原始态值无序，但是下标有序）
	//为什么要多绕一层建立映射关系呢？因为把数组变为升序是简单的，但想让它变为某一种确定的无序状态是复杂的
	//因此用原来的值方便找到目标态，而建立辅助的下标关系方便还原为原始态 
	for(int i = 1; i <= n; i++) c[a[i].idx] = b[i].idx;
	
	//求冒泡的交换次数相当于求逆序对个数 
	ll ans = 0;
	for(int i = 1; i <= n; i++)
	{
		ans = (ans + getsum(n) - getsum(c[i])) % MOD;
		update(c[i], 1);
	}
	
	cout << ans;
	
	return 0;
}

//4
//2 3 1 4
//3 2 1 4
//
//1
//
//
//4
//1 3 4 2
//1 7 2 4
//
//2
