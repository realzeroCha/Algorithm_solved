#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int parent[1000001];
int pRank[1000001];

int find(int x) {
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]); // 경로 압축
}

void setUnion(int x, int y) {
    int findX = find(x);
    int findY = find(y);

    if(findX == findY) return;

    if(pRank[findX] < pRank[findY]) parent[findX] = findY;
    else if(pRank[findX] > pRank[findY]) parent[findY] = findX;
    else {
        parent[findY] = findX;
        pRank[findX]++;
    }
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    for(int i=0; i<=n; i++) {
        parent[i] = i;
        pRank[i] = 0;
    }

    for(int i=0; i<m; i++) {
        int a, b, c;
        cin >> a >> b >> c;

        if(a == 0) setUnion(b, c);
        else {
            if(find(b) == find(c)) cout << "YES\n";
            else cout << "NO\n";
        }
    }

    return 0;
};
