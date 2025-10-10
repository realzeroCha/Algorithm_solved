#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MOD = 1000000000;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;
    cin >> n;

    vector<vector<int>> memo (n+1, vector<int>(10, 1));

    memo[1][0] = 0;

    long long sum = 0;

    for(int i=2; i<=n; i++) {
        for(int j=0; j<10; j++) {
            if(j == 0) memo[i][j] = memo[i-1][1];
            else if(j == 9) memo[i][j] = memo[i-1][8];
            else {
                memo[i][j] = memo[i-1][j-1] + memo[i-1][j+1];
            }
            memo[i][j] %= MOD;
            if(i == n) sum = (sum + memo[i][j]) % MOD;
        }
    }
   
    cout << ((n == 1) ? 9 : sum) << endl;
}