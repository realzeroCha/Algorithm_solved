#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<vector<int>> graph;
vector<int> dist;

int x, y;

void bfs(int node) {
    queue<int> q;
    q.push(node);
    dist[node] = 0;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int i : graph[curr]) {
            if(dist[i] == -1) {
                q.push(i);
                dist[i] = dist[curr] + 1;
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n;
    cin >> x >> y;
    cin >> m;

    graph.resize(n+1);
    dist.resize(n+1, -1);

    for(int i=1; i<=m; i++) {
        int k, l;
        cin >> k >> l;

        graph[k].push_back(l);
        graph[l].push_back(k);
    }

    bfs(x);

    cout << dist[y] << endl;

    return 0;
}
