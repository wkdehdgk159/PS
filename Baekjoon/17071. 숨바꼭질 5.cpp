//https://www.acmicpc.net/problem/17071
//17071. 숨바꼭질 5(Platinum 5, BFS)

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

int N, K, ans = INT_INF;
int min_time[2][500001];
bool visited[2][500001];

void bfs(int start) {
    queue<pair<int, int> > q;
    q.push(make_pair(start, 0));
    visited[0][start] = 1;

    while(!q.empty()) {
        int cx = q.front().first;
        int ct = q.front().second;
        q.pop();

        int e_o = (ct + 1) % 2;
        if(cx * 2 <= 500000 && visited[e_o][cx*2] == 0) {
            q.push(make_pair(cx * 2, ct+1));
            visited[e_o][cx * 2] = 1;
            min_time[e_o][cx * 2] = ct + 1;
        }
        if(cx + 1 <= 500000 && visited[e_o][cx+1] == 0) {
            q.push(make_pair(cx + 1, ct+1));
            visited[e_o][cx + 1] = 1;
            min_time[e_o][cx + 1] = ct + 1;
        }
        if(cx - 1 >= 0 && visited[e_o][cx-1] == 0) {
            q.push(make_pair(cx - 1, ct+1));
            visited[e_o][cx - 1] = 1;
            min_time[e_o][cx - 1] = ct + 1;
        }
    }
    return;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> K;

    // SOLVE
    memset(visited, 0, sizeof(visited));
    if(N == K) {
        cout << 0; return 0;
    }
    bfs(N);

    int idx = 1;
    for(int i = K + 1; i <= 500000; i += idx) {
        int e_o = idx % 2;
        //해당 위치에 수빈이가 갈 수 있고 홀짝이 같고 수빈이가 갈 수 있는 최소 시간이 동생의 시간보다 짧거나 같다면 정답 갱신
        if(visited[e_o][i] && min_time[e_o][i] <= idx) {
            ans = idx;
            break;
        }
        idx++;
    }

    //OUTPUT
    if(ans == INT_INF) cout << -1;
    else cout << ans;
}
//카테고리가 BFS라 무슨 말인가 했는데 홀짝의 개념을 잘 떠올려야 했던 문제