#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//Ȩֵ�߶�������˼����һ��Ͱ��������������������ֵ 

const int N = 2e5 + 7;

int n = 2e5, t[N << 2];//t������� 

void pushup(int o) {t[o] = t[o << 1] + t[o << 1 | 1];}

//�������������ĵݹ���ֹ��������;�йأ��������Ȩֵ����ֹΨһ�����䣻���»�����ĳһ�������ݹ���ֹ����ĳ����������� 
int queryCnt(int l, int r, int s = 1, int e = n, int o = 1)//ѯ��ֵ 
{
	if(l <= s && e <= r) return t[o];//ֵ��t[o]���� 
	
	int mid = (s + e) >> 1, res = 0;
	if(l <= mid) res += queryCnt(l, r, s, mid, o << 1);//ע��if����ж�������max<=min 
	if(mid + 1 <= r) res += queryCnt(l, r, mid + 1, e, o << 1 | 1);
	
	return res;
}

int queryVal(int k, int s = 1, int e = n, int o = 1)//ѯ�ʼ� 
{
	if(s == e) return s;//ע�����s��e��������t���� 
	
	//�����õ���s��e�������õ���t���� 
	int mid = (s + e) >> 1, ls = t[o << 1];//ls��letf_sum�����Ȩֵ֮�ͣ�Ҳ��������ж��ٸ��� 
	if(k <= ls) return queryVal(k, s, mid, o << 1);//���ѯ�ʵ����������� 
	return queryVal(k - ls, mid + 1, e, o << 1 | 1);
}

void insert(int x, int s = 1, int e = n, int o = 1)
{
	if(s == e)//ע��ݹ���ֹ��������s��e 
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
