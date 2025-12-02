#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int lcm(int a, int b) {
    return a / gcd(a, b) * b;
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    vector<int> memo;

    for(int i=0; i<5; i++) {
        int k;
        cin >> k;
        memo.push_back(k);
    }

    int result = 1e9;

    for(int i=0; i<5; i++) {
        for(int j=i+1; j<5; j++) {
            for(int k=j+1; k<5; k++) {
                result = min(result, lcm(lcm(memo[i], memo[j]), memo[k]));
            }
        }
    }

    cout << result << endl;

    return 0;
}
