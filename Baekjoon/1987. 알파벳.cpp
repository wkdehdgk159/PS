//https://www.acmicpc.net/problem/1987
//알파벳(Gold 4, DFS, 백트래킹)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

int R, C;
int board[20][20];
bool check[26];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
int max_len = 0;

void dfs(int x, int y, int cnt) {

    max_len = max(cnt, max_len);

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < R && 0 <= ny && ny < C) {
            if(check[board[nx][ny]] == 0) {
                check[board[nx][ny]] = 1;
                dfs(nx, ny, cnt + 1);
                check[board[nx][ny]] = 0;
            }
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    //INPUT
    memset(board, 0, sizeof(board));
    memset(check, 0, sizeof(check));

    char tmp[25];
    cin >> R >> C;

    //바로 정수형태로 변환
    for(int i = 0; i < R; i++) {
        cin >> tmp;
        for(int j = 0; j < C; j++) {
            board[i][j] = tmp[j] - 'A';
        }
    }

    //SOLVE
    check[board[0][0]] = 1;
    dfs(0, 0, 1);
    
    //OUTPUT
    cout << max_len;

    return 0;
}
//엄청 오래 걸린 문제였다. 예제 답도 잘 나오고 엣지 케이스들도 다 나와서 고민고민하다 블로그까지 봤는데 논리구조도 똑같았다. 틑린 이유는 한 줄을 받는 tmp 변수를 tmp[20]으로 설정해서였다. 25로 크기를 늘리니 해결되었다. 왜 그런지는 백준 고수님들이 알려줄 것이다..