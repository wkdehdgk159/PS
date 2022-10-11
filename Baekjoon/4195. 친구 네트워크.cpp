//https://www.acmicpc.net/problem/4195
//4195. 친구 네트워크(Gold 2, Union-find)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map> //문자열 중복확인

#define endl "\n"
#define INF 999999999
using namespace std;


int F, TC;
int Root[200001];
int Rank[200001];
int Count[200001];
map<string, int> m;

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
        Count[y] += Count[x];
    } 
    else {
        Root[y] = x;
        Count[x] += Count[y];
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

    //INPUT
    cin >> TC;

    //SOLVE
    for(int i = 0; i < TC; i++) {
        for(int j = 0; j < 200001; j++) {
            Root[j] = j;
            Rank[j] = 0;
            Count[j] = 1;
        }
        cin >> F;
        m.clear();
        map<string, int>::iterator it;
        int idx = 0;//map의 second int 부분에 고유성을 부여할 변수
        string s1, s2;
        int a, b;
        for(int i = 0; i < F; i++) {
            cin >> s1 >> s2;
            it = m.find(s1);
            if(it == m.end()) {
                m[s1] = idx;
                a = idx;
                idx++;
            }
            else {
                a = it->second;
            }
            it = m.find(s2);
            if(it == m.end()) {
                m[s2] = idx;
                b = idx;
                idx++;
            }
            else {
                b = it->second;
            }
            Union(a, b);
            cout << Count[find(a)] << endl;
        }
    }
    //OUTPUT
}
//Union하는 시점에서 루트에 붙을 트리노드의 개수를 더해주는 과정만 있으면 된다.