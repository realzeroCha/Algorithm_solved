#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> list;
    vector<int>memo(n, 0);

    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        list.push_back(k);
    }

    for(int i=0; i<n; i++) {
        if(i == 0) {
            memo[i] = list[i];
        }
        else memo[i] = max(list[i], list[i] + memo[i-1]);
    }

    cout << *max_element(memo.begin(), memo.end()) << endl;

    return 0;
}
