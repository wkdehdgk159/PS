//https://www.acmicpc.net/problem/2616
//2616. 소형 기관차(Gold 3, DP, 누적합)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long
using namespace std;

int arr[50001];
int sumarr[50001];
int dp[50001][4]; //dp[i][j]는 i번째 객차까지 j대가 배차되었을 때 최대값
int N, max_g, ans = -1;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];
    cin >> max_g;

    //SOLVE
    //누적합 계산
    int tmp = 0;
    for(int i = 1; i <= max_g; i++) {
        tmp += arr[i];
    }
    sumarr[1] = tmp;
    for(int i = 2; i <= N - max_g + 1; i++) {
        sumarr[i] = sumarr[i-1] - arr[i-1] + arr[i + max_g - 1];
    }

    //dp[j][i] j번째 객차까지 i대 배치되었을 때의 손님 최대값은
    //j-1번째 객차까지 i대 배치된 경우와    j번째 객차에 i번째 기관차가 배치된 경우의 최대값.
    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= 3; i++) {
        for(int j = i * max_g; j <= N; j++) {
            dp[j][i] = max(dp[j-1][i], dp[j-max_g][i-1] + sumarr[j - max_g + 1]);
        }
    }

    //OUTPUT
    cout << dp[N][3];
}