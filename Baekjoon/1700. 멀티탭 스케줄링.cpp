//https://www.acmicpc.net/problem/1700
//1700. 멀티탭 스케줄링(Gold 1, 그리디)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long

using namespace std;

int N, K, ans = 0;
int item[101];
int schedule[101];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> K;

    for(int i = 1; i < K + 1; i++) {
        cin >> schedule[i];
    }
    memset(item, 0, sizeof(item));

    //SOLVE
    int cnt = 0;
    for(int i = 1; i < K + 1; i++) {
        if(N >= K) break;
        //플러그가 비어있고 현재 아이템이 플러그에 꽂혀있지 않다면 넣어주기
        if(cnt < N) {
            if(item[schedule[i]] == 0) {
                item[schedule[i]] = 1;
                cnt++;
            }
        }
        else if(cnt == N) {
            //플러그가 꽉 차있고 현재 아이템이 플러그에 꽂혀있다면 스킵
            if(item[schedule[i]] == 1) {
                continue;
            }
            //플러그가 꽉 차있고 현재 아이템이 플러그에 꽂혀있지 않다면
            //현재 꽂힌 아이템들 중 가장 나중에 쓰일 아이템의 플러그를 뽑아줘야 한다.
            else if(item[schedule[i]] == 0) {
                int tmp = 0;
                for(int j = i; j < K + 1; j++) {
                    //마지막 남은 것 제외하고 다 찾으면 break
                    if(tmp == N - 1) break;
                    //현재 꽂힌 상태고 다음 스케줄까지 꽂혀있을 예정이면 2로 바꿔준다.
                    if(item[schedule[j]] == 1) {
                        item[schedule[j]] = 2;
                        tmp++;
                    }
                }
                //전체 아이템들을 돌며 2인 친구들은 다음 번에도 플러그에 꽂혀 있을테니 1로 바꿔주기
                //1인 친구들의 플러그는 현재 아이템으로 갈아끼울테니 0으로 바꿔주기
                for(int j = 1; j < K + 1; j++) {
                    if(item[j] == 2) item[j] = 1;
                    else if(item[j] == 1) item[j] = 0;
                }
                item[schedule[i]] = 1;
                ans++;
            }
        }
        // cout << ans << " ";
    }

    //OUTPUT
    cout << ans;
}