//https://www.acmicpc.net/problem/23817
//23817. 포항항(Gold 1, BFS, 브루트포스)

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

int N, M, ans = INT_INF;
int board[1000][1000]; //입력받을 때 int로 변환해서 받기
int m_dist[1000][1000];
int r_dist[21][21]; //식당과 식당간의 거리, 0번째는 시작점으로 가정
vector<pair<int, int> > restaurant; //식당 좌표들
int rc = 0; //식당 개수 시작점은 제외
bool visited[1000][1000];
bool rvisited[21]; //식당 방문여부
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

void bfs(int sr) {
    memset(visited, 0, sizeof(visited));
    queue<pair<int, int> > q;
    q.push(make_pair(restaurant[sr].first, restaurant[sr].second));
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            m_dist[i][j] = INT_INF;
        }
    }
    visited[restaurant[sr].first][restaurant[sr].second] = 1;
    m_dist[restaurant[sr].first][restaurant[sr].second] = 0;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= M) continue;
            if(visited[nx][ny] || board[nx][ny] == -1) continue;
            //최소 거리 갱신
            m_dist[nx][ny] = m_dist[cx][cy] + 1;
            visited[nx][ny] = 1;
            q.push(make_pair(nx, ny));
        }
    }

    //한 가게를 기준으로 구한 모든 칸에 대한 최소거리를
    //식당에 관해서만 다루는 배열에 적용하기
    for(int i = 0; i <= rc; i++) {
        if(m_dist[restaurant[i].first][restaurant[i].second] == INT_INF) r_dist[sr][i] = -1;
        else r_dist[sr][i] = m_dist[restaurant[i].first][restaurant[i].second];
    }
    return;
}

void dfs(int sr, int cnt, int dist) {
    if(cnt == 5) {
        ans = (ans > dist) ? dist : ans;
        return;
    }
    
    //백트래킹 해주면서 모든 경우의 수를 탐방
    for(int i = 1; i <= rc; i++) {
        if(!rvisited[i] && r_dist[sr][i] >= 1) {
            rvisited[i] = 1;
            dfs(i, cnt + 1, dist + r_dist[sr][i]);
            rvisited[i] = 0;
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
    cin >> N >> M;
    char c;
    restaurant.push_back(make_pair(0, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> c;
            if(c == 'X') board[i][j] = -1;
            else if(c == 'K') {
                board[i][j] = ++rc;
                restaurant.push_back(make_pair(i, j));
            }
            else if(c == 'S') {
                restaurant[0] = make_pair(i, j);
            }
        }
    }

    // SOLVE
    //한 식당을 기준으로 식당 간의 최소거리 구하기
    memset(m_dist, 0, sizeof(m_dist));
    for(int i = 0; i <= rc; i++) {
        bfs(i);
    }
    
    rvisited[0] = 1;
    dfs(0, 0, 0); //현재 가게, 들린 가게 수, 현재까지의 거리;

    //OUTPUT
    if(ans == INT_INF) ans = -1;
    cout << ans;
}