#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(string a, string b) {
    return a + b > b + a;
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> v;
    for (int i : numbers) {
        v.push_back(to_string(i));
    }
    sort(v.begin(), v.end(), cmp);
    
    for (int i = 0; i < v.size(); i++) {
        answer += v[i];
        if (answer == "0") return answer;
    }

    return answer;
}