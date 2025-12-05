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
    vector<int> memo;

    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        list.push_back(k);
        memo.push_back(k);
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<i; j++) {
            if(list[i] > list[j]) {
                memo[i] = max(memo[i], memo[j] + list[i]);
            }
        }
    }

    cout << *max_element(memo.begin(), memo.end()) << endl;

    return 0;
}
