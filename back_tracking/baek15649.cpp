#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>

using namespace std;

int n, m;

int memo[10];
bool visited[10];

void dfs(int depth) {
    if(depth == m) {
        for(int i=0; i<m; i++) {
            cout << memo[i] << " ";
        }
        cout << "\n";
        return;
    }

    for(int i=0; i<n; i++) {
        if(!visited[i]) {
            visited[i] = true;
            memo[depth] = i + 1;

            dfs(depth + 1);

            // 백트래킹
            visited[i] = false;
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;
    dfs(0);

    return 0;
}
