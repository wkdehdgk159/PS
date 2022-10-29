//https://www.acmicpc.net/problem/1943
//1943. 동전 분배(Gold 3, DP, knapsack)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N;
pair<int, int> coin[100]; //가격, 개수
int dp[50001];

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    for(int TC = 0; TC < 3; TC++) {
        cin >> N;
        int price, num, total = 0;
        for(int i = 0; i < N; i++) {
            cin >> price >> num;
            coin[i] = make_pair(price, num);
            total += price * num;     
        }

        //SOLVE
        if(total % 2 == 1) {
            cout << 0 << endl;
            continue;
        }
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        //오름차순으로 정렬
        sort(coin, coin + N);
        int target = total / 2;
        //가장 큰 단위의 동전을 한 명이 최소 절반 이상은 소모해야 한다.
        //top-down으로 채워주는 이유는 3원 동전이 하나임에도 dp[3]이 1이 된 순간 다시 dp[3]에 대해 dp[6]이 1이 될 수도 있다.
        //또한 50원 동전이 3개라고 했을 때 dp[j - 50], 100, 150을 모두 체크해줄 수 있다.
        for(int i = 0; i < N; i++) {
            for(int j = 50000; j >= coin[i].first; j--) {
                if(dp[j - coin[i].first]) {
                    for(int k = 0; k < coin[i].second && j + k * coin[i].first <= 50000; k++) {
                        dp[j + k * coin[i].first] = 1;
                    }
                }
            }
        }
        cout << dp[target] << endl;
    }
    
    //OUTPUT
    
}