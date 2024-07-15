//https://www.acmicpc.net/problem/16236
//16236. 아기 상어(Gold 3, BFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INF 999999999
using namespace std;

int board[20][20];
bool visited[20][20];
int N;
int shark_size = 2, exp_needed = 2;
int cur_x, cur_y;
int move_flag = 1;
int ans = 0;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

//이동할 좌표 찾기 
pair<pair<int, int>, int> bfs(int x, int y) {

    queue<pair<pair<int, int>, int> > q;
    q.push({{x, y}, 0});
    visited[x][y] = true;
    int dest_x = x, dest_y = y;
    int dist = 1000;

    while(!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int cd = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || shark_size < board[nx][ny]) continue;

            //만약 자기보다 작은 물고기면서  거리의 최소값보다 이동거리가 작기까지 한다면 갱신
            if(board[nx][ny] != 0 && board[nx][ny] < shark_size) {
                //거리가 최우선
                if(cd + 1 < dist) {
                    dist = cd + 1;
                    dest_x = nx;
                    dest_y = ny;
                }
                //거리가 같다면 위치 따져주기
                if(cd + 1 == dist) {
                    if(nx < dest_x) {
                        dest_x = nx;
                        dest_y = ny;
                    }
                    else if(nx == dest_x && ny < dest_y) {
                        dest_x = nx;
                        dest_y = ny;
                    }
                }
            }

            visited[nx][ny] = true;
            q.push({{nx, ny}, cd + 1});

        }
    }

    if(dist != 1000) move_flag = 1;
    return {{dest_x, dest_y}, dist}; 

}

void move(int dest_x, int dest_y, int dist) {

    //이동거리와 현재 위치 갱신
    ans += dist;
    cur_x = dest_x;
    cur_y = dest_y;
    board[cur_x][cur_y] = 0;

    //경험치와 사이즈 갱신
    exp_needed--;
    if(exp_needed == 0) {
        shark_size++;
        exp_needed = shark_size;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
            if(board[i][j] == 9) {
                cur_x = i;
                cur_y = j;
                board[i][j] = 0;
            }
        }
    } 

    //SOLVE

    while(true) {
        memset(visited, false, sizeof(visited));
       pair<pair<int, int>, int > info = bfs(cur_x, cur_y);
       if(!move_flag) break;
       move(info.first.first, info.first.second, info.second);
       move_flag = 0;
    }

    //OUTPUT
    if(ans == 1000) ans = 0;
    cout << ans;
}