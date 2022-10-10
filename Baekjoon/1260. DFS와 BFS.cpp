//https://www.acmicpc.net/problem/1260
//1260. DFS와 BFS(Silver 2, 그래프 탐색)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INF 999999999
using namespace std;

int N, M, V;
vector<int> vertex[1001];
bool visited[1001];

void dfs(int start) {
    visited[start] = 1;
    cout << start << " ";
    for(int i = 0; i < vertex[start].size(); i++) {
        int v = vertex[start][i];
        if(!visited[v]) {
            dfs(v);
        }
    }
}

void bfs(int start) {
    queue<int> q;
    visited[start] = 1;
    q.push(start);

    while(!q.empty()) {
        int v =  q.front();
        cout << v << " ";
        q.pop();

        for(int i = 0; i < vertex[v].size(); i++) {
            int curr = vertex[v][i];
            if(!visited[curr]) {
                visited[curr] = 1;
                q.push(curr);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    memset(vertex, 0, sizeof(vertex));


    //INPUT
    cin >> N >> M >> V;

    int v1, v2;
    for(int i = 0; i < M; i++) {
        cin >> v1 >> v2;
        vertex[v1].push_back(v2);
        vertex[v2].push_back(v1);
    }

    //SOLVE
    //작은 정점부터 방문하기 위해 정렬
    for(int i = 1; i <= N; i++) {
        sort(vertex[i].begin(), vertex[i].end());
    }

    memset(visited, 0, sizeof(visited));
    dfs(V);
    cout << endl;
    memset(visited, 0, sizeof(visited));
    bfs(V);

    //OUTPUT
}