//https://www.acmicpc.net/problem/2225
//2225. 합분해(Gold 5, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N, K;
ll dp[201][201];

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> K;

    //SOLVE
    //i를 j개 숫자의 합으로 나타내는 방법(dp[i][j])은 for i = 0부터 i = N 까지의 dp[i][j-1]을 모두 더하는 것
    //이미 구성된 한 개가 모자라는 수열에 수를 붙여준다는 의미
    memset(dp, 0, sizeof(dp));

    for(int i = 0; i <= N; i++) {
        for(int j = 1; j <= K; j++) {
            if(i == 0) {
                dp[i][j] = 1;
                continue;
            }
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % 1000000000;
        }
    }
    
    //OUTPUT
    cout << dp[N][K] % 1000000000;
}
//모듈러 계산때문에 조금 애먹었던 문제
//O(N^2K)의 점화식도 곰곰히 생각하면 O(NK)로 줄일 수 있었다.