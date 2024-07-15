//https://www.acmicpc.net/problem/14888
//14888. 연산자 끼워넣기(Silver 1, 백트래킹, 브루트포스)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INF 999999999
using namespace std;

int ans_max = -1000000001, ans_min = 1000000001;
int N;
int num[101];
int op_cnt[4];

void cal(int res, int op, int cnt) {

    if(op == 0) res = res + num[cnt];
    else if(op == 1) res = res - num[cnt];
    else if(op == 2) res = res * num[cnt];
    else if(op == 3) res = res / num[cnt];

    //모든 계산이 끝났다면 최대, 최소 비교 후 함수 종료
    if(cnt == N - 1) {
        ans_max = max(ans_max, res);
        ans_min = min(ans_min, res);
        return;
    }

    //그 외의 경우 계산 진행
    for(int i = 0; i < 4; i++) {
        //사용할 부호가 더 없을 경우 continue
        if(op_cnt[i] == 0) continue;

        //사용할 부호가 존재할 경우 사용 표시로 -1 해주고, 함수 돌리고, 복원
        op_cnt[i]--;

        cal(res, i, cnt+1);

        op_cnt[i]++;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);


    //INPUT
    cin >> N;
    for(int i = 0; i < N; i++) {
        cin >> num[i];
    }
    for(int i = 0; i < 4; i++) {
        cin >> op_cnt[i];
    }

    //SOLVE
    cal(num[0], -1, 0);

    //OUTPUT
    cout << ans_max << " " << ans_min << endl;
}