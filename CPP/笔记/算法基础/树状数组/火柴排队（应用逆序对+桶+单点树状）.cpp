#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//���򲻵�ʽ��
//˳���֮��>=�����֮��>=�����֮��
//����֤���������������ֵ�����ֵ���δ�ֵ�Դδ�ֵ����Сֵ����Сֵ��ʱ��Ϊ���� 

const int N = 1e5 + 7, MOD = 1e8 - 3;
struct P
{
	//v��¼ֵ��idxΪһ��ӳ�����±� 
	int v, idx;
	
	bool operator < (const P& t) const
	{
		return v < t.v;
	}
};
P a[N], b[N];//����������������� 
int c[N], t[N], n;//tΪ��״���飬c��a,b������ϵ���� 

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
	//�Ȱ���1,2,3,4...���ţ���ô���������У������±꣩������鼴Ϊԭʼ̬ 
	for(int i = 1; i <= n; i++) cin >> a[i].v, a[i].idx = i;
	for(int i = 1; i <= n; i++) cin >> b[i].v, b[i].idx = i;
	
	//��ֵ�������򣩣���Ϊ���򲻷���ȥһһ��Ӧ 
	sort(a + 1, a + 1 + n), sort(b + 1, b + 1 + n);
	
	//��ֵ������±��Ϊ������״̬������Ͱc��a��Ϊ���򣬴�ʱֻҪ�ٰ�Ͱ�е�b��Ϊ������ô���൱����һһ��Ӧ����
	//ps����b�±������������൱�ڴ�Ŀ��̬��Ϊԭʼ̬���±��Ŀ��̬���򣬵���ֵ������Եģ�ԭʼֵ̬���򣬵����±�����
	//ΪʲôҪ����һ�㽨��ӳ���ϵ�أ���Ϊ�������Ϊ�����Ǽ򵥵ģ�����������Ϊĳһ��ȷ��������״̬�Ǹ��ӵ�
	//�����ԭ����ֵ�����ҵ�Ŀ��̬���������������±��ϵ���㻹ԭΪԭʼ̬ 
	for(int i = 1; i <= n; i++) c[a[i].idx] = b[i].idx;
	
	//��ð�ݵĽ��������൱��������Ը��� 
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
