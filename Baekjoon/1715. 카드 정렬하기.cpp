//https://www.acmicpc.net/problem/1715
//1715. 카드 정렬하기(Gold 4, 그리디, 우선순위큐)

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

int N;
ll ans = 0;
int arr[100001];
priority_queue<int, vector<int>, greater<int> > pq;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
        pq.push(arr[i]);
    }

    //SOLVE
    //그 순간 가장 작은 두개를 골라야 하므로 정렬을 계속 해줘야 한다.
    //10만번 정렬을 할 수는 없으니 우선순위 큐 이용
    int tmp;
    while(pq.size() != 1) {
        tmp = pq.top();
        pq.pop();
        tmp += pq.top();
        pq.pop();
        pq.push(tmp);
        ans += tmp;
    }
    

    //OUTPUT
    cout << ans;
}