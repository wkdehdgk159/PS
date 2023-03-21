//https://www.acmicpc.net/problem/9370
//9370. 미확인 도착지(Gold 2, 다익스트라)

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

int T, n, m, t, s, g, h;
int Dist_S[2001];//S로부터의 최단거리
int Dist_G[2001];
int Dist_H[2001];
int Dist_GH = 0;
vector<pair<int, int>> Vertex[2001]; //(v, w) 형태
vector<int> res;

void Dijkstra(int start, int arr[]) {
    //Dist 초기화
    for(int i = 0; i <= n; i++) arr[i] = INT_INF;
    //시작지점 Dist
    arr[start] = 0;
    
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

            //등호 붙인 이유는 g나 h가 연관되어 있다면 그 경로 방향으로 갱신되도록
            if(arr[v] > cd + w) {
                arr[v] = cd + w;
                pq.push({arr[v], v});
            }
        }
    }
}

bool check(int target) {
    if(Dist_S[target] == Dist_S[g] + Dist_GH + Dist_H[target]) return true;
    if(Dist_S[target] == Dist_S[h] + Dist_GH + Dist_G[target]) return true;

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> T;

    //SOLVE
    for(int i = 1; i <= T; i++) {
        for(int j = 0; j <= 2000; j++) {
            Vertex[j].clear();
        }
        res.clear();
        cin >> n >> m >> t;
        cin >> s >> g >> h;

        int a, b, d;
        for(int j = 0; j < m; j++) {
            cin >> a >> b >> d;
            Vertex[a].push_back({b, d});
            Vertex[b].push_back({a, d});
            if((a == g && b == h) || (a == h && b == g)) Dist_GH = d;
        }
        int t_dest;
        for(int j = 0; j < t; j++) {
            cin >> t_dest;
            Dijkstra(s, Dist_S);
            Dijkstra(g, Dist_G);
            Dijkstra(h, Dist_H);
            if(check(t_dest)) res.push_back(t_dest);
        }
        sort(res.begin(), res.end());
        for(int j = 0; j < res.size(); j++) {
            cout << res[j] << " ";
        }
        cout << endl;
    }
    //OUTPUT
}
//다익스트라로 s->g->h->t 나 s->h->g->t 가 s->t의 최단거리인 경우를 구한다.