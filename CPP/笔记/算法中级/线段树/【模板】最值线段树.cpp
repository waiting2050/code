#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 2e5 + 7;  // ԭʼ������󳤶�

int n;                  // ʵ�����鳤��
ll a[N];                // ԭʼ���飨1-based������
ll tMax[N];             // �߶����ڵ����飨�洢�������ֵ��
ll tMin[N];             // �߶����ڵ����飨�洢������Сֵ��
ll lz[N];               // ��������飨�洢����ӵ�������
ll inf = 2e18;          // ��ʾ��������ڳ�ʼ����Сֵ��ѯ��

// ���ϸ��µ�ǰ�ڵ�����/��Сֵ���������ӽڵ�ϲ���
void pushup(int o)
{
    // ��ǰ�ڵ�����ֵ = ���ӽڵ����ֵ �� ���ӽڵ����ֵ �еĽϴ���
    tMax[o] = max(tMax[o << 1], tMax[o << 1 | 1]);
    // ��ǰ�ڵ����Сֵ = ���ӽڵ���Сֵ �� ���ӽڵ���Сֵ �еĽ�С��
    tMin[o] = min(tMin[o << 1], tMin[o << 1 | 1]);
}

// �����߶���
// s: ��ǰ�ڵ㸲�ǵ�������㣬e: �����յ㣬o: ��ǰ�ڵ��ţ����ڵ�Ϊ1��
void buildTree(int s = 1, int e = n, int o = 1)
{
    if(s == e)  // Ҷ�ӽڵ㣨���䳤��Ϊ1��
    {
        tMax[o] = tMin[o] = a[s];  // Ҷ�ӽڵ�����/��Сֵ��Ϊ����
        return;
    }
    
    int mid = (s + e) >> 1;  // �������������䣨�ȼ���(s+e)/2��
    // �ݹ鹹��������������[s, mid]��
    buildTree(s, mid, o << 1);
    // �ݹ鹹��������������[mid+1, e]��
    buildTree(mid + 1, e, o << 1 | 1);
    
    pushup(o);  // �ϲ������ӽڵ��ֵ�����µ�ǰ�ڵ�
}

// �Ե�ǰ�ڵ㸲�ǵ�����[s,e]ִ�мӷ����£��ڲ�����������
// o: ��ǰ�ڵ��ţ�x: ����ӵ�����
void update(int s, int e, int o, ll x)
{
    tMax[o] += x;  // ���ֵ��������x
    tMin[o] += x;  // ��Сֵ��������x
    lz[o] += x;    // ��¼����ǣ������ݸ��ӽڵ��������
}

// ��������ǣ�����ǰ�ڵ���������ݸ��ӽڵ㣩
void pushdown(int s, int e, int o)
{
    if(!lz[o]) return;  // ��û�д����ݵı�ǣ�ֱ�ӷ���
    
    int mid = (s + e) >> 1;       // ��������������
    int ls = o << 1;              // ���ӽڵ���
    int rs = o << 1 | 1;          // ���ӽڵ���
    
    // ����������[s, mid]�����������
    update(s, mid, ls, lz[o]);
    // ����������[mid+1, e]�����������
    update(mid + 1, e, rs, lz[o]);
    
    lz[o] = 0;  // ��ǰ�ڵ��������Ѵ��ݣ����
}

// ������£���[l, r]�����ÿ��Ԫ�ؼ���x
void add(int l, int r, ll x, int s = 1, int e = n, int o = 1)
{
    // ����ǰ�ڵ㸲�ǵ�������ȫ��[l, r]�ڣ�ֱ�Ӹ��µ�ǰ�ڵ�
    if(l <= s && e <= r)
    {
        update(s, e, o, x);
        return;
    }
    
    pushdown(s, e, o);  // ��������ǣ�ȷ���ӽڵ�ֵ��ȷ
    
    int mid = (s + e) >> 1;
    // ������������[l, r]���ص����ݹ����������
    if(mid >= l) 
        // ��������Ӧ�õ���add�ݹ飬����ֱ�ӵ���update
        // update(s, mid, o << 1, x);  // ������
        add(l, r, x, s, mid, o << 1);  // ��ȷ��
    // ������������[l, r]���ص����ݹ����������
    if(mid + 1 <= r) 
        // ����ͬ��Ӧ����add�ݹ�
        // update(mid + 1, e, o << 1 | 1, x);  // ������
        add(l, r, x, mid + 1, e, o << 1 | 1);  // ��ȷ��
    
    pushup(o);  // �ϲ����º���ӽڵ�ֵ�����µ�ǰ�ڵ�
}

// �����ѯ����[l, r]��������ֵ
ll queryMax(int l, int r, int s = 1, int e = n, int o = 1)
{
    // ����ǰ�ڵ㸲�ǵ�������ȫ��[l, r]�ڣ�ֱ�ӷ������ֵ
    if(l <= s && e <= r) return tMax[o];
    
    pushdown(s, e, o);  // ��������ǣ�ȷ���ӽڵ�ֵ��ȷ
    
    ll res = -inf;  // ��ʼ�����Ϊ������
    int mid = (s + e) >> 1;
    
    // ������������[l, r]���ص����ݹ��ѯ���������ֵ
    if(mid >= l) res = max(res, queryMax(l, r, s, mid, o << 1));
    // ������������[l, r]���ص����ݹ��ѯ���������ֵ
    if(mid + 1 <= r) res = max(res, queryMax(l, r, mid + 1, e, o << 1 | 1));
    
    return res;
}

// �����ѯ����[l, r]�������Сֵ
ll queryMin(int l, int r, int s = 1, int e = n, int o = 1)
{
    // ����ǰ�ڵ㸲�ǵ�������ȫ��[l, r]�ڣ�ֱ�ӷ�����Сֵ
    if(l <= s && e <= r) return tMin[o];
    
    pushdown(s, e, o);  // ��������ǣ�ȷ���ӽڵ�ֵ��ȷ
    
    ll res = inf;  // ��ʼ�����Ϊ������
    int mid = (s + e) >> 1;
    
    // ������������[l, r]���ص����ݹ��ѯ��������Сֵ
    if(mid >= l) res = min(res, queryMin(l, r, s, mid, o << 1));
    // ������������[l, r]���ص����ݹ��ѯ��������Сֵ
    if(mid + 1 <= r) res = min(res, queryMin(l, r, mid + 1, e, o << 1 | 1));
    
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int q;  // ��������
    cin >> n >> q;
    // ����ԭʼ���飨1-based������
    for(int i = 1; i <= n; i++) cin >> a[i];
    
    buildTree();  // �����߶���
    
    while(q--)
    {
        int op, l, r;  // op:�������ͣ�1=���£�2=��ѯ����l/r:��������
        cin >> op >> l >> r;
        if(op == 1)  // ����ӷ�����[l, r]ÿ��Ԫ�ؼ�x
        {
            ll x; cin >> x;
            add(l, r, x);
        }
        else  // �����ѯ�����[l, r]�����ֵ����Сֵ
        {
            cout << queryMax(l, r) << ' ' << queryMin(l, r) << '\n';
        }
    }
    
    return 0;
}
