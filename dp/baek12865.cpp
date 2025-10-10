#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n, k;
    cin >> n >> k;

    vector<int> value(n+1);
    vector<int> weight(n+1);

    vector<int> memo(k+1, 0);

    for(int i=1; i<=n; i++) {
        cin >> weight[i] >> value[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=k; j>= weight[i]; j--) {
            if(j >= weight[i]) {
                memo[j] = max(memo[j], memo[j-weight[i]] + value[i]);
            }
        }
    }
   
    cout << memo[k] << endl;
}