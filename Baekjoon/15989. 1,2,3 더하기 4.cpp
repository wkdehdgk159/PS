//https://www.acmicpc.net/problem/15989
//15989. 1,2,3 더하기 4(Silver 1, 다이나믹 프로그래밍)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;
int dp[10001][4];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    int T;
    cin >> T;
    memset(dp, 0, sizeof(dp));

    //SOLVE
    //이전 수의 조합에 1, 2, 3을 붙인다는 느낌. DP[i][j]는 i 수를 조합 시 정렬했을 때 j로 끝나는 경우의 수를 말한다.
    dp[0][1] = 1;
    dp[1][1] = 1;
    for(int i = 2; i < 10001; i++) {
        dp[i][1] = dp[i - 1][1];
        dp[i][2] = dp[i - 2][1] + dp[i - 2][2];
        if(i >= 3) dp[i][3] = dp[i - 3][1] + dp[i - 3][2] + dp[i - 3][3];
    }

    //OUTPUT
    for(int i = 0; i < T; i++) {
        int a;
        cin >> a;
        cout << dp[a][1] + dp[a][2] + dp[a][3] << endl;
    }

    return 0;
}
//카테고리를 보고 나서야 감이 잡힌 어려운 문제였다 ㅠㅠ DP일 줄이야