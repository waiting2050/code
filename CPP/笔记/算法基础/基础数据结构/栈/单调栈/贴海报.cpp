#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int N = 3e5;
int a[N], stk[N];

int main()
{
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	int n; cin >> n;
	
	int d; 
	for(int i = 1; i <= n; i++) cin >> d >> a[i];
	
	int top = 0, ans = 0;
	for(int i = 1; i <= n; i++)
	{
		//ά��һ���ϸ񵥵�������ջ 
		while(top && a[stk[top]] > a[i]) top--;
		
		//��ѭ�������Ժ�a[stk[top]]�϶�<��=a[i]��������ڣ���ôǰ���һ��¥�������ˣ����״̬����ת�Ƹ���
		//���С�ڣ���ô��û��״̬ת�ƣ�������¿�һ�ź���
		//���ʾ����Ҹ�Ԫ������������С�ڵ�������Ԫ��
		if(a[stk[top]] ^  a[i]) ans++;
		
		stk[++top] = i;
	}
	
	cout << ans;
	
	return 0;
}

//5
//1 2
//1 3
//2 2
//2 5
//1 4
//
//4
