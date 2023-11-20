//배달 (Level 2, 최단거리, 다익스트라)
//https://school.programmers.co.kr/learn/courses/30/lessons/12978
#include <iostream>
#include <vector>
#include <queue>
#include <climits>
using namespace std;

int dist[51];
int N = 5;
vector<vector<int> > road = {{1,2,1},{2,3,3},{5,2,2},{1,4,2},{5,3,1},{5,4,2}};
int K = 3;

vector<pair<int, int> > edge[51];

void dijkstra(int start) {
    //여기 넣을 땐 첫번째 인자 기준으로 정렬되니 {dist, vertex} 형태로 Push
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    dist[start] = 0;

    pq.push({0, start});
    while(!pq.empty()) {
        int cost = pq.top().first;
        int curv = pq.top().second;
        pq.pop();

        for(int i = 0; i < edge[curv].size(); i++) {
            int nv = edge[curv][i].first;
            int ncost = edge[curv][i].second;

            if(dist[nv] > cost + ncost) {
                dist[nv] = cost + ncost;
                pq.push({dist[nv], nv});
            }
        }
    }
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;

    //INPUT
    //간선 정보 넣기
    for(int i = 0; i < road.size(); i++) {
        int v1 = road[i][0];
        int v2 = road[i][1];
        int d = road[i][2];
        edge[v1].push_back({v2, d});
        edge[v2].push_back({v1, d});
    }
    //dist 무한으로 초기화
    for(int i = 0; i <= N; i++) {
        dist[i] = INT_MAX;
    }

    //SOLVE
    dijkstra(1);

    for(int i = 1; i <= N; i++ ) {
        if(dist[i] <= K) answer++;
    }

    return answer;
}
/*
다익스트라로 최단거리들 구해준다.
*/