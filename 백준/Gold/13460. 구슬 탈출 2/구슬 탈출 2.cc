//https://www.acmicpc.net/problem/13460
//13460. 구슬 탈출 2(Gold 1, 시뮬레이션, BFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INF 999999999
using namespace std;

struct INFO {
    int rx, ry, bx, by, cnt;
};

INFO start;
char board[10][10];
bool visited[10][10][10][10];
int N, M;
int ans = -1;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int bfs() {

    queue<INFO> q;
    q.push(start);
    visited[start.rx][start.ry][start.bx][start.by] = true;

    int ret = -1;
    while(!q.empty()) {

        INFO cur = q.front();
        q.pop();
        if(cur.cnt > 10) break;
        if(board[cur.rx][cur.ry] == 'O' && board[cur.bx][cur.by] != 'O') {
            ret = cur.cnt;
            break;
        }

        for(int i = 0; i < 4; i++) {
            int nrx = cur.rx;
            int nry = cur.ry;
            int nbx = cur.bx;
            int nby = cur.by;

            //빨간 공 먼저 굴리자
            while(1) {
                //이동할 칸이 벽이나 구멍이 아니면 좌표 + 1
                if(board[nrx][nry] != '#' && board[nrx][nry] != 'O') {
                    nrx = nrx + dx[i];
                    nry = nry + dy[i];
                }
                else {
                    //이동한 칸이 벽이라면 좌표 -1
                    if(board[nrx][nry] == '#') {
                        nrx = nrx - dx[i];
                        nry = nry - dy[i];
                    }
                    break;
                }
            }

            //파란 공 굴리기
            while(1) {
                //이동할 칸이 벽이나 구멍이 아니면 좌표 + 1
                if(board[nbx][nby] != '#' && board[nbx][nby] != 'O') {
                    nbx = nbx + dx[i];
                    nby = nby + dy[i];
                }
                else {
                    //이동한 칸이 벽이라면 좌표 -1
                    if(board[nbx][nby] == '#') {
                        nbx = nbx - dx[i];
                        nby = nby - dy[i];
                    }
                    break;
                }
            }

            //두 공 모두 굴렸는데 좌표가 같은 경우
            if(nrx == nbx && nry == nby) {
                //두 좌표가 모두 구멍이었다면 둘 다 탈출했을테니 고려할 필요 없음
                if(board[nrx][nry] != 'O') {
                    //방향마다 다 고려하지 말고 이동거리를 구해서 이동을 더 많이 한쪽이 한발 물러서야 한다.
                    int rdist = abs(nrx - cur.rx) + abs(nry - cur.ry);
                    int bdist = abs(nbx - cur.bx) + abs(nby - cur.by);
                    if(rdist > bdist) {
                        nrx = nrx - dx[i];
                        nry = nry - dy[i];
                    } 
                    else {
                        nbx = nbx - dx[i];
                        nby = nby - dy[i];
                    }
                }
            }

            if(visited[nrx][nry][nbx][nby] == 0) {
                visited[nrx][nry][nbx][nby] = true;
                INFO next;
                next.rx = nrx;
                next.ry = nry;
                next.bx = nbx;
                next.by = nby;
                next.cnt = cur.cnt + 1;
                q.push(next);
            }
        } 
    }
    return ret;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    //INPUT
    int rx, ry, bx, by;

    memset(visited, 0, sizeof(visited));
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
            if(board[i][j] == 'R') {
                start.rx = i;
                start.ry = j;
            }
            else if(board[i][j] == 'B') {
                start.bx = i;
                start.by = j;
            }
        }
    }
    start.cnt = 0;

    //SOLVE
    ans = bfs();

    //OUTPUT
    cout << ans;
}
/*
겁나 어렵네...
https://www.youtube.com/watch?v=SarTy3ZwmVo&t=1114s
큐를 이용해서 (rx, ry, bx, by, cnt) 구조체를 bfs로 풀 것인데
만약에 현재 구슬의 위치가 이전 구슬의 위치와 동일하면 큐에 넣지 않는다(visited로 체크)
두 공이 같은 좌표에 있다면 굴린 방향을 고려하여 하나의 구슬만 -1 해준다.
*/