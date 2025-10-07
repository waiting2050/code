#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int N = 200;
int n, m;
bitset<N> a[N];
int dx[] = {0, 0, -1, 1}; // 修正方向数组，仅保留四个方向
int dy[] = {-1, 1, 0, 0};
int ans[N][N];

bool inmp(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs() {
    queue<pair<int, int>> q;
    // 初始化：将所有白色像素点加入队列
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j]) {
                q.push({i, j});
                ans[i][j] = 0; // 白色像素点的距离为 0
            } else {
                ans[i][j] = -1; // 黑色像素点的距离初始化为 -1
            }
        }
    }

    // 多源 BFS
    //同一层加入队列的节点会在一起遍历，所得到的ans是同一层的最优解。然后同一层所得到的ans作为 子节点加入遍历，以此类推。
	//（同一层检查的节点可以看作同时荡漾的波纹，因为只要求距离，没要求路径转移 
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = now.fi + dx[i];
            int ny = now.se + dy[i];
            if(inmp(nx, ny)) {
                if(ans[nx][ny] == -1) { // 如果该点未被访问过
                    ans[nx][ny] = ans[now.fi][now.se] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            char x; cin >> x;//注意：这个地方得用char，不能用int 
            if(x == '1') a[i][j] = 1;
        }
    }
    
    bfs(); // 只调用一次 BFS
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << ans[i][j] << " \n"[j == m];
        }
    }
    
    return 0;
}

//3 4
//0001
//0011
//0110
//
//3 2 1 0
//2 1 0 0
//1 0 0 1
