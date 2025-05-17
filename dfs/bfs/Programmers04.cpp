#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


vector<string> v;
vector<bool>visited;

int bfs(string begin, string target) {
    queue<pair<string, int>> q;
    q.push({begin, 0});

    while(!q.empty()) {
        string cur = q.front().first;
        int dep = q.front().second;

        q.pop();

        if(target == cur) {
            return dep;
        }
        
        for(int i=0; i< v.size(); i++) {
            int diff = 0;
            if(!visited[i]) {
                for(int j=0; j < begin.length(); j++) {
                    if(cur[j] != v[i][j]) diff++;
                }

                if(diff == 1) {
                    visited[i] = true;
                    q.push({v[i], dep + 1});
                }
            }
        }       
   }
   return 0;
}


int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    string begin, target;
    int n;
    cin >> begin >> target >> n;

    visited.resize(n, false);

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }


    cout << bfs(begin, target) << endl;

    return 0;
}