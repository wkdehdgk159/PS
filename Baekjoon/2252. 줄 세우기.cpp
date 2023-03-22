//https://www.acmicpc.net/problem/2252
//2252. 줄 세우기(Gold 3, 위상정렬)

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
int indegree[32001];
bool visited[32001];
vector<int> Vertex[32001];
vector<int> res;

void Topological_Sort() {
    queue<int> q;
    for(int i = 1; i <= N; i++) {
        if(indegree[i] == 0) {
            q.push(i);
            visited[i] = true;
            res.push_back(i);
        }
    }

    while(!q.empty()) {
        int cv = q.front();
        q.pop();
        for(int i = 0; i < Vertex[cv].size(); i++) {
            int v = Vertex[cv][i];
            if(!visited[v]) indegree[v]--;
            if(indegree[v] == 0) {
                q.push(v);
                visited[v] = true;
                res.push_back(v);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> M;

    //SOLVE
    memset(indegree, 0, sizeof(indegree));
    memset(visited, 0, sizeof(visited));
    int A, B;
    for(int i = 0; i < M; i++) {
        cin >> A >> B;
        indegree[B]++;
        Vertex[A].push_back(B);
    }
    //여기서 아예 언급 안된 친구들은 indegree 0으로 간주되어 바로 큐에 들어간다
    //어차피 다 앞쪽으로 빠지고 우리가 고려해야하는 선후관계는 다 지켜질테니 무방하다.
    Topological_Sort();
    
    //OUTPUT
    for(int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}
//위상 정렬을 처음 배워봤다. 
//https://yoongrammer.tistory.com/86