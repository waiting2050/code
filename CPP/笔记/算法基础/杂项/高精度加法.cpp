#include <iostream>
#include <vector>
using namespace std;

string a, b;
vector<int> A, B, C;

//注意
//1.开头 if 的作用为保证 A的位数≥B的位数，当然可以通过修改下面的循环和判断条件使其适配所有情况。
//2.for 循环中的 if 是为了防止越界访问 B.
//3.结尾需要判断 t是否为 0若非 0则需要进位 1
vector<int> add(vector<int>& A, vector<int>& B)
{
    if (B.size() > A.size())
        return add(B, A);

    int t = 0;
    for (int i = 0; i < A.size(); i++)
    {
        t += A[i];
        if (i < B.size())
            t += B[i];
        C.push_back(t % 10);
        t = t > 9 ? 1 : 0;
    }
    if (t)
        C.push_back(1);
    return C;
}

int main()
{
    /* 输入 */
    cin >> a >> b; // 首先以字符串形式读入
    for (int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0'); // 反向将字符串每位写入整型数组，注意减去偏移量‘0’
    for (int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');

    add(A, B);

    /* 输出 */
    for (int i = C.size() - 1; i >= 0; i--)
        cout << C[i]; // 反向输出整型数组每一位
}
