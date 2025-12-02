#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int cmp(string a, string b) {
    if (a.size() != b.size())
        return (a.size() < b.size()) ? -1 : 1;
    if (a == b) return 0;
    return (a < b) ? -1 : 1;
}

string subtractStr(string a, string b) {
    while (b.size() < a.size()) b = "0" + b; // 자릿수 일치시키기

    int carry = 0; // 다음 자릿수 넘김 여부
    for (int i = a.size() - 1; i >= 0; i--) { // 각 자리별로 계산
        int x = (a[i] - '0') - (b[i] - '0') - carry;
        if (x < 0) { // 음수 계산
            x += 10;
            carry = 1;
        } else {
            carry = 0;
        }
        a[i] = char(x + '0');
    }

    // 앞에 붙은 0 제거
    int idx = 0;
    while (idx + 1 < a.size() && a[idx] == '0') idx++;
    return a.substr(idx);
}

pair<string, string> dividerStr (string n, string m) {
    string quotient = "";
    string cur = "0";

    for(char digit: n) {
        if(cur == "0") cur = "";
        cur.push_back(digit);

        int count = 0;
        while (cmp(cur, m) >= 0) {
            cur = subtractStr(cur, m);
            count++;
        }

        quotient.push_back(count + '0');
    }

    // 앞에 붙은 0 제거
    int idx = 0;
    while (idx + 1 < quotient.size() && quotient[idx] == '0') idx++;
    quotient = quotient.substr(idx);

    return {quotient, cur};
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string n, m;
    cin >> n >> m;

    pair<string, string> result = dividerStr(n, m);

    cout << result.first << endl;
    cout << result.second << endl;

    return 0;
}
