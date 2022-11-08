//https://www.acmicpc.net/problem/2011
//2011. 암호코드(Gold 5, DP)

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
int dp[5001];
string code;

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> code;

    //SOLVE
    memset(dp, 0, sizeof(dp));

    int code_len = code.length();
    if(code[0] == '0') {
        cout << 0;
        return 0;
    }

    dp[0] = 1;
    //10, 20일 때 확정되는 것 조심
    for(int i = 1; i < code_len; i++) {
        //0이 아닌 수라면 최소 dp[i-1]과 조합 가능
        if(code[i] != '0') dp[i] = dp[i-1] % 1000000;

        int check = int(code[i - 1] - '0') * 10 + int(code[i] - '0');
        //2자리수면 dp[i-2]와 조합가능 10, 20은 dp[i-2]와만 조합이 가능한데 위에서 걸러줌
        if(check >= 10 && check <= 26) {
            if(i == 1) dp[i] += 1;
            else dp[i] = (dp[i] + dp[i-2]) % 1000000;
        }
    }

    //OUTPUT
    cout << dp[code_len-1];
}
//흠 0으로 시작하는 코드도 주어지는 예외를 생각못해서 시간이 걸렸다.