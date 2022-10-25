//https://www.acmicpc.net/problem/1027
//1027. 고층건물(Gold 5, 구현, 브루트포스)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N, ans;
int height[50];
int cwb[50];

void can_watch(int a, int b) {
    double p = (double)(height[b] - height[a])/(b - a);
    for(int i = a + 1; i < b; i++) {
        if(height[i] >= height[a] + p * (i - a)) return;
    }
    cwb[a]++;
    cwb[b]++;
    return;
}
int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(cwb, 0, sizeof(cwb));
    cin >> N;
    for(int i = 0; i < N; i++) cin >> height[i];

    //SOLVE
    for(int i = 0; i < N - 1; i++) {
        for(int j = i + 1; j < N; j++) {
            can_watch(i, j);
        }
    }

    // OUTPUT
    for(int i = 0; i < N; i++) ans = max(ans, cwb[i]);
    cout << ans;
}
//이러면 안되는데 N이 50인 걸 보고 아 브루트포스겠구나 감을 잡았다
//다른 건물과 만나는 점을 모두 구하여 풀었는데 기울기만으로 구하는 코드가 더 깔끔해 보인다.