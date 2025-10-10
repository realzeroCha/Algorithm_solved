#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    
    int n;

    cin >> n;

    vector<pair<int, int>> meeting(n);

    for(int i=0; i<n; i++) {
        cin >> meeting[i].first >> meeting[i].second;
    }

    sort(meeting.begin(), meeting.end(), [](auto &a, auto &b) {
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    });

    int count = 0, endTime = 0;
    for(auto &time: meeting) {
        if(time.first >= endTime) {
            count++;
            endTime = time.second;
        }
    }

    cout << count << endl;
}