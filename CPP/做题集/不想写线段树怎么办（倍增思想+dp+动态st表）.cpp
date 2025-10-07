#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 1e6 + 9; // 定义数组的最大长度
const ll p = 1e9 + 7;  // 定义模数

ll a[N], b[N]; // a 是输入数组，b 是输出数组

ll st[N][20]; // st 是稀疏表，用于快速查询区间最大值

// 函数 getMax：查询区间 [l, r] 的最大值
ll getMax(int l, int r){
   ll res = a[r]; // 初始化结果为 a[r]
   int k = r - l + 1, i = r; // k 是区间长度，i 是当前查询的右端点
   for(int j = 20; j >= 0; --j){ // 从高位到低位遍历
      if(k >> j & 1){ // 如果区间长度包含 2^j
         res = max(res, st[i][j]); // 更新最大值
         i -= (1 << j); // 移动左端点
      }
   }
   return res; // 返回区间最大值
}

// 函数 insert：将元素 x 插入稀疏表，并更新相关区间
void insert(int i, ll x){
   st[i][0] = x; // 初始化 st[i][0] 为 x
   for(int j = 1; i - (1 << j) + 1 >= 1; ++j){ // 更新更高层的区间最大值
      st[i][j] = max(st[i][j - 1], st[i - (1 << (j - 1))][j - 1]);
   }
}

// 函数 solve：解决问题的主逻辑
void solve(){
   int n; cin >> n; // 输入数组长度
   for(int i = 1; i <= n; i++) cin >> a[i]; // 输入数组 a

   b[1] = a[1]; // 初始化 b[1] 为 a[1]
   insert(1, b[1]); // 将 b[1] 插入稀疏表
   cout << b[1] << ' '; // 输出 b[1]

   for(int i = 2; i <= n; ++i){ // 从第二个元素开始计算 b[i]
      b[i] = a[i] * getMax(max(1ll, i - a[i]), i - 1) % p; // 计算 b[i]
      insert(i, b[i]); // 将 b[i] 插入稀疏表
      cout << b[i] << ' '; // 输出 b[i]
   }
}

int main(){
   ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); // 优化输入输出
   int _ = 1;
   while(_--) solve(); // 调用 solve 函数
   return 0;
}
