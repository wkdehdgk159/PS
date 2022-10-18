//https://www.acmicpc.net/problem/3687
//3687. 성냥개비(Gold 2, DP)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

typedef long long ll;
#define endl "\n"
#define INF 99999999999999999
using namespace std;

int N, TC;
ll dp_min[101] = {INF, INF, 1, 7, 4, 2, 6, 8};
int min_num[8] = {0,0,1,7,4,2,0,8};

ll make_min(int n) {
    ll mmin = INF;
    for(int i = 2; i <= 7; i++) {
        mmin = min(dp_min[n-i] * 10 + min_num[i], mmin);
    }
    return mmin;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> TC;

    //SOLVE
    //테케 많이 돌릴테니 기억해놓자
    for(int i = 8; i <= 100; i++) {
        dp_min[i] = make_min(i);
    }
    for(int t = 0; t < TC; t++) {
        cin >> N;
        cout << dp_min[N] << " ";
        int cnt = 0;
        while(N > 0) {
            if(N == 3) {
                cout << 7;
                N -= 3;
                break;
            }
            else {
                cnt++;
                N -= 2;
            }
        }
        for(int i = 0; i < cnt; i++) cout << 1;
        cout << endl;
    }
}
//최소값을 구할때는 실제 정수계산이 필요하고 최대값을 구할때는 ll범위도 넘어버려서 
//최소값은 DP로 최대값은 문자열출력으로 해결했다.