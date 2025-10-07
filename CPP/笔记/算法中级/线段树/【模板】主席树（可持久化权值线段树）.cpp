#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e5 + 7;

struct Node
{
	ll ls, rs, val;
}t[N << 5];//一般5够用了
ll n, a[N], rt[N];
vector<ll> X;

ll idx;//核心计数器

ll bin(ll x) {return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;}

//注意这个引用符号不要漏
void insert(ll& o, ll pre, ll val, int s = 1, int e = n)
{
	//分配节点
	o = ++idx;
	//复制上一版本
	t[o] = t[pre];
	//修改自身权值
	t[o].val++;
	
	//递归终止
	if(s == e) return;
	
	//决策下一步
	int mid = (s + e) >> 1;
	if(mid >= val) insert(t[o].ls, t[pre].ls, val, s, mid);
	else insert(t[o].rs, t[pre].rs, val, mid + 1, e);
}

ll queryVal(ll lo, ll ro, ll k, int s = 1, int e = n)
{
	if(s == e)	return s;
	
	//为什么t里面再套一层t：为了确定第k大的数是在左/右子树，如果只一层t对确定位置没有帮助 
	ll left_sum = t[t[ro].ls].val - t[t[lo].ls].val;//关键步骤，是ro-lo
	int mid = (s + e) >> 1;
	if(k <= left_sum) return queryVal(t[lo].ls, t[ro].ls, k, s, mid);
	return queryVal(t[lo].rs, t[ro].rs, k - left_sum, mid + 1, e);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	ll q; cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		X.push_back(a[i] = x);
	}
	
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for(int i = 1; i <= n; i++) insert(rt[i], rt[i - 1], bin(a[i]));//注意这里插入的是下标，而不是值
	
	while(q--)
	{
		ll l, r, k; cin >> l >> r >> k;
		cout << X[queryVal(rt[l - 1], rt[r], k) - 1] << '\n';
	}
	
	return 0;
}

// 6 3
// 1 3 2 5 4 6
// 1 3 2
// 2 5 3
// 3 6 4

// 2
// 4
// 6
