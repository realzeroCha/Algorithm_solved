#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    unordered_map<string, int> hashMap;
    
    for(int i=0; i<participant.size(); i++) {
        hashMap[participant[i]]++;
    };

    for(int i=0; i<completion.size(); i++) {
        hashMap[completion[i]]--;
    }

    for(pair<string, int> p: hashMap) {
        if(p.second > 0) {
            answer = p.first;
        }
    }
    
    return answer;
}