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

    int n, m;
    cin >> n >> m;

    vector<vector<int>> memo;

    for(int i=0; i<n; i++) {
        vector<int> temp;
        for(int j=0; j<m; j++) {
            char c;
            cin >> c;
            if(c == '.') temp.push_back(0);
            else temp.push_back(1);
        }
        memo.push_back(temp);
    }

    int rowCnt = 0;
    for(int i=0; i<m; i++) {
        int rows = 0;
        for(int j=0; j<n; j++) {
            rows += memo[j][i];
        }
        if(rows == 0) {
            rowCnt++;
        }
    }

    int colCnt = 0;
    for(int i=0; i<n; i++) {
        int cols = 0;
        for(int j=0; j<m; j++) {
            cols += memo[i][j];
        }
        if(cols == 0) {
            colCnt++;
        }
    }

    cout << max(rowCnt, colCnt) << endl;

    return 0;
}
