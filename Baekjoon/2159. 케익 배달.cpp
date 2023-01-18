//https://www.acmicpc.net/problem/2159
//2159. 케익 배달(Gold2, DP, DFS) 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long

using namespace std;

int N;
pair<int, int> loc[100001];
int dx[5] = {0, 1, -1, 0, 0};
int dy[5] = {0, 0, 0, 1, -1};
ll dp[100001][5];

// ll cal(int x, int y, int idx, int n) {
//     if(idx == N) return 0;
//     ll &ret = dp[idx][n];
//     if(ret != -1) return ret;

//     ret = LL_INF;
    
//     for(int i = 0; i < 5; i++) {
//         int nx = loc[idx + 1].first + dx[i];
//         int ny = loc[idx + 1].second + dy[i];
//         if(nx < 1 || nx > 100000 || ny < 1 || ny > 100000) continue;
//         int dist = abs(nx - x) + abs(ny - y);
//         ret = min(ret, dist + cal(nx, ny, idx + 1, i));
//     }

//     return ret;
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> loc[0].first >> loc[0].second;

    for(int i = 1; i <= N; i++) {
        cin >> loc[i].first >> loc[i].second;
    }

    //SOLVE
    // memset(dp, -1, sizeof(dp));
    // cout << cal(loc[0].first, loc[0].second, 0, 0);

    memset(dp, 0, sizeof(dp));
    for(int i = 1; i <= N; i++) {
        for(int j = 0; j < 5; j++) {
            dp[i][j] = LL_INF;
            for(int k = 0; k < 5; k++) {
                int cx = loc[i].first + dx[j];
                int cy = loc[i].second + dy[j];
                int px, py;
                if(i == 1) {
                    px = loc[i-1].first;
                    py = loc[i-1].second;
                } else {
                    px = loc[i-1].first + dx[k];
                    py = loc[i-1].second + dy[k];
                }
                if(cx < 1 || cx > 100000 || cy < 1 || cy > 100000) continue;
                if(px < 1 || px > 100000 || py < 1 || py > 100000) continue;
                dp[i][j] = min(dp[i][j], dp[i-1][k] + abs(cx - px) + abs(cy - py));
            } 
        }
    }

    //OUTPUT
    ll ans = LL_INF;
    for(int i = 0; i < 5; i++) {
        ans = min(ans, dp[N][i]);
    }
    cout << ans;
}