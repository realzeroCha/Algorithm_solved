#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    string m,n;

    cin >> m >> n;

    vector<vector<int>> memo(m.length() + 1, vector<int>(n.length() + 1, 0));

    for(int i=1; i<=m.length(); i++) {
        for(int j=1; j<=n.length(); j++) {
            if(m[i-1] == n[j-1]) {
                memo[i][j] = memo[i-1][j-1] + 1; 
            }
            else {
                memo[i][j] = max(memo[i-1][j], memo[i][j-1]);
            }
        }
    }

    cout << memo[m.length()][n.length()] << endl;
}