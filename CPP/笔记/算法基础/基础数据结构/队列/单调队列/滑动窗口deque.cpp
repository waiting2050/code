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
int a[N];

void solve()
{
	int n, k; cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	deque<int> dq;//dq����±�

	//�����
	for (int i = 1; i <= n; i++)
	{
		//��ͷҪ��[i-k+1, i]���棬��Ҫ�ڼ�����������  ps:i-(i-k+1)=k-1,�����Ǳ����䣬����k-1+1=k,�պ��ǳ���Ϊk������
		while (dq.size() && dq.front() <= i - k) dq.pop_front();//i-k����˵���ߵ�һ���㣬�����ͷ����˵���ߣ����� 
		while (dq.size() && a[dq.back()] <= a[i]) dq.pop_back();//���ͷʼ��������

		dq.push_back(i);

		if (i >= k) cout << a[dq.front()] << ' ';//i>=k,����Ҫ�ȱ�����һ����������� 
	}
	cout << '\n';
	dq = deque<int>();//��ն���

	//����С
	for (int i = 1; i <= n; i++)
	{
		while (dq.size() && dq.front() <= i - k) dq.pop_front();
		while (dq.size() && a[dq.back()] >= a[i]) dq.pop_back();

		dq.push_back(i);

		if (i >= k) cout << a[dq.front()] << ' ';
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
