#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> visited;

void bfs(int x) {
    visited[x]++;
    queue<int> q;
    q.push(x);

    while(!q.empty()) {
        int curr = q.front();
        q.pop();
        
        for(int next: graph[curr]) {
            if(visited[next] == 0) {
                q.push(next);
                visited[next] = visited[curr] + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int answer = 0;

    cin >> n >> m;

    graph.resize(n+1);
    visited.resize(n+1, 0);

    for(int i=0; i<m; i++) {
       int a,b;
       cin >> a >> b;
       graph[a].push_back(b);
       graph[b].push_back(a);
    }

    bfs(1);

    int dist = *max_element(visited.begin(), visited.end());
    answer = count(visited.begin(), visited.end(), dist);

    cout << answer << endl;

    return 0;
}