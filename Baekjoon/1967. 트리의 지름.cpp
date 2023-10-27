//https://www.acmicpc.net/problem/1967
//1967. 트리의 지름(Gold 4, DFS)

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

int n = 0, ans = 0, result = 0, endpoint = 2;
bool visited[10001];
vector<pair<int, int> > node[10001]; //<v1, <v2, w> > 구조

void dfs(int v, int cur_dist) {
    //현재 
    if(visited[v]) return;

    if(result < cur_dist) {
        result = cur_dist;
        endpoint = v;
    }
    visited[v] = true;

    for(int i = 0; i < node[v].size(); i++) {
        dfs(node[v][i].first, cur_dist + node[v][i].second);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> n;
    int a, b, c;
    for(int i = 0; i < n - 1; i++) {
        cin >> a >> b >> c;
        node[a].push_back(make_pair(b, c));
        node[b].push_back(make_pair(a, c));
    }
    memset(visited, 0, sizeof(visited));

    //SOLVE

    dfs(1, 0);
    memset(visited, 0, sizeof(visited));
    dfs(endpoint, 0);

    //OUTPUT
    cout << result;
}