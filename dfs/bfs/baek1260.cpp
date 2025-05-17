#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;

void dfs(int node) {
    visited[node] = true;
    cout << node << " ";

    for(int i: graph[node]) {
        if(!visited[i]) {
            dfs(i);
        }
    }
}

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        int current = q.front();
        q.pop();
        cout << current << " ";
        
        for(int i: graph[current]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, v;

    cin >> n >> m >> v;

    graph.resize(n+1);
    visited.resize(n+1, false);


    for(int i=1; i<=m; i++) {
        int a,b;
        cin >> a>> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end());
    }

    dfs(v);
    cout << endl;

    visited.clear();
    visited.resize(n+1, false);

    bfs(v);
    cout << endl;

}