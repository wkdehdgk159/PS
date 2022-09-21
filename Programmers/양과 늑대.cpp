//https://school.programmers.co.kr/learn/courses/30/lessons/92343
//양과 늑대 (Level 3, 완전탐색 DFS)

#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> info_c;
vector<vector<int>> tree(17);
int answer = 1;

void dfs(int curr, int sheep, int wolves, vector<int> nextNodes) {
    
    if(info_c[curr] == 0) {
        sheep++;
    } else {
        wolves++;
    }
    if(wolves >= sheep) return;
    
    if(sheep > answer) answer = sheep;
    
    //내가 노드를 방문한 후에 방문 가능한 모든 후보군을 넣어준다.
    for(int i = 0; i < nextNodes.size(); i++) {
        vector<int> tmp = nextNodes;
        tmp.erase(tmp.begin() + i);
        for(int j = 0; j < tree[nextNodes[i]].size(); j++) {
            tmp.push_back(tree[nextNodes[i]][j]);
        }
        dfs(nextNodes[i], sheep, wolves, tmp);
    }
    return;
}

int solution(vector<int> info, vector<vector<int>> edges) {
    for(int i = 0; i < edges.size(); i++) {
        tree[edges[i][0]].push_back(edges[i][1]);
    }
    info_c = info;
    
    dfs(0, 0, 0, tree[0]);
    
    return answer;
}