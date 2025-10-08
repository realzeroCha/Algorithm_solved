#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;

    cin >> n;

    vector<int> a(n);
    vector<int> memo(n, 1);

    for(int i=0; i<n; i++) {
        cin >> a[i];
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(a[i] > a[j]) {
                memo[i] = max(memo[i], memo[j] + 1);
            }
        }
    }

    cout << *max_element(memo.begin(), memo.end()) << endl;

    return 0;
}
