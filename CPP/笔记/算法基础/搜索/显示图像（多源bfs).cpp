#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define fi first
#define se second

const int N = 200;
int n, m;
bitset<N> a[N];
int dx[] = {0, 0, -1, 1}; // �����������飬�������ĸ�����
int dy[] = {-1, 1, 0, 0};
int ans[N][N];

bool inmp(int x, int y) {
    return x >= 1 && x <= n && y >= 1 && y <= m;
}

void bfs() {
    queue<pair<int, int>> q;
    // ��ʼ���������а�ɫ���ص�������
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(a[i][j]) {
                q.push({i, j});
                ans[i][j] = 0; // ��ɫ���ص�ľ���Ϊ 0
            } else {
                ans[i][j] = -1; // ��ɫ���ص�ľ����ʼ��Ϊ -1
            }
        }
    }

    // ��Դ BFS
    //ͬһ�������еĽڵ����һ����������õ���ans��ͬһ������Ž⡣Ȼ��ͬһ�����õ���ans��Ϊ �ӽڵ����������Դ����ơ�
	//��ͬһ����Ľڵ���Կ���ͬʱ�����Ĳ��ƣ���ΪֻҪ����룬ûҪ��·��ת�� 
    while(!q.empty()) {
        auto now = q.front(); q.pop();
        for(int i = 0; i < 4; i++) {
            int nx = now.fi + dx[i];
            int ny = now.se + dy[i];
            if(inmp(nx, ny)) {
                if(ans[nx][ny] == -1) { // ����õ�δ�����ʹ�
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
            char x; cin >> x;//ע�⣺����ط�����char��������int 
            if(x == '1') a[i][j] = 1;
        }
    }
    
    bfs(); // ֻ����һ�� BFS
    
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
