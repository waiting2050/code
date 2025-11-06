// 后序最后一个点肯定是根节点，在中序里找到根节点，往前是全在左子树，往右全在右子树。往前有idx-1个（根节点的下标刚好作为划分）
// 这个idx很关键，在后序里面，前idx-1个一定是左子树，后n-idx-1个就是右子树（排除根节点自身）。代码的核心就是
// 不断找根节点，由根节点确定左右子树，但是要注意不同序的数组的根节点所在的位置不同

#include <bits/stdc++.h>
using namespace std;
#define pb push_back

const int N = 30;

vector<int> ans;

void buildtree(vector<int>& a, vector<int>& b)
{
    if(a.empty()) return;
    ans.pb(a.back());

    int idx = 0;
    while(b[idx] != a.back()) idx++;

    vector<int> ls(a.begin(), a.begin() + idx);
    vector<int> lm(b.begin(), b.begin() + idx);
    vector<int> rs(a.begin() + idx, a.end() - 1);
    vector<int> rm(b.begin() + idx + 1, b.end());

    buildtree(ls, lm);
    buildtree(rs, rm);
}

int main()
{
    int n; cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < n; i++) cin >> b[i];

    buildtree(a, b);

    cout << "Preorder: ";
    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if(i + 1 != n) cout << ' ';
    }
    
    return 0;
}

// 7
// 2 3 1 5 7 6 4
// 1 2 3 4 5 6 7

// Preorder: 4 1 3 2 6 5 7