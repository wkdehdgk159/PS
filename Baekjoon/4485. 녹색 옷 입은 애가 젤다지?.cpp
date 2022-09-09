//https://www.acmicpc.net/problem/4485
//4485. 녹색 옷 입은 애가 젤다지? (Gold4, 그래프 이론, 다익스트라)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define endl "\n"
#define INF 999999999
using namespace std;

int N;
int ans = 0;
int weight[125][125];
int dist[125][125];
bool visited[125][125];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void solve() {
    //RESET
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            visited[i][j] = false;
            dist[i][j] = INF;
        }
    }

    //CAL
    //pair(int, pair(int, int)) 구조라 애좀 먹음 복습하자
    priority_queue<pair<int, pair<int, int> >, vector<pair<int, pair<int, int> > >, greater<pair<int, pair<int, int> > > > pq;
    pq.push(make_pair(weight[0][0], make_pair(0, 0))); //첫 거리가 0이 아님을 주의
    visited[0][0] = true;

    while(pq.empty() == 0) {
        int cost = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();

        if(x == N - 1 && y == N - 1) return;

        for(int i = 0; i < 4; i++) {
            int tmpX = x + dx[i];
            int tmpY = y + dy[i];
            int tmpCost = cost + weight[tmpX][tmpY];

            if(0 <= tmpX && 0 <= tmpY && tmpX < N && tmpY < N) {
                if(visited[tmpX][tmpY] == false && dist[tmpX][tmpY] > tmpCost) {
                    dist[tmpX][tmpY] = tmpCost;
                    visited[tmpX][tmpY] = true;
                    pq.push(make_pair(tmpCost, make_pair(tmpX, tmpY)));
                }
            }
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
    int num = 0;

    while(1) {
        //INPUT
        cin >> N;
        if(N == 0) return 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> weight[i][j];
            }
        }

        //SOLVE
        solve();

        num++;
        //OUTPUT
        cout << "Problem " << num << ": " << dist[N - 1][N - 1] << endl;
    }


    return 0;
}