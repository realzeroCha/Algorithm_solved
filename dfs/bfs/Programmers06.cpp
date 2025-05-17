#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<bool>visited;

bool found = false;

void dfs(vector<vector<string>>& tickets, vector<string>& answer, string curr, vector<string>& path, int cnt) {
    if(found) return;

    // 탐색 완료 후 종료
    if(cnt == tickets.size() && path.size() == tickets.size()+1) {
        answer = path;
        found = true;
        return;
    }

    for(int i=0; i<tickets.size(); i++) {
        // 현재 도착지점과 다음 출발지점 비교
        if(!visited[i] && curr == tickets[i][0]) {
            visited[i] = true;
            path.push_back(tickets[i][1]);
            dfs(tickets, answer, tickets[i][1], path, cnt + 1);
        
            // 백트래킹
            visited[i] = false;
            path.pop_back();
        }
    }
}


vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    
    visited.resize(tickets.size(), false);
    
    sort(tickets.begin(), tickets.end());
    
    vector<string> path = {"ICN"};
    dfs(tickets, answer, "ICN", path, 0);
        
    return answer;
}