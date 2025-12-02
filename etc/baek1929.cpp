#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool prime(int x) {
    int end = int(sqrt(x));
    if(x == 1) return false;
    for(int i=2; i<=end; i++) {
        if(x % i == 0) {
            return false;
        }
    }
    return true;
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int m, n;
    cin >> m >> n;

    for(int i=m; i<=n; i++) {
        if(prime(i)) cout << i << endl;
    }

    return 0;
}
