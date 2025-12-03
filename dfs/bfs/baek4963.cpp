#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int cnt = 0;

int maps[50][50];
bool visited[50][50];

int dx[] = {0, 1, 1, 1, 0, -1, -1, -1};
int dy[] = {1, 1, 0, -1, -1, -1, 0, 1};

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = 1;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<8; i++) {
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;

            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if(!visited[nx][ny] && maps[nx][ny] == 1) {
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    while(true) {
        cnt = 0;
        cin >> m >> n;

        if(m == 0 && n == 0) break;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int k;
                cin >> k;
                maps[i][j] = k;
                visited[i][j] = false;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(maps[i][j] == 1 && !visited[i][j]) {
                    bfs(i, j);
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}
