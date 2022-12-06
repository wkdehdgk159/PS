//https://www.acmicpc.net/problem/2302
//2302. 극장 좌석(Silver 1, DP) 

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
int ans = 1;
int dp[41][2]; //dp[i][0]은 마지막 자리에 해당 숫자가 딱 맞게 끝나는 경우
//피보나치 규칙이 존재하기때문에 1차원 배열로 해도 무방하긴 함
vector<int> VIP;
vector<int> interval;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M;
    int tmp;
    for(int i = 0; i < M; i++) {
        cin >> tmp;
        VIP.push_back(tmp);
    }

    //SOLVE
    for(int i = 0; i < VIP.size(); i++) {
        if(i == 0) interval.push_back(VIP[i] - 1);
        else interval.push_back(VIP[i] - VIP[i-1] - 1);

        if(i == VIP.size() - 1) interval.push_back(N - VIP[i]);
    }

    memset(dp, 0, sizeof(dp));
    dp[1][0] = 1;
    dp[2][0] = 1, dp[2][1] = 1;
    for(int i = 2; i <= N; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1]; //이전에 가능한 경우에 i만 붙이면 됨
        dp[i][1] = dp[i-1][0]; //이전에 제자리에서 끝난 친구여야만 i-1과 i가 스왑하면서 i-1로 끝날 가능성이 생김
    }

    if(M == 0) ans = dp[N][0] + dp[N][1];
    else {
        for(int i = 0; i <= interval.size(); i++) {
            if(interval[i] != 0) ans *= dp[interval[i]][0] + dp[interval[i]][1];
        }
    }

    //OUTPUT
    cout << ans;
}
//VIP 좌석을 기준으로 각각 독립된 경우의 수를 구하고 곱해주면 된다.
//dp는 2차원배열을 선언하는 것이 더 dp스럽지만 막무가내로 구해보면 피보나치와 같다