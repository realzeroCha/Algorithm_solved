#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string king, stone;
    int n;
    cin >> king >> stone >> n;

    vector<string> cmd;

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        cmd.push_back(str);
    }

    for(int i=0; i<n; i++) {
        pair<int,int> dir = {0, 0};
        if(cmd[i].find('T') != string::npos) dir.second = 1;
        if(cmd[i].find('B') != string::npos) dir.second = -1;
        if(cmd[i].find('L') != string::npos) dir.first = -1;
        if(cmd[i].find('R') != string::npos) dir.first = 1;

        pair<int, int> kingTmp = {king[0] - 65, king[1] - 49};
        pair<int, int> stoneTmp = {stone[0] - 65, stone[1] - 49};

        if(kingTmp.first + dir.first >= 0 && kingTmp.first + dir.first <= 7 &&
        kingTmp.second + dir.second >= 0 && kingTmp.second + dir.second <= 7
        ) {
            if(stoneTmp.first == kingTmp.first + dir.first && stoneTmp.second == kingTmp.second + dir.second) {
                if(stoneTmp.first + dir.first >=0 && stoneTmp.first + dir.first <= 7 &&
                stoneTmp.second + dir.second >=0 && stoneTmp.second + dir.second <= 7) {
                    stoneTmp.first += dir.first;
                    stoneTmp.second += dir.second;
                } else {
                    continue;
                }
            }

            kingTmp.first += dir.first;
            kingTmp.second += dir.second;

            king = string(1, char(kingTmp.first + 65)) + string(1, char(kingTmp.second + 49));
            stone = string(1, char(stoneTmp.first + 65)) + string(1, char(stoneTmp.second + 49));
        }
    }

    cout << king << endl;
    cout << stone << endl;

    return 0;
}
