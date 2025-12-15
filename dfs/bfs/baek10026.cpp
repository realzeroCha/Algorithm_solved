#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

char grid[100][100];
bool visited[100][100];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int cnt = 0;
int rgCnt = 0;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx >=0 && ny >= 0 && nx < n && ny < n) {
                if(!visited[nx][ny] && grid[nx][ny] == grid[cx][cy]) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
            visited[i][j] = false;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
                cnt++;
            }
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 'G') grid[i][j] = 'R';
            visited[i][j] = false;
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j]) {
                bfs(i, j);
                rgCnt++;
            }
        }
    }

    cout << cnt << " " << rgCnt << endl;

    return 0;
};
