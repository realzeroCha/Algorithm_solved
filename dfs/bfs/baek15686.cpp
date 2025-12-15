#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m;

vector<pair<int, int>> home;
vector<pair<int, int>> store;

vector<int> selected;

int result = 1e9;

// 치킨가게 조합
void dfs(int idx, int cnt) {
    if(cnt == m) {
        int sum = 0;
        for(pair<int, int> p : home) {
            int shortest = 1e9;

            // 집과 치킨 가게 사이의 거리 최솟값
            for(int i : selected) {
                shortest = min(shortest, (abs(store[i].first - p.first) + abs(store[i].second - p.second)));
            }
            sum += shortest;
        }
        result = min(result, sum);

        return;
    }
    if(idx == store.size()) return;

    selected.push_back(idx);
    dfs(idx + 1, cnt + 1);

    selected.pop_back();
    dfs(idx + 1, cnt);
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            int k;
            cin >> k;
            if(k == 1) home.push_back({i, j});
            else if(k == 2) store.push_back({i, j});
        }
    }

    dfs(0, 0);

    cout << result << endl;

    return 0;
};
