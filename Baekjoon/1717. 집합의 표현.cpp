//https://www.acmicpc.net/problem/1717
//1717. 집합의 표현(Gold 4, Union-find)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;

int n, m;
int Root[1000001];
int Rank[1000001];

int find(int x) {
    if(x == Root[x]) return x;
    else {
        return Root[x] = find(Root[x]);
    }
}

void Union(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;

    if(Rank[x] < Rank[y]) {
        Root[x] = y;
    } 
    else {
        Root[y] = x;
        if(Rank[x] == Rank[y]) {
            Rank[x]++;
        }
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
    cin >> n >> m;

    //SOLVE
    for(int i = 0; i <= n; i++) {
        Root[i] = i;
        Rank[i] = 0;
    }

    int com, a, b;
    for(int i = 0; i < m; i++) {
        cin >> com >> a >> b;
        if(com == 0) {
            Union(a, b);
        }
        else {
            if(find(a) == find(b)) {
                cout << "YES" << endl;
            } else {
                cout << "NO" << endl;
            }
        }
    }
}