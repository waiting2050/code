#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;
int a[N];

vector<int> v;

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

	int n; cin >> n;
	
	for(int i = 1; i <= n; i++) cin >> a[i];
	v.push_back(a[1]);
	
	for(int i = 2; i <= n; i++)
	{
		//��Ϊ�����ϸ񵥵�����������Ҫ��ӵȺ�
		if(v.back() <= a[i]) v.push_back(a[i]);
		//��upper_bound�ҵ���һ��������������Ԫ�أ�������lower_bound����������滻��ȵ�Ԫ�أ����³���ƫС��
		else v[upper_bound(v.begin(), v.end(), a[i]) - v.begin()] = a[i];
	}
  	
  	cout << v.size();
  	
  	return 0;
}

// 6
// 1 5 3 3 7 6
// 
// 4
