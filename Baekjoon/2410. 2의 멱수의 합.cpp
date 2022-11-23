//https://www.acmicpc.net/problem/2410
//2410. 2의 멱수의 합(Gold 5, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long

using namespace std;

int N;
int dp[1000001];

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;

    //SOLVE
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for(int i = 1; i <= N; i*=2) {
        for(int j = i; j <= N; j++) {
            dp[j] = (dp[j] + dp[j - i]) % 1000000000;
        }
    }

    //OUTPUT
    cout << dp[N];
}
//얼마 전에 푼 동전 문제랑 비슷해서 금방 풀었다