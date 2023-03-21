//https://www.acmicpc.net/problem/2211
//2211. 네트워크 복구(Gold 2, 다익스트라)

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

int N, M;
int Dist[1001];
int from[1001];//최소 경로 갱신 시 어디에서 왔는지 확인
vector<pair<int, int>> Vertex[1001]; //(v, w) 형태

void Dijkstra(int start) {
    //from 초기화
    for(int i = 0; i <= N; i++) from[i] = -1;
    //Dist 초기화
    for(int i = 0; i <= N; i++) Dist[i] = INT_INF;
    //시작지점 from, Dist
    from[start] = 0, Dist[start] = 0;
    
    //PQ 최소힙으로 선언
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, start});

    //다익스트라 진행
    while(!pq.empty()) {
        int cd = pq.top().first;
        int cv = pq.top().second;
        pq.pop();

        for(int i = 0; i < Vertex[cv].size(); i++) {
            int v = Vertex[cv][i].first;
            int w = Vertex[cv][i].second;

            //등호 붙인 이유는 같은 경우의 우선순위도 반영해줘야하기 때문에
            if(Dist[v] > cd + w) {
                Dist[v] = cd + w;
                pq.push({Dist[v], v});
                from[v] = cv;
            }
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
    int A, B, C;
    for(int i = 0; i < M; i++) {
        cin >> A >> B >> C;
        Vertex[A].push_back({B, C});
        Vertex[B].push_back({A, C});
    }

    //SOLVE
    Dijkstra(1);
    
    //OUTPUT
    cout << N - 1 << endl;
    for(int i = 2; i <= N; i++) {
        cout << from[i] << " " << i << endl;
    }
}