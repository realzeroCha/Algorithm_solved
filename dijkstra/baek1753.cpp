#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

const int INF = 1e9;

vector<vector<pair<int, int>>>graph;

vector<int> dist;

void dijkstra(int x) {
    priority_queue<pair<int ,int>, vector<pair<int ,int>>, greater<pair<int, int>>> pq;
    dist[x] = 0;
    pq.push({0, x});
    
    while(!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(cost > dist[now]) continue;

        for(pair<int, int> p : graph[now]) {
            int nextCost = cost + p.second;
            if(nextCost < dist[p.first]) {
                dist[p.first] = nextCost;
                pq.push({nextCost, p.first});
            }
        }
    }
};

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m, o;

    cin >> n >> m >> o;

    dist.resize(n+1, INF);
    graph.resize(n+1);

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    dijkstra(o);

    for(int i=1; i<=n; i++) {
        if(dist[i] == INF) {
            cout << "INF" << endl;
        }
        else {
            cout << dist[i] << endl;
        }
    }

    return 0;
}