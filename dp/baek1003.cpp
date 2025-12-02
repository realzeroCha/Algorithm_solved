#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    int memo0[41];
    int memo1[41];

    memo0[0] = 1;
    memo0[1] = 0;
    memo1[0] = 0;
    memo1[1] = 1;

    for(int i=2; i<=40; i++) {
        memo0[i] = memo0[i-1] + memo0[i-2];
        memo1[i] = memo1[i-1] + memo1[i-2];
    }

    for(int i=0; i<n; i++) {
        int m;
        cin >> m;
        cout << memo0[m] << " " << memo1[m] << endl;
    }

    return 0;
}
