//https://school.programmers.co.kr/learn/courses/30/lessons/72413
//합승 택시 요금 (Level 3, 다익스트라, 플로이드워셜)

#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;
#define INF 99999999

//fee지만 편하게 dist로
int Dist[201]; //다익스트라를 위한 배열
int min_Dist[201][201];//최소 거리를 저장할 배열
int is_Vertices[201];//어떤 점이 실존하는지
vector<int> Vertices;
vector<pair<int, int>> V[201];//vertex, weight

void Dijkstra(int start) {
    for(int i = 1; i <= 200; i++) {
        Dist[i] = INF;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;//dist, vertex
    Dist[start] = 0;
    pq.push(make_pair(0, start));
    while(pq.empty() == 0) {
        int dist = pq.top().first;
        int curr = pq.top().second;
        pq.pop();
        
        if(dist > Dist[curr]) continue;
        for(int i = 0; i < V[curr].size(); i++) {
            int v = V[curr][i].first;
            int w = V[curr][i].second;
            if(Dist[v] > dist + w) {
                Dist[v] = dist + w;
                pq.push(make_pair(Dist[v], v));
            }
        }
    }
    for(int i = 0; i < Vertices.size(); i++) {
        min_Dist[start][Vertices[i]] = Dist[Vertices[i]];
        min_Dist[Vertices[i]][start] = Dist[Vertices[i]];
    }
    return;
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = INF;
    memset(is_Vertices, 0, sizeof(is_Vertices));
    //make graph
    for(int i = 0; i < fares.size(); i++) {
        V[fares[i][0]].push_back(make_pair(fares[i][1], fares[i][2]));
        V[fares[i][1]].push_back(make_pair(fares[i][0], fares[i][2]));
        is_Vertices[fares[i][0]] = 1;
        is_Vertices[fares[i][1]] = 1;
    }
    for(int i = 0; i < 201; i++) {
        if(is_Vertices[i]) {
            Vertices.push_back(i);
        }
    }
    
    //출발지, a, b에서 모든 점까지의 최소 거리 구하기
    Dijkstra(s);
    Dijkstra(a);
    Dijkstra(b);
    
    //합승 출발해서 어느 점 도착 후 그 점에서 갈라질 경우의 최소비용 그렇지만 애초에 갈라지는 경우도 포함 중
    for(int i = 0; i < Vertices.size(); i++) {
        answer = min(min_Dist[s][Vertices[i]] + min_Dist[Vertices[i]][a] + min_Dist[Vertices[i]][b], answer);
    }
    
    
    return answer;
}
//최단거리 유일하게 아는 다익스트라로 푼 문제. 플로이드 워셜 풀이도 찾아보았다.
//주의할 점은 원래 익숙한 int Dijkstra(start, end) 형식으로 s,a,b와 모든 정점간의 최소 거리를 구해 효율성 하나가 틀렸었는데 void 형식으로 한 함수에 s,a,b에 대한 모든 거리를 구해주니 시간이 확 줄었다는 것