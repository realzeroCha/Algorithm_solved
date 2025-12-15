#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;

int cols[15];

int result = 0;

void dfs(int row) {
    // 마지막 열까지 탐색
    if(row == n) {
        result++;
        return;
    }

    // 행 탐색
    for(int i=0; i<n; i++) {
        // 퀸 배치 여부
        bool isPossible = true;

        // 탐색한 열까지만 확인
        for(int j=0; j<row; j++) {
            // 같은 행 & 대각선 체크 (행과 열의 차이가 같음)
            if(cols[j] == i || (abs(cols[j] - i) == abs(j - row))) {
                isPossible = false;
                break;
            }
        }

        if(isPossible) {
            cols[row] = i;
            dfs(row + 1);
        }
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    cin >> n;

    dfs(0);

    cout << result << endl;

    return 0;
};
