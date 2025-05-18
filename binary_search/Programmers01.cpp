#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    long long low = 1;
    long long high = (long long)times.back() * n;

    while(low <= high) {
        long long mid = (low + high) / 2;

        long long total = 0;
        for(int x : times) {
            total += mid / x;
        }

        if (total >= n) {
            answer = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    
    return answer;
}