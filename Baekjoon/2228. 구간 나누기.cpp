//https://www.acmicpc.net/problem/2228
//2228. 구간 나누기(Gold 4, DP, 누적합)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long

using namespace std;

int N, M;
int arr[100];
int dp[100][51]; //dp[i][j]는 i번째 원소까지를 j개의 구간으로 나눴을 때의 최대값
int acu_sum[100][100];

int cal(int n, int m) {
    if(m == M) return 0;
    if(n >= N) return -INF;
    if(dp[n][m] != -1) return dp[n][m];

    //n번째 원소가 앞선 구간에 포함 or 포함되지 않고 구간의 구별점으로 쓰임
    dp[n][m] = cal(n+1, m);
    for(int i = n; i < N; i++) {
        dp[n][m] = max(dp[n][m], acu_sum[n][i] + cal(i+2, m+1));
    }
    return dp[n][m];
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M;
    for(int i = 0; i < N; i++) cin >> arr[i];

    //SOLVE
    memset(dp, -1, sizeof(dp)); //memset은 0이나 -1만 되는 것 주의
    //누적합 계산
    for(int i = 0; i < N; i++) {
        int tmp = 0;
        for(int j = i; j < N; j++) {
            tmp += arr[j];
            acu_sum[i][j] = tmp;
        }
    }

    //OUTPUT
    cout << cal(0, 0);
}
//top-down 방식이 아직은 덜 익숙해진 듯 하다