//https://www.acmicpc.net/problem/5972
//5972. 택배 배송(Gold 5, 다익스트라)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INF 999999999
using namespace std;

int N, M;
int Dist[50001];
vector<pair<int, int> > road[50001];//<vertex, cow>

int dijkstra(int start, int dest) {
    //RESET
    for(int i = 1; i <= N; i++) {
        Dist[i] = INF;
    }
    Dist[start] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;//<cow, vertex>
    pq.push(make_pair(0, start));
    
    while(!pq.empty()) {
        int cow = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        if(cow > Dist[curr]) continue;

        for(int i = 0; i < road[curr].size(); i++) {
            int v = road[curr][i].first;
            int c = road[curr][i].second;

            if(c + cow < Dist[v]) {
                Dist[v] = c + cow;
                pq.push(make_pair(Dist[v], v));
            }
        }
    }
    return Dist[dest];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M;
    for(int i = 0; i < M; i++) {
        int v1, v2, cow;
        cin >> v1 >> v2 >> cow;
        road[v1].push_back(make_pair(v2, cow));
        road[v2].push_back(make_pair(v1, cow));
    }

    //SOLVE
    //다익스트라
    int ans = dijkstra(1, N);

    //OUTPUT
    cout << ans;

    return 0;
}
//최단거리 기본 문제는 잘 할 수 있다!