#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> memo;

    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        memo.push_back(k);
    }
    sort(memo.begin(), memo.end());

    cout << memo[0] * memo[n-1] << endl;

    return 0;
}
