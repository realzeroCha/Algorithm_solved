#include<vector>
#include<queue>

using namespace std;

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int n,m;

void bfs(vector<vector<int>>& maps, int x, int y) {
    queue<pair<int, int>>q;
    q.push({x,y});

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i=0; i<4; i++) {
            int nx = dx[i] + cx;
            int ny = dy[i] + cy;
            if(nx >= 0 && ny >= 0 && nx < n && ny < m) {
                if(maps[nx][ny] == 1) {
                    maps[nx][ny] = maps[cx][cy] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
}

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    
    n = maps.size();
    m = maps[0].size();
    
    bfs(maps, 0, 0);
    
    answer = maps[n-1][m-1] > 1 ? maps[n-1][m-1] : -1;
    
    return answer;
}