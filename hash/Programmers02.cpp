#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    unordered_map<int, int> hashMap;
    for(int i: nums) {
        hashMap[i]++;
    }
    
    int hashSize = hashMap.size();
    int numsSize = nums.size();
    answer = min(hashSize, numsSize/2);
    
    return answer;
}