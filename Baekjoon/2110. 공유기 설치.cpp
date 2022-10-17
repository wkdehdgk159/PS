//https://www.acmicpc.net/problem/2110
//2110. 공유기 설치(Gold 4, 이분 탐색)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;

int home[200001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    int N, C;

    //INPUT
    cin >> N >> C;
    for(int i = 0; i < N; i++) {
        cin >> home[i];
    }

    //SOLVE
    sort(home, home + N);
    //최소 거리 1과 최대 거리 home[N-1] - home[0] 사이에서 이분탐색으로 가장 적절한 거리를 찾는다.
    int start = 1;
    int end = home[N-1] - home[0];
    int ans = 0, cnt = 0, mid, coor;

    while(start <= end) {
        mid = (start + end) / 2;
        coor = home[0];
        cnt = 1;
        for(int i = 1; i < N; i++) {
            //첫번째 집은 무조건 설치한 후에 현재 설정한 갭에서 공유기가 몇개까지 설치 가능한 지 확인
            if(home[i] >= coor + mid) {
                coor = home[i];
                cnt++;
            }
        }
        //공유기가 충분히 설치 가능하면 갭을 더 늘려봄
        if(cnt >= C) {
            ans = mid;
            start = mid + 1;
        } 
        else {
            end = mid - 1;
        }
    }
    //OUTPUT
    cout << ans;
}
//분류가 이분탐색인 것을 알고도 좌표 관점에서만 생각을 해서 결국 블로그를 참고했다.
//알고보니 우리가 찾는 정답이 최대 거리니 최대 거리를 이분탐색하는 문제였다.