#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

char map[25][25];
bool visited[25][25];

int n;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int cnt;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;
    cnt++;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx>=0 && ny>=0 && nx<n && ny<n) {
                if(!visited[nx][ny] && map[nx][ny] == '1') {
                    cnt++;
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                }
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> group;

    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            if(!visited[i][j] && map[i][j] == '1') {
                bfs(i, j);
                group.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(group.begin(), group.end());

    cout << group.size() << endl;
    for(int i=0; i<group.size(); i++) {
        cout << group[i] << endl;
    }


    return 0;
};
