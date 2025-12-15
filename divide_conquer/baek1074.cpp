#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int devide(int r, int c, int n) {
    if(n == 0) return 0;

    int half = pow(2, n-1);

    if(r >= half && c >= half) return (half*half) * 3 + devide(r-half, c-half, n-1);
    else if(r >= half && c < half) return (half*half) * 2 + devide(r-half, c, n-1);
    else if(c >= half && r < half) return (half*half) + devide(r, c-half, n-1);
    return devide(r, c, n-1);
};

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int N, r, c;
    cin >> N >> r >> c;

    cout << devide(r, c, N) << endl;

    return 0;
};
