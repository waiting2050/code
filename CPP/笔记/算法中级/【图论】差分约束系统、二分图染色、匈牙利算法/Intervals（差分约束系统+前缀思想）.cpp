#include <bits/stdc++.h>
using namespace std;
using ll = long long;

//��������ǰ׺��˼�룬���±�Ϊiλ��ʱ��ѡ���˼�����������pre[i]>=pre[i-1]+0��pre[b]>=pre[a-1]+w.
//�����������Сֵ���������· 

const int N = 5e4 + 7;
const ll INF = 2e18;

struct Edge
{
	int y, w;
};

vector<Edge> g[N];
int n, m = 5e4;
ll d[N];

bool spfa(int st) //�·���·����ֻ�������ط���1��d[i]��ֵΪ-INF��2����Ϊd[x]+w>d[y] 
{
	vector<int> cnt(m + 1);
	queue<int> q;
	bitset<N> inq;
	
	q.push(st);
	inq[st] = 1;
	for(int i = 1; i <= m; i++) d[i] = -INF; //��ͬ��1 
	
	while(q.size())
	{
		int x = q.front(); q.pop(); inq[x] = 0;
		
		for(auto& [y, w] : g[x])
		{
			if(d[x] + w > d[y]) //��ͬ��2 
			{
				if(++cnt[y] >= m + 1) return false; //�����û���������Ҳ�У���Ϊ����Ŀ˵�����߼��϶���ͨ�ģ������������Ŀ��� 
				d[y] = d[x] + w;
				if(!inq[y]) q.push(y), inq[y] = 1;
			}
		}
	}
	
	return true;
}

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	cin >> n;
	for(int i = 1; i <= n; i++)
	{
		int a, b, c; cin >> a >> b >> c;
		g[a - 1].push_back({b, c});
	}
	
	//���ù�������Դ�㣬��Ϊ����������Ĳ����Ժ�����ͼ�Ѿ�����ͨ�� 
	for(int i = 1; i <= m; i++)
	{
		g[i - 1].push_back({i, 0});
		g[i].push_back({i - 1, -1}); //��һ��λ�õ���������һ��λ�õ�����1����Ϊ������Ƕ���ÿ��λ�õ���ѡ��ѡ 
	}								//����ѡ������Ҳ����˵�����ظ�ѡ��������һ��λ�ô���2���ϣ�˵���¸�λ�õ���ѡ�˶�� 
	
	spfa(0);
	
	cout << d[m]; //��Ŀ�ʵ���[1,5e4]��Χ�Ĵ𰸣�m=5e4 
	
	return 0;
}

// 5
// 3 7 3
// 8 10 3
// 6 8 1
// 1 3 1
// 10 11 1
// 
// 6
