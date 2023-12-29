//https://www.acmicpc.net/problem/1913
//1913. 달팽이(Silver 3, 구현)

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

int board[1000][1000];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    int N, target;
    cin >> N >> target;
    memset(board, 0, sizeof(board));

    //SOLVE
    int cur_num = N * N;
    int cx = 1, cy = 1;
    int dir = 0;
    vector<int> answer;

    while(true) {
        board[cx][cy] = cur_num;
        if(cur_num == target) {
            answer.push_back(cx);
            answer.push_back(cy);
        }

        int nx = cx + dx[dir];
        int ny = cy + dy[dir];
        //다음 갈 칸이 이미 들린 칸이거나 경계 이상이라면 방향 전환
        if(nx < 1 || nx >= N + 1 || ny < 1 || ny >= N + 1 || board[nx][ny]) {
            dir++;
            if(dir == 4) dir = 0;
            nx = cx + dx[dir];
            ny = cy + dy[dir];
        }

        cx = nx;
        cy = ny;
        cur_num--;
        
        if(cur_num == 0) break;
    }



    //OUTPUT
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << answer[0] << " " << answer[1];
}

/*
1. (1,1) 을 N제곱으로 잡고 뻉뻉 돌자
*/