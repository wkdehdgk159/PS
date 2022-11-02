//https://www.acmicpc.net/problem/3197
//3197. 백조의 호수(Platinum 5, BFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int R, C;
char board[1600][1600];
bool visited[1600][1600];
int ans = 0;
vector<pair<int, int> > swan;
queue<pair<int, int> > sq, wq, nsq;
bool find_flag = 0;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> R >> C;
    string tmps;
    for(int i = 0; i < R; i++) {
        cin >> tmps;
        for(int j = 0; j < C; j++) {
            board[i][j] = tmps[j];
            if(board[i][j] != 'X') {
                wq.push(make_pair(i ,j));
            }
            if(board[i][j] == 'L') {
                swan.push_back(make_pair(i, j));
            }
        }
    }
    
    //SOLVE
    sq.push(make_pair(swan[0].first, swan[0].second));
    visited[swan[0].first][swan[0].second] = 1;
    while(1) {
        if(ans != 0) sq = nsq;
        nsq = queue<pair<int, int> >();
        while(!sq.empty()) {
            int x = sq.front().first;
            int y = sq.front().second;
            sq.pop();
            
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= R || ny < 0 || ny >= C || visited[nx][ny]) continue;
                if(board[nx][ny] == 'L') {
                    find_flag = 1;
                    break;
                }
                visited[nx][ny] = 1;
                //백조가 갈 수있는 물을 돌면서 만난 X는 다음 타임에 백조가 새로 검사해야 할 물이 될 것이다.
                if(board[nx][ny] == 'X') {
                    nsq.push(make_pair(nx, ny));
                }
                //지금 물이면 큐에 넣기 
                else {
                    sq.push(make_pair(nx, ny));
                }
            }
            if(find_flag) break;
        }
        if(find_flag) {
            cout << ans;
            return 0;
        }
        else ans++;

        int cnt = wq.size();
        //물을 돌면서 얼음 녹여주기 큐가 빌 때까지가 아닌 현재 시점에서의 물들만
        while(cnt > 0) {
            int x = wq.front().first;
            int y = wq.front().second;
            wq.pop();
            for(int i = 0; i < 4; i++) {
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || nx >= R || ny < 0 || ny >= C) continue;
                //얼음을 만나면 녹여주고 다음에 검사해야 하니 물 큐에 저장
                if(board[nx][ny] == 'X') {
                    board[nx][ny] = '.';
                    wq.push(make_pair(nx, ny));
                }
            }
            cnt--;
        }
    }
    
    //OUTPUT
    
}
//구현은 정말 베이직한 BFS만 작성하면 되었지만 아이디어가 배울 것이 많은 문제였다.
//BFS로 O(R^2C^2) 걸릴 문제를 살짝 틀어주어 O(RC)로 만든 아이디어가 대단했던 문제 