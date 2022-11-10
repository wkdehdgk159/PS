//https://www.acmicpc.net/problem/2666
//2666. 벽장문의 이동(Gold 5, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long

using namespace std;

int ans = 0;
int N, cnt;
int arr[21];
int dp[21][21][21]; //dp[idx][i][j]; arr[idx]번째 벽장을 쓰기 위해 i나 j로 벽장을 밀어야할 때 걸리는 최소 회수

int cal(int idx, int w1, int w2) {
    if(idx > cnt) return 0;
    if(dp[idx][w1][w2] != -1) return dp[idx][w1][w2];

    //w1을 고르면 지금 arr[idx]벽장이 w1을 대체
    int can1 = abs(arr[idx] - w1) + cal(idx + 1, arr[idx], w2);
    int can2 = abs(arr[idx] - w2) + cal(idx + 1, w1, arr[idx]);

    return dp[idx][w1][w2] = min(can1, can2);
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    int w1, w2;
    cin >> N;
    cin >> w1 >> w2;
    cin >> cnt;
    for(int i = 1; i <= cnt; i++) {
        cin >> arr[i];
    }

    //SOLVE
    memset(dp, -1, sizeof(dp)); //memset은 0이나 -1만 되는 것 주의

    //OUTPUT
    cout << cal(1, w1, w2);
}
//예전 삼성 알고리즘 문제에서도 4차원배열 쓰는 문제는 포기했었는데 슬슬 기대가 된다