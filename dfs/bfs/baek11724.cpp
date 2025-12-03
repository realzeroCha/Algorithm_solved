#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

int cnt = 0;

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int i : graph[curr]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    graph.resize(n+1);
    visited.resize(n+1, false);

    for(int i=0; i<m; i++) {
        int k, l;
        cin >> k >> l;

        graph[k].push_back(l);
        graph[l].push_back(k);
    }

    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            bfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
