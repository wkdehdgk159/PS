//https://www.acmicpc.net/problem/1976
//1976. 여행 가자(Gold 4, Union-find)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;

vector<int> plan;
int N, M;
int Root[201];
int Rank[201];

int find(int x) {
    if(Root[x] == x) return x;
    else {
        //찾는 과정에서 거친 모든 노드의 root를 갱신해주면서 경로 압축의 효과
        return Root[x] = find(Root[x]);
    }
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);
    
    if(x == y) return;
    
    //O(N-1) 최악의 경우를 막기 위해 rank(높이) 개념 도입
    if(Rank[x] < Rank[y]) {
        Root[x] = y;
    } 
    else {
        Root[y] = x;

        if(Rank[x] == Rank[y]) Rank[x]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
    memset(Root, 0, sizeof(Root));
    memset(Rank, 0, sizeof(Rank));

    //INPUT
    cin >> N >> M;

    //SOLVE
    for(int i = 1; i <= N; i++) {
        Root[i] = i;
    }

    int tmp;
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cin >> tmp;
            if(tmp == 1) {
                Union(i, j);
            }
        }
    }

    for(int i = 0; i < M; i++) {
        cin >> tmp;
        plan.push_back(tmp);
    }

    for(int i = 0; i < M - 1; i++) {
        if(find(plan[i]) != find(plan[i + 1])) {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";

    //OUTPUT
}
//Disjoint set 문제에서 가장 많이 활용되는 union-find 알고리즘
//이번에 경로 compression과 union-by-rank 최적화도 블로그를 통해 공부했다.