//https://www.acmicpc.net/problem/16234
//16234. 인구 이동(Gold 5, 그래프 탐색, BFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib> //abs

#define endl "\n"
using namespace std;

int N, L, R, ans = 0, p_sum = 0, move_flag;
vector<pair<int, int> > tmp; //인구가 갱신될 좌표를 담는 임시 벡터
bool visited[50][50];
int board[50][50];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

//인구가 갱신될 좌표를 담기만 함
void search(int x, int y) {
    visited[x][y] = true;
    p_sum += board[x][y];
    tmp.push_back(make_pair(x, y));

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
    
        if(0 <= nx && nx < N && 0 <= ny && ny < N) {
            int diff = abs(board[x][y] - board[nx][ny]);
            if(!visited[nx][ny] && L <= diff && diff <= R) {
                search(nx, ny);
            }
        }
    }
}

void move() {
    if(tmp.size() < 2) {
        tmp.clear();
        p_sum = 0;
        return;
    }
    move_flag = 1;
    //search 함수에서 구해줬던 인구의 총합을 나눠준다.
    int p = int(p_sum/tmp.size());
    for(int i = 0; i < tmp.size(); i++) {
        board[tmp[i].first][tmp[i].second] = p;
    }
    //RESET
    tmp.clear();
    p_sum = 0;
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

    cin >> N >> L >> R;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    //SOLVE
    move_flag = 1;
    while(move_flag) {
        move_flag = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if(!visited[i][j]) {
                    search(i, j);
                    move();
                }
            }
        }
        tmp.clear();
        memset(visited, false, sizeof(visited));
        if(move_flag) ans++;
    }

    //OUTPUT
    cout << ans;

    return 0;
}
//문제 분류는 BFS지만 DFS가 더 빠르다고 한다. 큐에 넣고 빼고 하는 과정 때문이다. 