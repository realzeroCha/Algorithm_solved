#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<vector<int>> visited;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n, m;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({x,y});
    visited[x][y] = 1;


    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();
        
        for(int i=0; i<4; i++) {
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;
    
            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if(visited[nx][ny] == 0 && graph[nx][ny] == 1) {
                    visited[nx][ny] = visited[cx][cy] + 1;
                    q.push({nx,ny});
                }
            }
        }
    }
    
}
int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    graph.resize(n, vector<int>(m));
    visited.resize(n, vector<int>(m, 0));

    for(int i=0; i<n; i++) {
        string num;
        cin >> num;
        for(int j=0; j<m; j++) {
            graph[i][j] = num[j] - '0';
        }
    }
    
    bfs(0, 0);

    cout << visited[n-1][m-1] << endl;
}