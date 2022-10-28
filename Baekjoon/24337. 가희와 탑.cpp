//https://www.acmicpc.net/problem/24337
//24337. 가희와 탑(Gold 3, 그리디)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N;
int a, b;
int height[100003];

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N >> a >> b;

    //SOLVE
    //두 시야 건물 합이 N + 1보다 클 수 없음
    if(a + b > N + 1) {
        cout << -1;
        return 0;
    }
    //높이가 다른 건물 종류 수는 max(a, b)
    //a와 b는 각각 가희와 단비의 입장에서 LIS의 길이
    //사전 순이라는 조건이 있기 때문에 max(a,b)가 5라면 건물의 최대 높이를 5로 설정하고 묻히는 건물들은 다 1로 취급해야 한다. 이 1들도 사전 순 조건에 따라 왼쪽에 많이 쏠리도록
    //시작 idx는 1이라 가정
    int max_idx, ups_idx;
    int max_height = max(a, b);

    //1을 최대한 채워주다가 1234 오름차순 넣어주기
    if(a != 1) {
        max_idx = N - b + 1;
        ups_idx = max_idx - a + 1;
        height[max_idx] = max_height;

        //최고층 건물 우측을 b의 종류만큼
        for(int i = N; i > max_idx; i--) {
            height[i] = N - i + 1;
        }
        for(int i = 1; i < ups_idx; i++) {
            height[i] = 1;
        }
        for(int i = ups_idx; i < max_idx; i++) {
            height[i] = i - ups_idx + 1;
        }
    }
    //만약에 가희입장에서 건물이 1개만 보인다면 그건 최고높이의 건물일 것이므로 가장 왼쪽이 최고높이 일 것
    //그래서 9 1 5를 가정했을 때 5 1 1 1 1 4 3 2 1 이렇게 해줘야 함.
    else {
        int idx = N - b + 2;
        height[1] = max_height;
        for(int i = 2; i < idx; i++) {
            height[i] = 1;
        }
        for(int i = N; i >= idx; i--) {
            height[i] = N - i + 1;
        }
    }

    //OUTPUT
    for(int i = 1; i <= N; i++) {
        cout << height[i] << " ";
    }
}
//아이디어 문제였다
//9 1 5를 54321111로 계속 착각하여 반례에 시간을 많이 소모했다.