#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k;

    cin >> n >> k;

    vector<int> coin(n);

    for(int i=0; i<n; i++) {
        cin >> coin[i];
    }

    sort(coin.begin(), coin.end(), [](auto &a, auto &b) {
        return a > b;
    });

    int cnt = 0;

    for(int &c: coin) {
        if(c <= k) {
            cnt += k/c;
            k %= c;
        }
    }

    cout << cnt << endl;
}