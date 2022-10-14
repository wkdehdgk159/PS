//https://www.acmicpc.net/problem/21921
//21921. 블로그(Silver 3, 누적합, 슬라이딩 윈도우)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    int N, X, max_v = 0, tmp_sum = 0, times = 0;
    int visitor[250001];
    //INPUT
    cin >> N >> X;
    for(int i = 1; i <= N; i++) {
        cin >> visitor[i];
    }

    //SOLVE
    for(int i = 1; i <= X; i++) {
        tmp_sum += visitor[i];
    }
    max_v = tmp_sum;
    times = 1;

    for(int i = X + 1; i <= N; i++) {
        tmp_sum = tmp_sum - visitor[i - X] + visitor[i];
        if(tmp_sum > max_v) {
            max_v = tmp_sum;
            times = 1;
        }
        else if(tmp_sum ==  max_v) times++;
    }

    //OUTPUT
    if(max_v == 0) cout << "SAD"; 
    else cout << max_v << endl << times << endl;
}
//변수 초기화를 잘 하자