//https://www.acmicpc.net/problem/19238
//19238. 스타트 택시(Gold 2, BFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long

using namespace std;

int N, M, sfuel, ans;
int board[21][21];
bool visited[21][21];
pair<int, int> start;
pair<int, int> g_s[401];
pair<int, int> g_d[401];
bool visited_g[401];
//거리가 같을 시 행 작고, 열 작은 순으로 손님을 고르므로 행을 낮추는 쪽 -> 열을 낮추는 쪽 -> 열을 높이는 쪽 -> 행을 높이는 쪽으로 탐색을 해야 하는
//줄 알았으나 아니었다. 왼왼왼, 오오위 같이 반례가 존재
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0};

int shortest_dist(int s_x, int s_y, int d_x, int d_y) {
    if(s_x == d_x && s_y == d_y) return 0;

    memset(visited, 0, sizeof(visited));
    queue<pair<pair<int, int>, int> > q;
    visited[s_x][s_y] = 1;
    q.push(make_pair(make_pair(s_x, s_y), 0));

    while(!q.empty()) {
        int cx = q.front().first.first;
        int cy = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 1 || nx > N || ny < 1 || ny > N || board[nx][ny] == 1 || visited[nx][ny]) continue;
            if(nx == d_x && ny == d_y) return dist + 1;
            visited[nx][ny] = 1;
            q.push(make_pair(make_pair(nx, ny), dist + 1));
        }
    }
    return -1;
}

int drive(int x, int y) {
    int cx = x;
    int cy = y;
    int target = M;

    while(target > 0) {

        int g_idx, dist1 = N * N;
        //몇번째 손님인지 찾기
        for(int i = 1; i <= M; i++) {
            if(visited_g[i]) continue;
            int tmp_d = shortest_dist(cx, cy, g_s[i].first, g_s[i].second);
            if(tmp_d < dist1) {
                g_idx = i;
                dist1 = tmp_d;
            }
            else if(tmp_d == dist1) {
                //현재 손님의 행이 더 작다면
                if(g_s[g_idx].first > g_s[i].first) g_idx = i;
                else if(g_s[g_idx].first == g_s[i].first && g_s[g_idx].second > g_s[i].second) g_idx = i;
            }
        }
        visited_g[g_idx] = 1;

        //손님을 데리러 갈 연료가 없다면 종료
        if(dist1 > sfuel || dist1 == -1) return -1;

        //손님 태우기까지의 연료 소비
        sfuel -= dist1;
        int dist2 = shortest_dist(g_s[g_idx].first, g_s[g_idx].second, g_d[g_idx].first, g_d[g_idx].second);
        //손님 태워다 줄 연료가 없다면 종료
        if(dist2 > sfuel || dist2 == -1) return -1;

        //손님 태워준 후 연료 충전
        sfuel += dist2;
        target--;
        //다시 손님 찾으러 갈 준비
        cx = g_d[g_idx].first;
        cy = g_d[g_idx].second;
    }
    return sfuel;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M >> sfuel;
    for(int i = 1; i <= N; i++) { 
        for(int j = 1; j <= N; j++) {
            cin >> board[i][j];
        }
    } 
    cin >> start.first >> start.second;
    for(int i = 1; i <= M; i++) {
        cin >> g_s[i].first >> g_s[i].second;
        cin >> g_d[i].first >> g_d[i].second;
    }

    // SOLVE
    ans = drive(start.first, start.second);

    //OUTPUT
    cout << ans;

}