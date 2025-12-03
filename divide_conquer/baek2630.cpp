#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int paper[128][128];

int blueCnt = 0;
int whiteCnt = 0;

bool checkSameColor(int x, int y, int size) {
    int firstColor = paper[x][y];

    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            if(paper[x+i][y+j] != firstColor) return false;
        }
    }
    return true;
}

void divide(int x, int y, int size) {
    if(checkSameColor(x, y, size)) {
        if(paper[x][y] == 1) blueCnt++;
        else whiteCnt++;
    }
    else {
        int newSize = size/2;

        divide(x, y, newSize);
        divide(x, y + newSize, newSize);
        divide(x + newSize, y, newSize);
        divide(x + newSize, y + newSize, newSize);
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cin >> paper[i][j];
        }
    }

    divide(0, 0, n);

    cout << whiteCnt << "\n" << blueCnt << "\n";

    return 0;
}
