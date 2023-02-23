//https://www.acmicpc.net/problem/4991
//4991. 로봇 청소기(Gold 2, BFS)

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

int R, C, ans;
char board[20][20];
bool visited[20][20];
bool s_visited[11];
int dist[20][20]; //기준점으로부터 다른 칸들까지의 거리
int s_dist[11][11]; //시작점 + 더러운 칸 들 간의 거리.
pair<int, int> spot[11];
int spot_size = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int idx) {
    memset(visited, 0, sizeof(visited));
    for(int i = 0; i < R; i++) {
        for(int j = 0; j < C; j++) {
            dist[i][j] = INT_INF;
        }
    }
    int x = spot[idx].first;
    int y = spot[idx].second;
    dist[x][y] = 0;
    queue<pair<int, int> > q;

    q.push(make_pair(x, y));
    visited[x][y] = 1;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= R || ny >= C || visited[nx][ny] || board[nx][ny] == 'x') continue;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = 1;
            dist[nx][ny] = dist[cx][cy] + 1;
        }
    }

    for(int i = 0; i <= spot_size; i++) {
        s_dist[idx][i] = dist[spot[i].first][spot[i].second];
        if(s_dist[idx][i] == INT_INF) ans = -1;
    }
}

void dfs(int ss, int cnt, int td) {
    if(cnt == spot_size) {
        ans = (ans > td) ? td : ans;
        return;
    }

    for(int i = 1; i <= spot_size; i++) {
        if(s_visited[i]) continue;
        s_visited[i] = 1;
        dfs(i, cnt + 1, td + s_dist[ss][i]);
        s_visited[i] = 0;
    }
} 

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT

    //SOLVE
    while(true) {
        cin >> C >> R;
        if(C == 0 && R == 0) break;

        ans = INT_INF;
        memset(s_dist, 0, sizeof(s_dist));
        int idx = 1;
        for(int i = 0; i < R; i++) {
            for(int j = 0; j < C; j++) {
                cin >> board[i][j];
                if(board[i][j] == 'o') spot[0] = make_pair(i, j);
                else if(board[i][j] == '*') {
                    spot[idx] = make_pair(i, j);
                    idx++;
                }
            }
        }
        spot_size = idx-1;
        //더러운 칸이 없는 경우
        if(spot_size == 0) {
            cout << 0 << endl; continue;
        }


        for(int i = 0; i <= spot_size; i++) {
            bfs(i);
        }
        if(ans == -1) {
            cout << ans << endl;
            continue;
        }
        dfs(0, 0, 0);//시작점, 청소 횟수, 총 이동 거리

        cout << ans << endl;
    }

    //OUTPUT
}
//아기 상어 문제처럼 bfs로 최소거리 찾고 dfs로 완전탐색하는 문제!