#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

void solve()
{
	int n; cin >> n;
	vector<int> a(107);
    int s = 0;
    for(int i = 1; i <= n; i++) 
    {
        cin >> a[i];
        s = max(s, a[i]);
    }
    
    sort(a.begin() + 1, a.begin() + 1 + n);//����ľ����С��������
    //һ��Ҫ������Ϊ֮��Ҫö����ߡ���������򣬱���[5,1,1,1]����ô֮��ö�ٵ�1��1������ߣ���ô�Դ𰸺Ϸ��Ե���֤�Ͳ������� 
	//�Ϸ��ԣ�����ߴ��������֮�� 

    vector<int> dp(n * s + 1);
    dp[0] = 1;

    ll ans = 1e18;
    for(int i = 1; i <= n; i++)//��ÿһ��ľ������Ϊ�ľ�� 
    {
        for(int j = a[i] + 1; j <= s * n; j++)//jΪǰ���ۻ��Ŀ��ܳ��ֵĳ��ȣ�������ñȵ�ǰ����ߴ󣨹���a[i]+1��ʼ������֮�ʹ��ڵ����ߣ� 
        {//��ʵ��ʱ�Ѿ����������һ�����ͼ�����������ߵ������ˣ���ǰ��ֻ��1����ʱ�������ܴ��ڵ�2���ߡ���ǰ���������ߵ�ʱ�򣬲ŻῪʼ������ 
            if(dp[j])//����з������������ 
            {
                ans = min(ans, a[i] + j + 0ll);//����ǰ��߼��� 
                break;
            }
        }
        for(int j = s * n; j >= a[i]; j--)//���͵�01������ö��ÿһ�ֳ��ȵĿ��� 
            dp[j] |= dp[j - a[i]];
    }

    if(ans > 1e17) ans = -1;
    cout << ans << endl;
}

int main() 
{
	int t; cin >> t;
	while(t--) solve();

    return 0;
}

//2
//8
//1 2 3 5 6 7 8 9
//3
//1 2 3
//
//11
//-1
