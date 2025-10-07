#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 37;

double a[N], m, suf[N];
int n;
int mi = 2e9;

void dfs(int dep, double sum, int cnt)
{
	if(cnt > mi || sum > m || dep > n) return;//�����֦ 
	if(sum + suf[dep + 1] < m) return;//�Ժ�׺�ļ�֦�����⣩ 

	if(fabs(sum - m) < 1e-6)
	{
		mi = min(mi, cnt);
		return;
	}
	
	dfs(dep + 1, sum + a[dep + 1], cnt);//ȫѡ
	dfs(dep + 1, sum + a[dep + 1] / 2, cnt + 1);//ѡһ��
	dfs(dep + 1, sum, cnt);//��ѡ
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> a[i];
	
	//�Ѵ�ķ�ǰ�棬�����ų��ܶ��ֿ��� 
	sort(a + 1, a + 1 + n, greater<double>());
	
	//�Ժ�׺�Ĵ���ܹؼ��������ٺܶ�����Ч����� 
	for(int i = n; i >= 1; i--) suf[i] = suf[i + 1] + a[i];
	dfs(0, 0, 0);
	
	cout << (mi == 2e9 ? -1 : mi);
	
	return 0;
}

//3 10
//1 3 13
//
//2
//
//
//5 3
//2 7 11 12 14
//
//-1
