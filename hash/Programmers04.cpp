#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    unordered_map<string, int>hash;
    
    for(vector<string> cloth : clothes) {
        hash[cloth[1]]++;
    }
    
    answer++;
    for(pair<string, int> p : hash) {
        answer *= p.second + 1;
    }
    answer--;
    
    return answer;
}