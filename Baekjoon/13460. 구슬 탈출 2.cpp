//https://www.acmicpc.net/problem/13460
//13460. 구슬 탈출 2(Gold 1, 구현, BFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N, M;
char board[15][15];
int ans = 100;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
pair<int, int> RM, BM, OC;
bool RF = false, BF = false, BMF = false;

void dfs(int rx, int ry, int bx, int by, int move) {
    if(move == 11) return;
    for(int i = 0; i < 4; i++) {
        int nx = rx + dx[i];
        int ny = ry + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
        int tbx = bx, tby = by;
        // 남쪽으로 굴리기
        if(i == 0) {
            //파란 구슬이 빠지는 것을 체크하기 위해 파란 구슬 먼저 굴려봄
            while(board[tbx][tby] != '#') {
                //파랑 구슬이 구멍에 빠진다면 불가한 케이스므로 break;
                if(board[tbx][tby] == 'O') BF = true;
                tbx++;
            }
            //마지막 하나 뺴줘서 좌표 완성
            tbx--; 
            while(board[nx][ny] != '#') {
                if(board[nx][ny] == 'O' && !BF) {
                    ans = min(move, ans);
                    return;
                }
                nx++;
            }
            nx--;
            if(!BF) {
                //둘이 최종 종착점이 같고 만나지 않았다면 둘이 위아래로 붙어있다는 것
                if(tbx == nx && tby == ny) {
                    //RB가 딱 붙어서 같혀 있는 상황 고려
                    if(bx > rx && board[nx-1][ny] != '#') nx--;
                    //여기까지 왔다는 것은 최소한 굴러갈 공간은 있다는 것
                    if(bx < rx) tbx--;
                }
                dfs(nx, ny, tbx, tby, move + 1);
            }
            BF = false;
        }
        // 북쪽으로 굴리기
        if(i == 1) {
            while(board[tbx][tby] != '#') {
                if(board[tbx][tby] == 'O') BF = true;
                tbx--;
            }
            tbx++; 
            while(board[nx][ny] != '#') {
                if(board[nx][ny] == 'O' && !BF) {
                    ans = min(move, ans);
                    return;
                }
                nx--;
            }
            nx++;
            if(!BF) {
                if(tbx == nx && tby == ny) {
                    if(bx < rx && board[nx+1][ny] != '#') nx++;
                    if(bx > rx) tbx++;
                }
                dfs(nx, ny, tbx, tby, move + 1);
            }
            BF = false;
        }
        //오른쪽으로 굴리기
        if(i == 2) {
            while(board[tbx][tby] != '#') {
                if(board[tbx][tby] == 'O') BF = true;
                tby++;
            }
            tby--; 
            while(board[nx][ny] != '#') {
                if(board[nx][ny] == 'O' && !BF) {
                    ans = min(move, ans);
                    return;
                }
                ny++;
            }
            ny--;
            if(!BF) {
                if(tbx == nx && tby == ny) {
                    if(by > ry && board[nx][ny - 1] != '#') ny--;
                    if(by < ry) tby--;
                }
                dfs(nx, ny, tbx, tby, move + 1);
            }
            BF = false;
        }
        //왼쪽으로 굴리기
        if(i == 3) {
            // cout << "hi" << nx << ny << " ";
            while(board[tbx][tby] != '#') {
                if(board[tbx][tby] == 'O') BF = true;
                tby--;
            }
            tby++; 
            while(board[nx][ny] != '#') {
                if(board[nx][ny] == 'O' && !BF) {
                    ans = min(move, ans);
                    return;
                }
                ny--;
            }
            ny++;
            if(!BF) {
                if(tbx == nx && tby == ny) {
                    if(by < ry && board[nx][ny + 1] != '#') ny++;
                    if(by > ry) tby++;
                }
                dfs(nx, ny, tbx, tby, move + 1);
            }
            BF = false;
        }
    }
    return;
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M;
    string tmps;
    for(int i = 0; i < N; i++) {
        cin >> tmps;
        for(int j = 0; j < M; j++) {
            board[i][j] = tmps[j];
            if(board[i][j] == 'R') {
                RM = make_pair(i, j);
            }
            else if(board[i][j] == 'B') {
                BM = make_pair(i, j);
            }
            else if(board[i][j] == 'O') {
                OC = make_pair(i, j);
            }
        }
    }
    
    //SOLVE
    dfs(RM.first, RM.second, BM.first, BM.second, 1);
    
    //OUTPUT
    if(ans != 100) cout << ans;
    else cout << -1;
    
}
//구현력을 테스트하는 문제같다
//빨간 구슬 파란 구슬에 대한 visited 배열을 만들어서 왔다리 갔다리 하는 의미없는 이동을 방지할 수 있다.
//나는 그냥 굴러봤자 10번인데 라는 생각으로 안했다.