#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 帕斯卡三角形（组合数）的最大行数和列数
const int N = 1e3 + 9; // 设置数组大小略大于最大可能值，确保不会越界
ll c[N][N];            // 组合数存储表，c[i][j]表示C(i, j)，即从i个不同元素中选取j个元素的组合数
const ll mod = 1e9 + 7; // 设定模数，用于防止数值过大导致溢出

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); // 提升I/O操作效率

    int n, m;
    cin >> n >> m; // 输入n和m，分别代表要计算的帕斯卡三角形的行数和每行输出的最大列数

    // 初始化：对于所有行，第一项（即c[i][0]）都设为1，因为C(n, 0)总是等于1
    for(int i = 0; i < n; i++) 
        c[i][0] = 1ll;

    // 计算组合数：使用递推公式 C(i, j) = C(i-1, j) + C(i-1, j-1)
    // 注意这里只计算到第i行且不超过m列，以节省空间和时间
    for(int i = 1; i < n; i++)
        for(int j = 1; j <= i && j < m; j++) 
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod; // 计算并取模

    // 输出计算好的帕斯卡三角形，注意只输出前m列
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++) // 确保不超出当前行的长度
            cout << c[i][j] << " ";
        cout << '\n';
    }

    return 0; // 程序正常结束
}

//3 3
//
//1 0 0
//1 1 0
//1 2 1
