#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <cstring>
#include <cstdlib>
#include <cctype>
#include <ctime>
#include <random>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <bitset>
#include <cmath>
using namespace std;
using ll = long long;

const int N = 2e5 + 9;
int a[N], dq[N];//dqģ��deque

void solve()
{
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];

	int hh = 1, tt = 0;//hh��head,tt��tail��hh�Ƕ�����tt���ҡ�����ʼ��ʱ��Ҫ��hh��tt�ұ�

	//�����
	for (int i = 1; i <= n; i++)
	{
		//��ͷҪ��[i-k+1, i]���棬��Ҫ�ڼ�����������  ps:i-(i-k+1)=k-1,�����Ǳ����䣬����k-1+1=k,�պ��ǳ���Ϊk������
		//���ͳ��[i-k+1,i-1]������<i-k 
		while (hh <= tt && dq[hh] <= i - k) hh++;//��β��ͷ���ң������зǿգ�������ͷ�ڼ��������⣬hh++(��ͷλ������)
		while (hh <= tt && a[dq[tt]] <= a[i]) tt--;//�����βԪ��<=����,tt--���൱�ڵ�����βԪ�أ�

		dq[++tt] = i;//tt--������ƫ��1λ������++tt����

		if (i >= k) cout << a[dq[hh]] << ' ';//i>=k,����Ҫ�ȱ�����һ����������� 
	}
	cout << '\n';

	hh = 1, tt = 0;//��ն���

	//����С
	for (int i = 1; i <= n; i++)
	{
		while (hh <= tt && dq[hh] <= i - k) hh++;
		while (hh <= tt && a[dq[tt]] >= a[i]) tt--;

		dq[++tt] = i;

		if (i >= k) cout << a[dq[hh]] << ' ';
	}
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int t = 1;
	while (t--) solve();

	return 0;
}
//8 3
//0 3 1 0 - 5 2 1 8
//
//3 3 1 2 2 8
//0 0 - 5 - 5 - 5 1
