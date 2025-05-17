#include <string>
#include <vector>

using namespace std;

int cnt = 0;

void dfs(vector<int>& numbers, int target, int x, int sum) {
    if(x == numbers.size()) {
        if(sum == target) cnt++;
        return;
    }

    dfs(numbers, target, x+1, sum + numbers[x]);
    dfs(numbers, target, x+1, sum - numbers[x]);
}
 

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    dfs(numbers, target, 0, 0);
    
    answer = cnt;
    
    return answer;
}