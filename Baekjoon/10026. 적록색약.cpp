//https://www.acmicpc.net/problem/10026
//10026. 적록색약(Gold 5, BFS)

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

int N;
char map[100][100];
bool visited[100][100];
int ans_normal = 0, ans_jeokrok = 0;
int cnt = 0;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};

pair<int, int> find_start() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(!visited[i][j]) return make_pair(i, j);
        }
    }
    return make_pair(-1,-1);
}

void bfs(int x, int y) {
    char color = map[x][y];
    queue<pair<int, int> > q;
    q.push(make_pair(x,y));
    visited[x][y] = true;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;

        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N || visited[nx][ny] == true || map[nx][ny] != color) continue;
            visited[nx][ny] = true;
            q.push(make_pair(nx,ny));
        }
    }
    //다 돌고 나면 한 구역이 생긴 것이므로 +1
    cnt++;
    //새로운 시작점 찾기
    pair<int, int> new_start = find_start();
    //모든 점을 들렸다면 종료 아니라면 다시 bfs 시작
    if(new_start.first == -1) return;
    else {
        bfs(new_start.first, new_start.second);
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
        for(int j = 0; j < N; j++) cin >> map[i][j];
    }

    //SOLVE
    //일반인 파트
    bfs(0, 0);
    ans_normal = cnt;

    //초기화
    memset(visited, false, sizeof(visited));
    cnt = 0;

    //적록색약 파트
    //모든 G를 R로 바꿔준다.
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(map[i][j] == 'G') map[i][j] = 'R';
        }
    }
    bfs(0,0);
    ans_jeokrok = cnt;


    //OUTPUT
    cout << ans_normal << " " << ans_jeokrok << endl;
}