//https://www.acmicpc.net/problem/22251
//22251. 빌런 호석(Gold 5, 구현, 브루트포스)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;

//LED on-off 여부
int LED_ON[10][7] = {{1,1,1,0,1,1,1},{0,0,1,0,0,1,0},{1,0,1,1,1,0,1},{1,0,1,1,0,1,1},{0,1,1,1,0,1,0},{1,1,0,1,0,1,1},{1,1,0,1,1,1,1},{1,0,1,0,0,1,0},{1,1,1,1,1,1,1},{1,1,1,1,0,1,1}};
int LED_change[10][10]; //i -> j로 바꾸는 데 반전해야할 LED 개수.
int num[6], num_b[6];
int N, K, P, X, ans;

void make_LED(int x) {
    string tmp = to_string(x);
    for(int i = 0; i < K - tmp.length(); i++) {
        num[i] = 0;
    }
    for(int i = K - tmp.length(); i < K; i++) {
        num[i] = tmp[i - K + tmp.length()] - 48;
    }
}

void make_LED_b(int n) {
    string tmp = to_string(n);
    for(int i = 0; i < K - tmp.length(); i++) {
        num_b[i] = 0;
    }
    for(int i = K - tmp.length(); i < K; i++) {
        num_b[i] = tmp[i - K + tmp.length()] - 48;
    }
}

int count() {
    int a = 0;
    for(int i = 0; i < K; i++) {
        a += LED_change[num[i]][num_b[i]];
    }
    return a;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> K >> P >> X;

    //SOLVE
    //digit변환마다 필요한 LED 반전 개수를 저장.
    for(int i = 0; i < 10; i++) {
        for(int j = 0; j < 10; j++) {
            int cnt = 0;
            for(int k = 0; k < 7; k++) {
                if(LED_ON[i][k] != LED_ON[j][k]) cnt++;
            }
            LED_change[i][j] = cnt;
        }
    }

    //num 배열에 0을 포함한 digit들 삽입
    make_LED(X);

    for(int i = 1; i <= N; i++) {
        make_LED_b(i);
        int cnt = count();
        if (0 < cnt && cnt <= P) {
            ans++;
        }
    }
    
    //OUTPUT
    cout << ans;
}
//숫자변환에 필요한 LED 반전개수를 저장해두고
//N보다 작은 모든 숫자에 대해 확인해보았다.
//LED 반전 개수를 셀 때 비트마스킹을 활용할 수 있었을 수도