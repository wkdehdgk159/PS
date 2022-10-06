//https://www.acmicpc.net/problem/1446
//1446. 지름길(Silver 1, 다익스트라)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;

int N, D;
int Dist[10001];
vector<pair<pair<int, int>, int> >info;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> D;

    //SOLVE
    //지름길이 없을 때는 거리가 걸리는 시간과 동일
    for(int i = 0; i <= D; i++) {
        Dist[i] = i;
    }

    for(int i = 0; i < N; i++) {
        int s, e, d;
        cin >> s >> e >> d;
        info.push_back(make_pair(make_pair(s, e), d));
    }
    sort(info.begin(), info.end());

    for(int i = 0; i < info.size(); i++) {
        int s, e, d;
        s = info[i].first.first;
        e = info[i].first.second;
        d = info[i].second;
        if(Dist[s] + d < Dist[e]) {
            Dist[e] = Dist[s] + d;
            int profit = e - s - d;
            for(int j = e; j <= D; j++) {
                Dist[j] = min(Dist[j], Dist[e] + j - e);
            }
        }
    }
    //OUTPUT
    cout << Dist[D];
}
//최단거리 = 다익스트라라는 고정관념으로 풀긴 했지만 다이나믹 프로그래밍 풀이가 훨씬 좋아보인다.
//i로 가는 지름길이 있을 때 Dist[i - 1] + 1 과 Dist[start] + cost중 최소값을 고름.