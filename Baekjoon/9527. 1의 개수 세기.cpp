//https://www.acmicpc.net/problem/9527
//9527. 1의 개수 세기(Gold 2, 비트마스킹, 누적합)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

ll A, B;
ll dp[56] = {0, 1}; //dp[i]는 i자리 수 2진수에 있는 모든 1을 더한 값

ll sum_1(ll x) {
    ll tmp = 0;
    for(int i = 55; i > 0; i--) {
        //i번째 비트가 1이라면
        if(x & (1LL << (i-1))) {
            //최상위 비트가 i번째보다 아래인 아이들 모두 + i번째 최상위 비트들만 처리
            tmp += dp[i - 1] + (x - (1LL << (i-1)) + 1);
            x -= 1LL << (i-1);
        }
    }
    return tmp;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    
    cin >> A >> B;

    //SOLVE
    for(int i = 2; i < 56; i++) {
        dp[i] = dp[i - 1] * 2 + (1LL << (i-1));
    }

    // OUTPUT
    cout << sum_1(B) - sum_1(A - 1);

}
//비트 마스킹과 누적합까지는 감이 잡혔지만 i번째 비트가 켜진 모든 수들을 처리할 생각만 했지
//최상위 비트를 가진 아이들만 비트 하나하나 없애가며 카운트하는 접근법은 생각도 못 했다.
//다음에 풀었을 때도 맞출 자신이 없어 링크를 첨부한다.
//https://degurii.tistory.com/158