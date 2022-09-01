//https://www.acmicpc.net/problem/1238  
//1238.파티 (Gold3, 그래프 이론, 다익스트라)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define endl "\n"
#define INF 999999999
using namespace std;

int N, M, X;
int ans = 0;
int Dist[1001];
vector<pair<int, int>> Vertex[1001]; //<vertex, weight>

int Dijkstra(int start, int end) {
    //RESET
    for(int i = 1; i <= N; i++) {
        Dist[i] = INF;
    }
    //CAL
    priority_queue<pair<int, int>> pq; //<dist, vertex>
    Dist[start] = 0;
    pq.push(make_pair(0, start));
    
    while(pq.empty() == 0) {
        int dist = -pq.top().first;
        int curr = pq.top().second; //내림차순 유지
        pq.pop();

        if(dist > Dist[curr]) continue;
        for(int i = 0; i < Vertex[curr].size(); i++) {
            int v = Vertex[curr][i].first;
            int w = Vertex[curr][i].second;

            if(Dist[v] > dist + w) {
                Dist[v] = dist + w;
                pq.push(make_pair(-Dist[v], v));
            }
        }
    }
    return Dist[end];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M >> X;
    for(int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        Vertex[u].push_back(make_pair(v, w));
    }

    //SOLVE
    for(int i = 1; i <= N; i++) {
        if(Dijkstra(i, X) + Dijkstra(X, i) > ans) {
            ans = Dijkstra(i, X) + Dijkstra(X, i);
        }
    }

    //OUTPUT
    cout << ans << endl;

    return 0;
}

//다익스트라 알고리즘을 이용해 모든 경우의 수 중 최대값 도출