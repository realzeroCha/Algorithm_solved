#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int l, c;

vector<char> key;

void dfs(int node, string str) {
    if(str.length() == l) {
        int aeCnt = 0;
        for(char c : str) {
            if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') aeCnt++;
        }
        if(aeCnt > 0 && l-aeCnt > 1) cout << str << endl;
        return;
    }

    for(int i=node; i<c; i++) {
        str += key[i];
        dfs(i+1, str);
        str.pop_back();
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> l >> c;

    for(int i=0; i<c; i++) {
        char ch;
        cin >> ch;
        key.push_back(ch);
    }
    sort(key.begin(), key.end());

    dfs(0, "");

    return 0;
};
