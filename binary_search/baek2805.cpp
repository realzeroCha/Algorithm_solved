#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    long long n, m;
    cin >> n >> m;
    vector<long long> tree;

    long long left = 0;
    long long right = 0;

    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        tree.push_back(k);
        if(right < k) right = k;
    }


    while(left <= right) {
        long long mid = (left + right) / 2;
        long long total = 0;
        for(int i=0; i<n; i++) {
            if(tree[i] > mid) total += tree[i] - mid;
        }
        if(total >= m) left = mid + 1;
        else right = mid - 1;
    }

    cout << right << endl;

    return 0;
}
