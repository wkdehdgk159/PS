//https://www.acmicpc.net/problem/16236
//16236. 아기 상어(Gold 3, BFS)

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

int N, ans = 0, s_size = 2;
int board[20][20];
bool visited[20][20];
pair<int, int> fish[400];
pair<int, int> start;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int find_shortest(int s_x, int s_y, int d_x, int d_y) {
    if(s_x == d_x && s_y == d_y) return 0;

    memset(visited, 0, sizeof(visited));
    queue<pair<pair<int, int>, int> > q;
    visited[s_x][s_y] = 1;
    q.push(make_pair(make_pair(s_x, s_y), 0));

    while(!q.empty()) {
        int x = q.front().first.first;
        int y = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || nx >= N || ny < 0 || ny >= N || visited[nx][ny] || board[nx][ny] > s_size) continue;
            if(nx == d_x && ny == d_y) return dist+1;
            visited[nx][ny] = 1;
            q.push(make_pair(make_pair(nx, ny), dist+1));
        }
    }
    return 800;
}

void solve() {
    int cx = start.first;
    int cy = start.second;
    int needed = s_size;
    board[cx][cy] = 0;

    while(1) {
        int dist = N * N;
        pair<int, int> dest = make_pair(-1, -1);
        //먹을 수 있는 가장 가까운 생선찾기
        //(0,0)부터 훑기 때문에 무승부 시 가장 위의 가장 왼쪽의 물고기를 자동으로 골라줌
        for(int i = 0; i < N; i++) {
            for(int j= 0; j < N; j++) {
                if(board[i][j] == 0 || board[i][j] >= s_size) continue;
                int tmp_d = find_shortest(cx, cy, i, j);
                if(tmp_d < dist) {
                    dist = tmp_d;
                    dest.first = i, dest.second = j;
                }
            }
        }
        // cout << dist;
        if(dist == N * N) break;
        cx = dest.first, cy = dest.second;
        //잡아먹었으므로 이곳은 빈칸
        board[cx][cy] = 0;
        //성장까지 필요한 양 -1
        needed--;
        ans += dist;
        //다 먹었으면 크기 키워주고 필요한 양 갱신
        if(needed == 0) {
            s_size++;
            needed = s_size;
        }
    }
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
            if(board[i][j] == 9) {
                start.first = i;
                start.second = j;
            }
        }
    }

    // SOLVE
    solve();

    //OUTPUT
    cout << ans;

}