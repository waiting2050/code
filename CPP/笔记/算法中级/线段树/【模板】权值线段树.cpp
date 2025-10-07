#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//权值线段树顾名思义是一个桶，里面有两个量，键和值 

const int N = 2e5 + 7;

int n = 2e5, t[N << 2];//t数组计数 

void pushup(int o) {t[o] = t[o << 1] + t[o << 1 | 1];}

//下面三个函数的递归终止条件跟用途有关，问区间的权值则终止唯一个区间；更新或者问某一个键，递归终止就在某个具体的子树 
int queryCnt(int l, int r, int s = 1, int e = n, int o = 1)//询问值 
{
	if(l <= s && e <= r) return t[o];//值用t[o]计数 
	
	int mid = (s + e) >> 1, res = 0;
	if(l <= mid) res += queryCnt(l, r, s, mid, o << 1);//注意if里的判断条件是max<=min 
	if(mid + 1 <= r) res += queryCnt(l, r, mid + 1, e, o << 1 | 1);
	
	return res;
}

int queryVal(int k, int s = 1, int e = n, int o = 1)//询问键 
{
	if(s == e) return s;//注意键是s，e，而不是t数组 
	
	//上面用的是s，e；下面用的是t数组 
	int mid = (s + e) >> 1, ls = t[o << 1];//ls即letf_sum，左边权值之和，也就是左边有多少个键 
	if(k <= ls) return queryVal(k, s, mid, o << 1);//如果询问的数在左子树 
	return queryVal(k - ls, mid + 1, e, o << 1 | 1);
}

void insert(int x, int s = 1, int e = n, int o = 1)
{
	if(s == e)//注意递归终止的条件是s，e 
	{
		t[o]++;
		return;
	}
	
	int mid = (s + e) >> 1;
	if(mid >= x) insert(x, s, mid, o << 1);
	else insert(x, mid + 1, e, o << 1 | 1);
	
	pushup(o);
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int q; cin >> q;
	while(q--)
	{
		int op; cin >> op;
		
		if(op == 1)
		{
			int x; cin >> x;
			insert(x);
		}
		else if(op == 2)
		{
			int l, r; cin >> l >> r;
			cout << queryCnt(l, r) << '\n';
		}
		else
		{
			int k; cin >> k;
			cout << queryVal(k) << '\n';
		}
	}
	
	return 0;
}

//6
//1 1
//1 2
//2 1 2
//1 1
//2 1 2
//3 3
//
//2
//3
//2
