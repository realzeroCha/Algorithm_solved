#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int grid[1000][1000];
vector<pair<int, int>> tomato;

int dist[1000][1000];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int longgest = 0;

void bfs() {
    queue<pair<int, int>> q;

    for(pair<int ,int> p: tomato) {
        q.push(p);
    }

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx >=0 && ny >=0 && nx < m && ny < n) {
                if(grid[nx][ny] == 0 && dist[nx][ny] == 0) {
                    q.push({nx, ny});
                    grid[nx][ny] = 1;
                    dist[nx][ny] = dist[cx][cy] + 1;
                    longgest = max(longgest, dist[nx][ny]);
                }
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> grid[i][j];
            dist[i][j] = 0;
            if(grid[i][j] == 1) {
                tomato.push_back({i, j});
            }
        }
    }

    bfs();

    bool foundZero = false;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            if(grid[i][j] == 0) foundZero = true;
        }
    }

    cout << (foundZero ? -1 : longgest) << endl;

    return 0;
};
