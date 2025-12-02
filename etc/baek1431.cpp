#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    if(a.length() != b.length()) {
        return a.length() < b.length();
    }

    int aSum = 0;
    int bSum = 0;
    for(char c : a) {
        if(isdigit(c)) aSum += (c-'0');
    }
    for(char c : b) {
        if(isdigit(c)) bSum += (c-'0');
    }
    if(aSum != bSum) return aSum < bSum;

    return a < b;
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<string> strs;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        strs.push_back(str);
    }

    sort(strs.begin(), strs.end(), cmp);

    for(int i=0; i<n; i++) {
        cout << strs[i] << endl;
    }

    return 0;
}
