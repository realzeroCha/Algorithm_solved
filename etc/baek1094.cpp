#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    int len = 64;
    int cnt = 0;

    while(n != 0) {
        if(n < len) {
            len /= 2;
        }
        else {
            n -= len;
            cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}
