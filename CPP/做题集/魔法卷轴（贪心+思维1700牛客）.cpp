// Problem: ħ������
// Contest: NowCoder
// URL: https://ac.nowcoder.com/acm/contest/107879/E
// Memory Limit: 512 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//˼·��������Ѱ���ֻ����ǡ����ʱ�䱬ը���У�Ҳ����˵��������ǰ��ħ���ڹؼ�ʱ����ܴ�����ը��
//���Է���һ�ֱ����״̬��������һ��ʱ��ͬʱ���������������Ѹ�ħ�ķ�ʦ��Ҫ�����Ѿ�Ԥ������󣩣���ô̰�Ŀ϶�Ҫ��������������֡�
//��ôȥ������̰�Ĳ����أ������뵽�϶�Ҫ������Ȼ�󾡿��ܰѷ�ʦ֮��ľ������󣬲����и�����ԣ����ô�϶�Ҫ��취�÷�ʦ���������߿���
//����˵���ķ�ʦ����ñ����������ڶ�λ��ʦ�����������Ӱ�����һλ��ʦ���ͱ���������ȼ�ա���Ϊʲô����ͷ������Ϊ�߽粻�ô��� 
//����Ĺ�����������ֳ�ͻ��Ҳ����ǰ���ᵽ�ı���̬����ôֱ��no����Ԥ�������Ժ󣬻�Ҫ�ж�ʱ�����������ü���
//��ΪҪ��ħ����ը��������Ҫ���룬��ȻҲ����ѡ����ǰ��ħ����һ�ж���Ҫʱ���㹻���ٸ����ӣ�1 5 5��Ԥ�����Ժ���2 4 6��
//���Ǵ��������ж�ʱ�����������ü��� 

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;

int a[N];

void solve()
{
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	sort(a + 1, a + 1 + n);
	
	map<int, int> mp;//���ﲻ��unordered_map����Ϊ֮����Ҫ��С�������map 
	for(int i = n; i >= 1; i--)
	{
		int x = a[i] - 1, y = a[i] + 1;
		
		if(!mp[y]) mp[y] = 1;
		else if(!mp[x]) mp[x] = 1;
		else
		{
			cout << "NO\n";
			return;
		}
	}
	
	ll sum = 0, pre = 0;
	for(auto& [x, y] : mp)
	{
		sum += x - pre;
		pre = x;
		sum -= 2;
		if(sum < 0)
		{
			cout << "NO\n";
			return;
		}
	}
	
	cout << "YES\n";
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int _; cin >> _;
	while(_--) solve();
	
	return 0;
}

//2
//3
//5 1 5
//2
//1 2
//
//YES
//NO
//
//
//4
//3
//3 5 5
//3
//6 6 6
//2
//2 3
//7
//41 42 42 43 43 44 46
//
//YES
//NO
//YES
//YES
