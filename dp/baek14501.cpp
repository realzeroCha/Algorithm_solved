#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> time;
    vector<int> price;
    vector<int> memo(n+1, 0);

    for(int i=0; i<n; i++) {
        int t, p;
        cin >> t >> p;
        time.push_back(t);
        price.push_back(p);
    }

    for(int i=n-1; i>=0; i--) {
        if(i + time[i] <= n) {
            memo[i] = max(memo[i+1], price[i] + memo[i + time[i]]);
        }
        else {
            memo[i] = memo[i+1];
        }
    }

    cout << memo[0] << endl;

    return 0;
}
