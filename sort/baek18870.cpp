#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    vector<int> pos;

    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        pos.push_back(k);
    }

    vector<int> newPos = pos;

    sort(newPos.begin(), newPos.end());
    newPos.erase(unique(newPos.begin(), newPos.end()), newPos.end());

    unordered_map<int, int> mp;
    for(int i=0; i<newPos.size(); i++) {
        mp[newPos[i]] = i;
    }

    for(int i=0; i<n; i++) {
        cout << mp[pos[i]] << " ";
    }

    cout << endl;

    return 0;
};
