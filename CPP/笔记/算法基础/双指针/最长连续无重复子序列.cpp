#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 1e5 + 10;
int a[N], c[N], ans;//a�Ǵ洢�������ֵ����飬c�Ǽ�������

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;

        ans = 0;
        for (int i = 1; i <= n; i++) c[a[i]] = 0;//����c���飬ֻ��Ҫ�����±�Ϊa[i]��λ�ü���

        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 1, j = 0; i <= n; i++) //�ı䴰����߽磬i��1��n����
        {
            while (j < n && !c[a[j + 1]])c[a[++j]]++;   //�ı䴰���ұ߽磨n+1������j+1<=n����c[a[j+1]]û���ظ�����ʱ����c[a[j+1]]������һ

            ans = max(ans, j - i + 1);  //j-i+1�����г��ȣ�ʵ��Ϊ(j+1)-i��j+1�����ұ߽�
            c[a[i]]--;      //�����곤�Ⱥ󣬽���߽������ɾȥ
        }

        cout << ans << '\n';
    }

    return 0;
}
