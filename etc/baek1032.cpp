#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main () {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    int n;
    cin >> n;

    string result = "";

    for(int i=0; i<n; i++) {
        string str;
        cin >> str;

        if(result == "") result = str;
        else {
            string temp = "";
            for(int j=0; j<result.size(); j++) {
                if(result[j] == str[j]) temp.push_back(result[j]);
                else temp.push_back('?');
            }
            result = temp;
        }
    }

    cout << result << endl;

    return 0;
}
