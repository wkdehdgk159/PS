//https://www.acmicpc.net/problem/2164
//2164. 카드2(Silver 4, 큐)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INF 999999999
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int N, tmp;
    queue<int> q;

    //INPUT
    cin >> N;
    for(int i = 1; i <= N; i++) {
        q.push(i);
    }

    //SOLVE
    while(q.size() > 1) {
        q.pop();
        if(q.size() > 1) {
            tmp = q.front();
            q.pop();
            q.push(tmp);
        }
    }
    //OUTPUT
    cout << q.front();
}