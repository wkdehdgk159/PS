//https://www.acmicpc.net/problem/2842
//2842. 집배원 한상덕(Platinum 5, BFS)

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

int N, ans;
char board[50][50];
bool visited[50][50];
int height[50][50];
int house_num = 0;
vector<int> height_r; //높이들을 중복을 제거해 오름차순으로 저장
pair<int, int> post;
int dx[8] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[8] = {1, 0, -1, 1, -1, 1, 0, -1};

int bfs(int l, int r) {
    int lh = height_r[l], rh = height_r[r];
    //우체국의 고도가 범위에 포함되어있지 않으면 X
    if(height[post.first][post.second] < lh || height[post.first][post.second] > rh) {
        return -1;
    }
    queue<pair<int, int> > q;
    q.push(make_pair(post.first, post.second));
    int cnt = 0;
    
    memset(visited, 0, sizeof(visited));
    visited[post.first][post.second] = 1;

    while(!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];
            if(nx < 0 || ny < 0 || nx > N || ny > N || visited[nx][ny]) continue;
            if(height[nx][ny] < lh || height[nx][ny] > rh) continue;
            q.push(make_pair(nx, ny));
            visited[nx][ny] = 1;
            if(board[nx][ny] == 'K') cnt++;
        }
        if(cnt == house_num) return rh - lh;
    }
    return -1;
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
            if(board[i][j] == 'P') {
                post.first = i; post.second = j;
            } 
            else if(board[i][j] == 'K') house_num++;
        }
    }
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> height[i][j];
            height_r.push_back(height[i][j]);
        }
    }

    // SOLVE
    //높이 벡터 정렬 후 뒤의 중복 제거
    //https://dpdpwl.tistory.com/39
    sort(height_r.begin(), height_r.end());
    height_r.erase(unique(height_r.begin(), height_r.end()), height_r.end());

    int l = 0, r = 0;
    ans = INT_INF;
    while(l <= r && r < height_r.size()){
        int tmp = bfs(l, r);
        // cout << l <<" " <<  r <<" " <<  tmp << endl;
        if(tmp == -1) r++;
        else {
            if(ans > tmp) ans = tmp;
            l++;
        }
    }

    //OUTPUT
    cout << ans;
}
//BFS를 이용하여 경로를 찾고 투포인터로 모든 범위를 탐색하는 아이디어를 떠올리는 게 어려운 문제였다.