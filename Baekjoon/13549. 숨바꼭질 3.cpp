//https://www.acmicpc.net/problem/13549
//13549.숨바꼭질 3 (Gold5, 그래프 탐색, BFS, 다익스트라)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

#define endl "\n"
#define INF 999999999
using namespace std;

int N, K;
int ans = 0;
bool visited[100001];

int solve(int start, int dest) {
    //RESET
    for(int i = 0; i <= 100000; i++) visited[i] = false;

    //CAL
    priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
    pq.push(make_pair(0, start));
    visited[start] = true;

    while(pq.empty() == 0) {
        int curT = pq.top().first;
        int curL = pq.top().second;
        pq.pop();

        if(curL == dest) return curT;

        //시간이 0초 소모되는 순간이동을 우선적으로
        if(curL * 2 <= 100000 && visited[curL * 2] == false) {
            pq.push(make_pair(curT, curL * 2));
            visited[curL * 2] = true;
        } 
        if(curL + 1 <= 100000 && visited[curL + 1] == false) {
            pq.push(make_pair(curT + 1, curL + 1));
            visited[curL + 1] = true;
        }
        if(curL - 1 >= 0 && visited[curL - 1] == false) {
            pq.push(make_pair(curT + 1, curL - 1));
            visited[curL - 1] = true;
        }
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> K;

    //SOLVE
    ans = solve(N, K);

    //OUTPUT
    cout << ans << endl;

    return 0;
}

//가중치가 다 다르기 때문에 우선순위큐를 이용한 BFS로 해결.
//내림차순 우선순위큐를 구현하기 귀찮아 -를 붙였다가 pair 두번째 원소 정렬을 생각하지 못해 헤맸다.