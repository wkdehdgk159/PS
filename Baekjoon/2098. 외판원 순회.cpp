//https://www.acmicpc.net/problem/2098
//2098. 외판원 순회(Gold 1, DP, 그래프)

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
int weight[16][16];
int dp[16][1 << 16]; //dp[0][1]은 0번째 도시에서 시작해 다시 0번쨰 도시로 돌아오는 weight

int TSP(int curr, int visited) { //visited 의미는 각 비트가 1인 경우 해당번째 도시를 방문했다는 뜻
    //모든 도시를 방문했다면 curr에서 다시 0번째 도시로 가는 길이 있는지 확인
    if(visited == (1 << N) - 1) {
        //가는 길이 없다면 INF 리턴
        return weight[curr][0] ? weight[curr][0] : INF;
    }

    //계산된 길이 있다면 리턴
    if(dp[curr][visited]) return dp[curr][visited];

    dp[curr][visited] = INF;

    for(int i = 0; i < N; i++) {
        //가는 길이 없거나 방문한 도시(비트)일 경우 continue
        if(weight[curr][i] == 0 || visited & (1 << i)) continue;

        //i번째 비트 방문처리 해주고 (+가 아니라 | or 연산도 가능했음)
        //i번째 도시에서 현재까지 거쳐온 도시를 지나지 않고 0번째 도시로 가는 tmp를 계산
        int tmp = TSP(i, visited + (1 << i));
        dp[curr][visited] = min(dp[curr][visited], weight[curr][i] + tmp);
    }

    return dp[curr][visited];
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(weight, 0, sizeof(weight));
    memset(dp, 0, sizeof(dp));
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> weight[i][j];
        }
    }

    //SOLVE
    cout << TSP(0, 1);

    //OUTPUT
} 
//알고분 수업에서도 배웠던 TSP문제인데 완전 까먹어서 블로그를 참고했다