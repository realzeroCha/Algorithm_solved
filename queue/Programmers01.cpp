#include <vector>
#include <iostream>
#include <queue>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    queue<int> q;
    
    for(int i: arr) {
        if(q.empty() || q.back() != i) {
            q.push(i);
            answer.push_back(i);
        }   
    }

    return answer;
}