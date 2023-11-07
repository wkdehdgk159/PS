//전력망을 둘로 나누기 (Level 2, 완전탐색, BFS)
//https://school.programmers.co.kr/learn/courses/30/lessons/86971

#include <string>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;
vector<int> v[101];
bool visited[101];

//v1과 연결된 송전탑의 총 수를 구한다. v2와의 간선은 제외한다.
int bfs_find_volume(int v1, int v2) {
    memset(visited, 0, sizeof(visited));
    int cnt = 0;
    queue<int> q;
    q.push(v1);
    visited[v1] = true;
    cnt++;

    while(!q.empty()) {
        int cv = q.front();
        q.pop();

        for(int i = 0; i < v[cv].size(); i++) {
            int nv = v[cv][i];
            //내가 제외할 점이거나 방문한 점이라면 skip
            if(nv == v2 || visited[nv] == true) continue;

            visited[nv] = true;
            cnt++;
            q.push(nv);
        }
    }
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    int ans = 1000000;
    for(int i = 0; i < n - 1; i++) {
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        v[v1].push_back(v2);
        v[v2].push_back(v1);
    }

    for(int i = 0; i < n - 1; i++) {
        int v1 = wires[i][0];
        int v2 = wires[i][1];
        int tmp = abs(bfs_find_volume(v1, v2) - bfs_find_volume(v2, v1));
        ans = (tmp < ans) ? tmp : ans;
    }
    return ans;
}