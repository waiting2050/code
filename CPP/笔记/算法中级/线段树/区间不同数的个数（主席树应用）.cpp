#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

struct Node
{
	ll ls, rs, val;
}t[N << 5];
//lst[i]Ϊ����i��һ�γ��ֵ�λ��
ll n, a[N], lst[N << 5], rt[N], idx;
vector<ll> X;

ll bin(ll x) {return lower_bound(X.begin(), X.end(), x) - X.begin() + 1;}

void insert(ll& o, ll pre, ll x, int s = 0, int e = n)
{
	o = ++idx;
	t[o] = t[pre];
	t[o].val++;
	
	if(s == e) return;
	
	int mid = (s + e) >> 1;
	if(mid >= x) insert(t[o].ls, t[pre].ls, x, s, mid);
	else insert(t[o].rs, t[pre].rs, x, mid + 1, e);
}

//��ѯĳ����[lo, ro]���ִ�С��[l,r]֮���Ȩֵ
ll query(int lo, int ro, ll l, ll r, int s = 0, int e = n)
{
	if(l <= s && e <= r) return t[ro].val - t[lo].val;

	int mid = (s + e) >> 1;
	ll res = 0;
	if(mid >= l) res += query(t[lo].ls, t[ro].ls, l, r, s, mid);
	if(mid + 1 <= r) res += query(t[lo].rs, t[ro].rs, l, r, mid + 1, e);
	
	return res;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int q; cin >> n >> q;
	for(int i = 1; i <= n; i++)
	{
		ll x; cin >> x;
		X.push_back(a[i] = x);
	}
	
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());
	for(int i = 1; i <= n; i++) 
	{
		//lst��¼ĳ������һ�γ��ֵ�λ�ã�һ��ʼ��0����������Ϊi����һ��insert��ʱ�����ľ���i
		insert(rt[i], rt[i - 1], lst[bin(a[i])]);
		lst[bin(a[i])] = i;
	}
	
	while(q--)
	{
		ll l, r; cin >> l >> r;
		
		//��˼����[l,r]���С��[0,l-1]֮�����
		cout << query(rt[l - 1], rt[r], 0, l - 1) << '\n';
	}
	
	return 0;
}

// 5 2
// 1 2 1 2 2
// 1 3
// 4 5
// 
// 2
// 1
