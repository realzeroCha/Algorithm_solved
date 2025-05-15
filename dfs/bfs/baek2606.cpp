
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> graph;
vector<bool> visited;
int inspected = 0;

void dfs(int node) {
    visited[node] = true;

    for(int i: visited) {
        if(visited[i]) {
           inspected++;
           dfs(i); 
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n,m;
    cin >> n >> m;

    graph.resize(n + 1);
    visited.resize(n + 1, false);

    for(int i=0; i<m; i++) {
        int a,b;
        cin >> a >> b;

        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(1);

    cout << inspected << "\n";
}