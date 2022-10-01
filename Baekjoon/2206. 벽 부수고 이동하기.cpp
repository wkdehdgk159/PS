//https://www.acmicpc.net/problem/2206
//2206. 벽 부수고 이동하기(Gold 3, BFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
using namespace std;

int N, M, min_len = 1000001;
bool board[1000][1000];
bool visited[1000][1000][2]; 
//벽을 부수고 온 경우를 따로 저장해야 한다. 늦게 탐색된 경로가 벽을 부수지 않았는데도 벽을 보고 좌절하는 경우를 방지
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void bfs() {
    queue<pair<pair<int, int>, pair<int, int> > > q;
    //(x좌표, y좌표, 벽을 부쉈는가 여부, 현재까지 경로의 길이)
    q.push(make_pair(make_pair(0, 0), make_pair(0, 1)));

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int broken = q.front().second.first;
        int path_len = q.front().second.second;
        q.pop();
        if(x == N - 1 && y == M - 1) {
            min_len = min(min_len, path_len);
        }

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(0 <= nx && nx < N && 0 <= ny && ny < M) {
                //벽을 부수고 왔다면
                if(broken == 1) {
                    if(board[nx][ny] == 0 && visited[nx][ny][1] == 0) {
                        visited[nx][ny][1] = 1;
                        q.push(make_pair(make_pair(nx, ny), make_pair(1, path_len + 1)));
                    }
                } 
                //벽을 안 부수고 왔다면
                else {
                    if(visited[nx][ny][0] == 0) {
                        if(board[nx][ny] == 0) {
                            visited[nx][ny][0] = 1;
                            q.push(make_pair(make_pair(nx, ny), make_pair(0, path_len + 1)));
                        } else {
                            visited[nx][ny][1] = 1;
                            q.push(make_pair(make_pair(nx, ny), make_pair(1, path_len + 1)));
                        }
                    }
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

    //INPUT
    memset(board, false, sizeof(board));
    memset(visited, false, sizeof(visited));

    char tmp[1050];
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        cin >> tmp;
        for(int j = 0; j < M; j++) {
            board[i][j] = tmp[j] - 48;
        }
    }

    //SOLVE
    visited[0][0][0] = 1;
    bfs();

    //OUTPUT
    if(min_len == 1000001) min_len = -1;
    cout << min_len;

    return 0;
}
//visited를 벽을 부순 경우와 아닌 경우를 구별해야하는 이유를 몰랐는데 블로그의 도움을 받았다.