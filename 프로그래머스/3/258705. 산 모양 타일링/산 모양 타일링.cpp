#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long dp[200002] = {0};

int solution(int n, vector<int> tops) {
    int answer = 0;
    dp[1] = 1;
    dp[2] = 2;
    if(tops[0] == 1) dp[2] = 3;
    for(int i = 3; i <= 2 * n + 1; i++) {
        dp[i] = dp[i-1] + dp[i-2];
        //대가리가 달린 경우
        if(i % 2 == 0 && tops[i/2 - 1] == 1) {
            dp[i] += dp[i-1];
        }
        dp[i] %= 10007;
    }
    
    answer = dp[2 * n + 1] % 10007;
    return answer;
}
//이거 좀 복잡한데
//삼각형 추가 시에는 마름모를 더하는 꼴로 dp[n-2], 삼각형을 추가하는 꼴로 dp[n-1] 을 더하면 된다.
//대가리 추가시 이전 추가하기 전 n-1 에서 만들 수 있는 경우의 수가 추가된다.
