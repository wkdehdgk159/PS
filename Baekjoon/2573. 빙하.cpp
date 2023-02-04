//https://www.acmicpc.net/problem/2573
//2573. 빙산(Gold 4, DFS, BFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long

using namespace std;

int N, M, ans = 0;
queue<pair<int, int> > q1;//현재 빙하 좌표들
queue<pair<pair<int, int>, int > > q2;//임시 ((x, y), 줄어들 높이)
int gl[300][300]; //현재 빙하의 높이
int melt[300][300]; //다음 주기때 녹을 빙하의 높이
bool visited[300][300];
int gllen;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    visited[x][y] = true;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || nx > N || ny < 0 || ny > M) continue;
        if(!visited[nx][ny] && gl[nx][ny]) {
            gllen++;
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(melt, 0, sizeof(melt));
    cin >> N >> M;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> gl[i][j];
            if(gl[i][j]) q1.push(make_pair(i, j));
        }
    }

    // SOLVE
    pair<int, int> tmp;
    while(1) {
        ans++;
        while(!q1.empty()) {
            tmp = q1.front();
            //깎일 높이
            int mh = 0;
            for(int i = 0; i < 4; i++) {
                int nx = tmp.first + dx[i];
                int ny = tmp.second + dy[i];
                if(nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
                if(gl[nx][ny] == 0) mh++;
            }
            q2.push(make_pair(tmp, mh));
            q1.pop();
        }
        while(!q2.empty()) {
            tmp = q2.front().first;
            int x, y;
            x = tmp.first, y = tmp.second;
            gl[x][y] -= q2.front().second;
            //다 녹아 없어진 게 아니라면 넣기
            if(gl[x][y] > 0) q1.push(tmp);
            else gl[x][y] = 0;
            q2.pop();
        }
        //모두 녹아 없어졌다면 0 출력 후 종료
        if(q1.size() == 0) {
            cout << 0; return 0;
        }

        memset(visited, 0, sizeof(visited));
        int cnt = 0;
        int x = q1.front().first;
        int y = q1.front().second;
        //dfs해서 센 이어진 빙하의 수와 q1의 사이즈가 다르다면 분열된 것이므로 답 출력 후 종료
        gllen = 1;
        dfs(x, y);
        if(q1.size() != gllen) {
            cout << ans; return 0;
        }
    }

    //OUTPUT
    cout << ans;
}
//BFS 흉내를 내보려고 큐를 두개 썼지만 그냥 빙하 배열을 하나 더 만들어서 임시로 저장해두는 게 나을 것 같다.