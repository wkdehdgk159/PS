//https://www.acmicpc.net/problem/17780
//17780. 새로운 게임(Gold 2, 구현)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long

using namespace std;

int N, K, ans = 0;
int direction[11]; //체스말의 이동방향
pair<int, int> p[11]; //체스말의 위치
int color[13][13]; //체스칸의 색깔
int height[13][13]; //체스칸의 말의 높이
int sq_arr[13][13][11]; //해당 체스칸의 체스말 배열
//idx순서대로 1은 우향, 2는 좌향, 3은 북향, 4는 남향
int dx[5] = {0, 0, 0, -1, 1};
int dy[5] = {0, 1, -1, 0, 0};
int a_flag = 0; //a_flag는 높이가 4 이상인게 생겼는지 체크,

void reverse(int x, int y) {
    if(height[x][y] <= 1) return;
    for(int i = 0; i < height[x][y] / 2; i++) {
        int tmp = sq_arr[x][y][i];
        sq_arr[x][y][i] = sq_arr[x][y][height[x][y] - 1 - i];
        sq_arr[x][y][height[x][y] - 1 - i] = tmp;
    }
}

void white(int x, int y, int nx, int ny) {
    for(int i = height[nx][ny]; i < height[nx][ny] + height[x][y]; i++) {
        //복사
        sq_arr[nx][ny][i] = sq_arr[x][y][i - height[nx][ny]];
    }
    //체스말 위치 변경 + 원래 칸 초기화 
    for(int i = 0; i < height[x][y]; i++) {
        p[sq_arr[x][y][i]].first = nx;
        p[sq_arr[x][y][i]].second = ny;
        sq_arr[x][y][i] = 0;
    }
    height[nx][ny] += height[x][y];
    height[x][y] = 0;
    if(height[nx][ny] >= 4) a_flag = 1;
}

void red(int x, int y, int nx, int ny) {
    //순서를 뒤집은 후에 그대로 옮겨주면 되므로, 본인 칸에서 순서 뒤집기 -> white()
    reverse(x, y);
    white(x, y, nx, ny);
}

void blue(int k) {
    if(direction[k] == 1) direction[k] = 2;
    else if(direction[k] == 2) direction[k] = 1;
    else if(direction[k] == 3) direction[k] = 4;
    else if(direction[k] == 4) direction[k] = 3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(height, 0, sizeof(height));
    memset(sq_arr, 0, sizeof(sq_arr));
    cin >> N >> K;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> color[i][j];
        }
    }
    //체스말의 위치와 방향 입력 후 체스칸에도 반영해주기
    for(int i = 1; i <= K; i++) {
        int tx, ty;
        cin >> tx >> ty >> direction[i];
        p[i].first = tx, p[i].second = ty;
        sq_arr[tx][ty][0] = i;
        height[tx][ty] = 1;
    }

    //SOLVE
    while(true) {
        ans++;
        //모든 말을 한번씩
        for(int i = 1; i <= K; i++) {
            int x = p[i].first;
            int y = p[i].second;
            //만약 현재 움직여야할 체스말이 가장 아래에 있는 것이 아니라면 skip
            if(sq_arr[x][y][0] != i) continue;

            int nx = x + dx[direction[i]];
            int ny = y + dy[direction[i]];

            //갈 곳이 blue 혹은 체스판 밖이라면
            if(nx < 1 || nx > N || ny < 1 || ny > N || color[nx][ny] == 2) {
                //방향 바꿔주기
                blue(i);
                nx = x + dx[direction[i]];
                ny = y + dy[direction[i]];
                //blue 바꿔준 후에도 blue가 나온 것이기 때문에 그냥 넘겨준다.
                if(nx < 1 || nx > N || ny < 1 || ny > N || color[nx][ny] == 2) {
                    continue;
                }
            }

            //갈 곳이 white라면
            if(color[nx][ny] == 0) {
                white(x, y, nx, ny);
            }
            //갈 곳이 red라면
            else if(color[nx][ny] == 1) {
                red(x, y, nx, ny);
            }

            if(a_flag) break;
        }
        //4이상이면 종료
        if(a_flag || ans > 1000) break;
    }

    //OUTPUT
    if(ans > 1000) ans = -1;
    cout << ans;
}