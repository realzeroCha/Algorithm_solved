#include <iostream>
#include <vector>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;

    cin >> n;

    vector<int> memo(n + 1);
    memo[0] = 0;
    memo[1] = 1;

    for(int i=2; i<=n; i++) {
        memo[i] = memo[i - 1] + memo[i - 2];
    }

    cout << memo[n] << endl;

    return 0;
}
