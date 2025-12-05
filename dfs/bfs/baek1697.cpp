#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

int dist[100001];
bool visited[100001];

void bfs(int node) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        if(curr == m) {
            cout << dist[curr] << endl;
            return;
        }

        int curArr[3] = { curr-1, curr+1, curr*2 };

        for(int i: curArr) {
            if(!visited[i] && i >= 0 && i <= 100000) {
                visited[i] = true;
                q.push(i);
                dist[i] = dist[curr] + 1;
            }
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    bfs(n);

    return 0;
};
