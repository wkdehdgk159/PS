//https://www.acmicpc.net/problem/12100
//12100. 2048(Easy)(Gold 2, 브루트포스, 백트래킹)

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

int N, ans = 0;
int board[20][20];

void play_turn(int turn, int dir) {
    if(turn == 6) {
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(board[i][j] > ans) ans = board[i][j];
            }
        }
        return;
    }

    //오른쪽 방향
    if(dir == 1) {
        //모든 행에 대해
        for(int i = 0; i < N; i++) {
            int pidx = N - 1; //저장될 인덱스
            int tmp = 0;
            for(int idx = N - 1; idx >= 0; idx--) {
                //현재 칸이 0이라면 볼 것도 없음
                if(board[i][idx] == 0) {
                    continue;
                }
                //이전 칸들에 비교할 대상이 없거나 같지 않다면 저장 후 다음 칸으로
                if(board[i][idx] != tmp) {
                    //tmp가 0이 아니라면 합쳐지지 않을 숫자라는 의미이므로 저장
                    board[i][pidx] = board[i][idx];
                    pidx--;
                    tmp = board[i][idx];
                    continue;
                }
                //비교할 대상이 존재하고 현재 칸과 같다면 합체 후 초기화
                else if(board[i][idx] == tmp) {
                    board[i][pidx+1] = tmp * 2;
                    tmp = 0;
                }
            }
            //남은 모든 칸들은 0으로 만들어주기
            for(int j = 0; j <= pidx; j++) board[i][j] = 0;
        }
    }
    //왼쪽 방향
    if(dir == 2) {
        for(int i = 0; i < N; i++) {
            int pidx = 0, tmp = 0;
            for(int idx = 0; idx < N; idx++) {
                if(board[i][idx] == 0) {
                    continue;
                }
                if(board[i][idx] != tmp) {
                    board[i][pidx] = board[i][idx];
                    pidx++;
                    tmp = board[i][idx];
                    continue;
                }
                else if(board[i][idx] == tmp) {
                    board[i][pidx-1] = tmp * 2;
                    tmp = 0;
                }
            }
            for(int j = pidx; j < N; j++) board[i][j] = 0;
        }
    }
    //위쪽 방향
    if(dir == 3) {
        for(int i = 0; i < N; i++) {
            int pidx = 0, tmp = 0;
            for(int idx = 0; idx < N; idx++) {
                if(board[idx][i] == 0) continue;
                if(board[idx][i]!= tmp) {
                    board[pidx][i] = board[idx][i];
                    pidx++;
                    tmp = board[idx][i];
                    continue;
                }
                else if(board[idx][i] == tmp) {
                    board[pidx-1][i] = tmp * 2;
                    tmp = 0;
                }
            }
            for(int j = pidx; j < N; j++) board[j][i] = 0;
        }
    }
    //아래 방향
    if(dir == 4) {
        for(int i = 0; i < N; i++) {
            int pidx = N-1, tmp = 0;
            for(int idx = N-1; idx >= 0; idx--) {
                if(board[idx][i] == 0) continue;
                if(board[idx][i]!= tmp) {
                    board[pidx][i] = board[idx][i];
                    pidx--;
                    tmp = board[idx][i];
                    continue;
                }
                else if(board[idx][i] == tmp) {
                    board[pidx+1][i] = tmp * 2;
                    tmp = 0;
                }
            }
            for(int j = 0; j <= pidx; j++) board[j][i] = 0;
        }
    }

    int tmp[20][20];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            tmp[i][j] = board[i][j];
        }
    }
    for(int i = 1; i < 5; i++) {
        play_turn(turn + 1, i);
        //다른 방향을 위한 백트래킹
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                board[i][j] = tmp[i][j];
            }
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
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    // SOLVE
    play_turn(0, 0);

    //OUTPUT
    cout << ans;
}