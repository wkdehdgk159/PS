//https://www.acmicpc.net/problem/10800
//10800. 컬러볼(Gold 3, 누적합)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <tuple>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long
using namespace std;

tuple<int, int, int> arr[200001];
int sumarr[200001];
int res[200001];
int N;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    int C, S;
    for(int i = 1; i <= N; i++) {
        cin >> C >> S;
        arr[i] = make_tuple(S, C, i);
    }

    //SOLVE
    memset(sumarr, 0, sizeof(sumarr));
    memset(res, 0, sizeof(res));
    
    int total_sum = 0;
    int cnt = 0;//중복 크기 세는 용도

    sort(arr + 1, arr + N + 1);
    for(int i = 1; i <= N; i++) {
        //현재 크기, 색, 공의 번호
        int cS = get<0>(arr[i]);
        int cC = get<1>(arr[i]);
        int cN = get<2>(arr[i]);

        //저번 표본과 크기가 같다면 크기가 더 작았던 때의 total_sum에서 빼주면 됨.
        if(cS == get<0>(arr[i-1])) {
            cnt++;
            //전과 색까지 같다면 이전 결과값과 동일
            if(cC == get<1>(arr[i-1])) {
                res[cN] = res[get<2>(arr[i-1])];
            }
            else {
                res[cN] = total_sum - sumarr[cC] - cnt * cS;
            }
        }
        //지금까지의 총 합에서 색이 같은 친구들만 뺀 값을 더해주면 됨
        else {
            res[cN] = total_sum - sumarr[cC];
            cnt = 0;
        }
        total_sum += cS;
        sumarr[cC] += cS;
    }

    //OUTPUT
    for(int i = 1; i <= N; i++) {
        cout << res[i] << endl;
    }
}