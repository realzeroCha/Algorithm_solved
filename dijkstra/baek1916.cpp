#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;
int start, dest;

vector<pair<int,int>> bus[1001];
int dist[1001];

void dijkstra(int x) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});
    dist[x] = 0;

    while(!pq.empty()) {
        int cost = pq.top().first;
        int now = pq.top().second;
        pq.pop();

        if(cost > dist[now]) continue;

        for(pair<int, int> p : bus[now]) {
            int nextCost = cost + p.second;
            if(nextCost < dist[p.first]) {
                dist[p.first] = nextCost;
                pq.push({nextCost, p.first});
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    fill(dist, dist+1001, 1e9);

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        bus[a].push_back({b, c});
    }
    cin >> start >> dest;

    dijkstra(start);

    cout << dist[dest] << endl;

    return 0;
};
