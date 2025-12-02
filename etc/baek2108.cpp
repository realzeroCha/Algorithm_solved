#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <map>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> list;
    map<int, int> map;

    for(int i=0; i<n; i++) {
        int k;
        cin >> k;
        list.push_back(k);
        map[list[i]]++;
    }

    sort(list.begin(), list.end());

    int avg = 0;
    for(int num: list) {
        avg += num;
    }
    // 산술평균
    cout << llround(double(avg)/list.size()) << endl;
    // 중앙값
    cout << list[list.size() / 2] << endl;

    // 최빈값
    vector<pair<int, int>> cntList;
    for(pair<int, int> item: map) {
        cntList.push_back(item);
    }

    sort(cntList.begin(), cntList.end(), [](pair<int, int> &a, pair<int, int> &b) {
        if(a.second == b.second) a.first < b.first;
        return a.second > b.second;
    });

    if(cntList.size() > 1 && cntList[0].second == cntList[1].second) {
        cout << cntList[1].first << endl;
    }
    else cout << cntList[0].first << endl;

    // 범위
    cout << list[n-1] - list[0] << endl;

    return 0;
}
