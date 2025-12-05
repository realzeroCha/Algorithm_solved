#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int map[100][100];
bool visited[100][100];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

void bfs(int x, int y, int height) {
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
            if(nx >= 0 && ny >= 0 && nx < n && ny < n) {
                if(!visited[nx][ny] && map[nx][ny] > height) {
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

    int maxHeight = 0;
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
            maxHeight = max(map[i][j], maxHeight);
        }
    }

    int maxCnt = 0;

    for(int i=0; i<maxHeight; i++) {
        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                visited[j][k] = false;
            }
        }
        int cnt = 0;

        for(int j=0; j<n; j++) {
            for(int k=0; k<n; k++) {
                if(!visited[j][k] && map[j][k] > i) {
                    bfs(j, k, i);
                    cnt++;
                }
            }
        }

        maxCnt = max(maxCnt, cnt);
    }

    cout << maxCnt << endl;

    return 0;
};
