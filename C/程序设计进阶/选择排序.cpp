#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

const int N = 20;
int a[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    for (int i = 1; i <= 10; i++) cin >> a[i];//假设输入十个数据

    for (int i = 1; i <= 10; i++)
    {
        int j, mx;
        for (j = i + 1, mx = i; j <= 10; j++)
            if (a[mx] < a[j]) mx = j;

        swap(a[i], a[mx]);
    }

    for (int& ele : a)
        cout << ele << ' ';

    return 0;
}
//15 72 3 46 89 23 54 11 67 42
