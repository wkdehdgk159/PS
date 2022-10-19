//https://www.acmicpc.net/problem/4179
//4179. 불!(Gold 4, BFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INF 999999
using namespace std;

int R, C;
char board[1001][1001];
int visited[1001][1001];
int fire[1001][1001];//몇 분 후에 해당 공간에 불이 번지는 지
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int start_x, start_y;
queue<pair<int, int> > fire_q;
int ans = INF;

void cal_fire() {
    while(!fire_q.empty()) {
        int x = fire_q.front().first;
        int y = fire_q.front().second;
        fire_q.pop();
        for(int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx >= 1 && nx <= R && ny >= 1 && ny <= C) {
                if(board[nx][ny] == '.' && fire[nx][ny] > fire[x][y] + 1) {
                    fire[nx][ny] = fire[x][y] + 1;
                    fire_q.push(make_pair(nx, ny));
                }
            }
        }
    }
}

void can_go(int a, int b, int c) {
    queue<pair<pair<int, int>, int> > q;
    q.push(make_pair(make_pair(a, b), c));
    visited[a][b] = 1;
    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int t = q.front().second;
        q.pop();
        if(x == 1 || x == R || y == C || y == 1) {
            ans = t + 1;
            return;
        }
        for(int j = 0; j < 4; j++) {
            int nx = x + dx[j];
            int ny = y + dy[j];
            if(nx >= 1 && nx <= R && ny >= 1 && ny <= C) {
                if(board[nx][ny] == '.' && fire[nx][ny] > t + 1 && !visited[nx][ny]) {
                    visited[nx][ny] = 1;
                    q.push(make_pair(make_pair(nx, ny), t + 1));
                }
            }
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    memset(board, '#', sizeof(board));
    memset(fire, INF, sizeof(fire));

    //INPUT
    cin >> R >> C;
    for(int i = 1; i <= R; i++) {
        for(int j = 1; j <= C; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'F') {
                fire[i][j] = 0;
                fire_q.push(make_pair(i, j));
            }
            if(board[i][j] == 'J') {
                start_x = i;
                start_y = j;
                board[i][j] = '.';
            }
        }
    }
    //SOLVE
    cal_fire();
    can_go(start_x, start_y, 0);

    //OUTPUT
    if(ans < INF) cout << ans;
    else cout << "IMPOSSIBLE";
}
//일단 DFS는 최소거리가 달라질 수 있기때문에 BFS를 써야하고
//이 문제의 핵심은 불이 여러 지점에서 벌어지는데 여기서의 BFS를 어떻게 최소시간에 해내느냐이다
//처음에는 각각의 발원지에 대해 따로따로 BFS를 해주었는데 이러기 보다는 발원지를 큐에 한꺼번에 넣어놓고 돌리는 게 더 빠르다.