//https://www.acmicpc.net/problem/1202
//1202. 보석 도둑(Gold 2, 그리디, 우선순위큐)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long

using namespace std;

int N, K;
ll ans = 0;
pair<int, int> jewels[300000]; //<무게, 가격>
int cap[300000];
priority_queue<int> pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> K;
    int M, V;
    for(int i = 0; i < N; i++) {
        cin >> M >> V;
        jewels[i] = make_pair(M, V);
    }
    for(int i = 0; i < K; i++) cin >> cap[i];

    //SOLVE
    sort(jewels, jewels + N);
    sort(cap, cap + K);

    //가방 용량 이하인 보석 중 가장 높은 가치를 가진 보석을 get
    int idx = 0;
    for(int i = 0; i < K; i++) {
        for(int j = idx; j < N; j++) {
            //가방 용량보다 보석의 무게가 커지는 순간 break;
            if(jewels[j].first > cap[i] || idx >= N) break;
            pq.push(jewels[j].second);
            idx++;
        }
        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    //OUTPUT
    cout << ans;
}