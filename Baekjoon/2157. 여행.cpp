//https://www.acmicpc.net/problem/2157
//2157. 여행(Gold4, DP) 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
#define ll long long

using namespace std;

int AW[301][301];
int dp[301][301]; //dp[i][j]는 i번째 도시까지 j만큼 항로를 이용했을 때 기내식 최대값
int N, M, K;
int ans = 0;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M >> K;

    memset(AW, 0, sizeof(AW));
    int a, b, c;
    for(int i = 0; i < K; i++) {
        cin >> a >> b >> c;
        if(a < b) AW[a][b] = max(AW[a][b], c);
    }

    //SOLVE
    memset(dp, 0, sizeof(dp));
    for(int i = 2; i <= N; i++) {
        if(AW[1][i]) dp[i][2] = AW[1][i];
    }

    for(int i = 2; i <= N; i++) {
        for(int j = i + 1; j <= N; j++) {
            //i에서 j로 가는 항로가 존재한다면
            if(AW[i][j]) {
                //1번 도시에서 i로 오는 길이 있었는지 확인
                for(int k = 1; k < M; k++) {
                    //최대값 갱신
                    if(dp[i][k]) dp[j][k+1] = max(dp[j][k+1], dp[i][k] + AW[i][j]);
                }
            }
        }
    }

    for(int i = 1; i <= M; i++) {
        ans = max(ans, dp[N][i]);
    }

    //OUTPUT
    cout << ans;
}
//그래프 문제를 꽤 풀어봐서 그런가 골드4치고는 풀만했던 것 같다.