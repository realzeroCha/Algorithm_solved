#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> list;
    vector<int> memo(n+1, 0);

    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        list.push_back(k);
    }

    for(int i=0; i<n; i++) {
        if (i == 0) memo[i] = list[0];
        else if (i == 1) memo[i] = memo[0] + list[1];
        else if (i == 2) memo[i] = max({memo[1], (memo[0] + list[2]), (list[1] + list[2])});
        else memo[i] = max({memo[i-1], (memo[i-2] + list[i]), (memo[i-3] + list[i-1] + list[i])});
    }

    cout << memo[n-1] << endl;

    return 0;
};
