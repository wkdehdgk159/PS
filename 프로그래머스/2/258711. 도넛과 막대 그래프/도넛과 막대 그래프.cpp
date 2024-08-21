#include <string>
#include <vector>
#include <iostream>
#include <cstring>

using namespace std;

//생성 정점, 도넛 수, 막대 수, 8자 수
int av, dn, sn, en;
vector<int> graph[1000001];
bool visited[1000001];
int indegree[1000001] = {0};
int outdegree[1000001] = {0};

void dfs(int v) {
    //다시 본인으로 돌아오면 도넛
    if(visited[v]) {
        dn++;
        return;
    }
    //나가는 간선의 개수가 2 이상인 정점이 있다면 8자
    else if(outdegree[v] >= 2) {
        en++;
        return;
    }
    //끝이 보인다면 막대
    else if(outdegree[v] == 0) {
        sn++;
        return;
    }
    
    visited[v] = true;
    
    for(int i = 0; i < graph[v].size(); i++) {
        dfs(graph[v][i]);
    }
    
    return;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;

    int max_cnt = 0, v_cnt = 0;
    memset(visited, 0, sizeof(visited));
    
    for(int i = 0; i < edges.size(); i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        indegree[edges[i][1]]++;
        outdegree[edges[i][0]]++;
        
        //나가는 간선이 가장 많은 정점이 생성된 정점일 것
        if(outdegree[edges[i][0]] >= 2 && indegree[edges[i][0]] == 0) {
            av = edges[i][0];
        }
    }
    
    for(int i = 0; i < graph[av].size(); i++) {
        dfs(graph[av][i]);
    }
    
    answer = {av, dn, sn, en};
    
    return answer;
}

//일단 들어오는 것은 없이 나가는 방향만 2개 이상 있는 정점이 생성된 정점임
//생성된 정점 찾은 후에 정점과 인접한 정점에 대해 그래프 탐색을 한다.
//그래프를 쭉 탐색하다가 
//나가는 방향이 2개인 점을 만나면 8자
//다시 자기 자신으로 돌아오면 도넛
//탐색이 아예 끝나면 막대