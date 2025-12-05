#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

char tree[26][2];

// 전위: root - left - right
void preorder(char node) {
    if(node == '.') return;
    cout << node;
    preorder(tree[node-'A'][0]);
    preorder(tree[node-'A'][1]);
}

// 중위: left - root - right
void inorder(char node) {
    if(node == '.') return;
    inorder(tree[node-'A'][0]);
    cout << node;
    inorder(tree[node-'A'][1]);
}

// 후위: left - right - root
void postorder(char node) {
    if(node == '.') return;
    postorder(tree[node-'A'][0]);
    postorder(tree[node-'A'][1]);
    cout << node;
}

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    for(int i=0; i<n; i++) {
        char l, node, r;
        cin >> node >> l >> r;
        tree[node-'A'][0] = l;
        tree[node-'A'][1] = r;
    }

    preorder('A');
    cout << '\n';
    inorder('A');
    cout << '\n';
    postorder('A');
    cout << '\n';

    return 0;
};
