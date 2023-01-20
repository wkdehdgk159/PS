//https://www.acmicpc.net/problem/1744
//1744. 수 묶기(Gold 4, 그리디)

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

int N, ans = 0;
int arr[50];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    //SOLVE
    sort(arr, arr + N);
    
    int idx = 0, idx2 = N-1;
    while(arr[idx] <= 0 && idx < N) {
        //마지막인지 확인 
        if(idx == N-1) {
            ans += arr[idx];
            idx += 1;
            break;
        }
        //뒷 친구가 양수인 상황
        if(arr[idx+1] > 0 ) {
            ans += arr[idx];
            idx += 1;
            break;
        }
        //두 개를 곱하는 상황
        if(arr[idx+1] <= 0) {
            ans += arr[idx] * arr[idx+1];
            idx += 2;
            continue;
        }
    }

    while(idx2 >= idx) {
        //1이 나온 순간 곱하지 말고 모두 더해주기
        if(arr[idx2-1] == 1) {
            ans += arr[idx2];
            idx2--;
            continue;
        }
        if(arr[idx2] == 1) {
            while(arr[idx2] == 1) {
                ans += 1;
                idx2--;
                if(idx2 < 0) break;
            }
            break;
        }
        //끝인지 확인
        if(idx2 == idx) {
            ans += arr[idx2];
            break;
        }
        //두개 더해주는 순간
        if(arr[idx2-1] > 1) {
            ans += arr[idx2] * arr[idx2-1];
            idx2 -= 2;
            continue;
        }
    }

    //OUTPUT
    cout << ans;
}