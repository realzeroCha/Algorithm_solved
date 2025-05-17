#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<vector<bool>> visited;
int m,n,o;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};


void dfs (int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if(nx >=0 && ny >=0 && nx < m && ny < n) {
            if(graph[nx][ny] == 1 && !visited[nx][ny]) {
                dfs(nx, ny);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int num;
    cin >> num;

    while(num --) {
        graph.clear();
        visited.clear();
        int cnt = 0;

        cin >> m >> n >> o;

        graph.resize(m, vector<int>(n, 0));
        visited.resize(m, vector<bool>(n,false));

        for(int j=0; j<o; j++) {
            int a, b;
            cin >> a >> b;

            graph[a][b] = 1;
        }

        for(int x=0; x<m; x++) {
            for(int y=0; y<n; y++) {
                if(graph[x][y] == 1 && !visited[x][y]) {
                    cnt++;
                    dfs(x,y);
                }
            }
        }

        cout << cnt << endl;
    }
}