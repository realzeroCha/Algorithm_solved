#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    vector<int> w(n+1), v(n+1);
    for(int i = 1; i<=n; i++) {
        cin >> w[i] >> v[i];
    }

    vector<vector<int>> memo (n+1, vector<int>(k+1, 0));

    for(int i = 1; i<=n; i++) {
        for(int j = 0; j <= k; j++) {
            if(j >= w[i]) {
                memo[i][j] = max(memo[i - 1][j], memo[i - 1][j - w[i]] + v[i]);
            }
            else {
                memo[i][j] = memo[i-1][j];
            }
        }
    }

    cout << memo[n][k] << endl;

    return 0;
}