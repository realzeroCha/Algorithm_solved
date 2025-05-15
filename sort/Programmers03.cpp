#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    for(int i=citations.size(); i>0; i--) {
        int num = 0;
        for(int j=0; j < citations.size(); j++) {
            if(citations[j] >= i) num++;
        }
        if(num >= i) return i;
    }

    return answer;
}