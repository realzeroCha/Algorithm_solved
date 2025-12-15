#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    int r, c, d;

    int maps[50][50];

    cin >> n >> m;
    cin >> r >> c >> d;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> maps[i][j];
        }
    }

    int cnt = 0;

    while(true) {
        if(maps[r][c] == 1) {
            break;
        }

        // 로봇 위치 청소 여부 (-1: 청소 완료))
        if(maps[r][c] == 0) {
            maps[r][c] = -1;
            cnt++;
        }

        // 4칸 내 0 찾기
        bool isClean = true;
        for(int i=0; i<4; i++) {
            int nx = r + dx[i];
            int ny = c + dy[i];

            if(nx >= 0 && ny >= 0 && nx < n && ny < m && maps[nx][ny] == 0) isClean = false;
        }

        // 전부 1 or -1
        if(isClean) {
            int nx = r + dx[(d + 2) % 4];
            int ny = c + dy[(d + 2) % 4];

            if(nx < 0 || ny < 0 || nx >= n || ny >= m || maps[nx][ny] == 1) break;
            r = nx;
            c = ny;
        }
        // 0 발견
        else {
            d = (d + 3) % 4;

            int nx = r + dx[d];
            int ny = c + dy[d];
            if(nx >= 0 && ny >= 0 && nx < n && ny < m && maps[nx][ny] == 0) {
                r = nx;
                c = ny;
            }
        }
    }

    cout << cnt << endl;

    return 0;
};
