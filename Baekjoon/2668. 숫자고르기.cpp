//https://www.acmicpc.net/problem/2668
//2668. 숫자고르기(Gold 5, DFS)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
using namespace std;

int N;
int idx = 0;
int arr[101];
int ans[101];
int visited[101];

//타고타고 가다가 다시 자신과 만나면 답 배열에 저장.
void dfs(int start, int curr) {
    if(visited[curr]) {
        if(curr == start) {
            ans[idx] = start;
            idx++;
        }
    } else {
        visited[curr] = 1;
        dfs(start, arr[curr]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> arr[i];

    //SOLVE
    memset(ans, 0, sizeof(ans));
    for(int i = 1; i <= N; i++) {
        memset(visited, 0, sizeof(visited));
        dfs(i, i);
    }

    //OUTPUT
    cout << idx << endl;
    for(int i = 0; i < idx; i++) {
        cout << ans[i] << endl;
    }

}
//종료조건이 있는 무한 재귀가 있으면 다 DFS로 취급하는 건가?
//그래프 탐색에서의 DFS가 익숙하다보니 조금 헷갈렸다.