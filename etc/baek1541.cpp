#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int getSum(string str) {
    stringstream ss(str);
    string part;

    int sum = 0;
    while(getline(ss, part, '+')) {
        sum += stoi(part);
    }
    return sum;
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string str;
    cin >> str;

    string part;
    stringstream ss(str);

    getline(ss, part, '-');

    string numStr = "";
    int minSum = 0;

    int sum = getSum(part);
    while (getline(ss, part, '-')) {
        sum -= getSum(part);
    }

    cout << sum << endl;

    return 0;
}
