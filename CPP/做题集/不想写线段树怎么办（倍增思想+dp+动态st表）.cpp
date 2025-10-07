#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9; // �����������󳤶�
const ll p = 1e9 + 7;  // ����ģ��

ll a[N], b[N]; // a ���������飬b ���������

ll st[N][20]; // st ��ϡ������ڿ��ٲ�ѯ�������ֵ

// ���� getMax����ѯ���� [l, r] �����ֵ
ll getMax(int l, int r){
   ll res = a[r]; // ��ʼ�����Ϊ a[r]
   int k = r - l + 1, i = r; // k �����䳤�ȣ�i �ǵ�ǰ��ѯ���Ҷ˵�
   for(int j = 20; j >= 0; --j){ // �Ӹ�λ����λ����
      if(k >> j & 1){ // ������䳤�Ȱ��� 2^j
         res = max(res, st[i][j]); // �������ֵ
         i -= (1 << j); // �ƶ���˵�
      }
   }
   return res; // �����������ֵ
}

// ���� insert����Ԫ�� x ����ϡ����������������
void insert(int i, ll x){
   st[i][0] = x; // ��ʼ�� st[i][0] Ϊ x
   for(int j = 1; i - (1 << j) + 1 >= 1; ++j){ // ���¸��߲���������ֵ
      st[i][j] = max(st[i][j - 1], st[i - (1 << (j - 1))][j - 1]);
   }
}

// ���� solve�������������߼�
void solve(){
   int n; cin >> n; // �������鳤��
   for(int i = 1; i <= n; i++) cin >> a[i]; // �������� a

   b[1] = a[1]; // ��ʼ�� b[1] Ϊ a[1]
   insert(1, b[1]); // �� b[1] ����ϡ���
   cout << b[1] << ' '; // ��� b[1]

   for(int i = 2; i <= n; ++i){ // �ӵڶ���Ԫ�ؿ�ʼ���� b[i]
      b[i] = a[i] * getMax(max(1ll, i - a[i]), i - 1) % p; // ���� b[i]
      insert(i, b[i]); // �� b[i] ����ϡ���
      cout << b[i] << ' '; // ��� b[i]
   }
}

int main(){
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); // �Ż��������
   int _ = 1;
   while(_--) solve(); // ���� solve ����
   return 0;
}
