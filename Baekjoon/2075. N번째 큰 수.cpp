//https://www.acmicpc.net/problem/2075
//2075. N번째 큰 수(Silver 2, 우선순위 큐)

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
    freopen("input.txt", "r", stdin);

    int N, tmp;
    priority_queue<int, vector<int>, greater<int> > pq;

    //INPUT
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0;  j < N; j++) {
            cin >> tmp;
            pq.push(tmp);
        }
        while(pq.size() > N) pq.pop();
    }

    //SOLVE
    //OUTPUT
    cout << pq.top();
}