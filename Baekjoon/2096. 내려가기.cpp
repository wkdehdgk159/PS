//https://www.acmicpc.net/problem/2096
//2096. 내려가기(Gold 5, DP)

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
int arr[3][3];
int dp_max[3][3];
int dp_min[3][3];

int get_max(int a, int b, int c) {
    return max(a, max(b, c));
}
int get_min(int a, int b, int c) {
    return min(a, min(b, c));
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(dp_max, 0, sizeof(dp_max));
    memset(dp_min, 0, sizeof(dp_min));
    cin >> N;
    int cur_idx = 0, pre_idx = 0;
    for(int i = 0; i < N; i++) {
        if(i == 0) {
            for(int j = 0; j < 3; j++) {
                cin >> arr[i][j];
                dp_max[i][j] = arr[i][j];
                dp_min[i][j] = arr[i][j];
            }
        }
        else {
            cur_idx = i % 3;
            pre_idx = (cur_idx == 0) ? 2 : cur_idx - 1;
            for(int j = 0; j < 3; j++) {
                cin >> arr[cur_idx][j];
            }

            dp_max[cur_idx][0] = arr[cur_idx][0] + max(dp_max[pre_idx][0], dp_max[pre_idx][1]);
            dp_max[cur_idx][1] = arr[cur_idx][1] + get_max(dp_max[pre_idx][0], dp_max[pre_idx][1], dp_max[pre_idx][2]);
            dp_max[cur_idx][2] = arr[cur_idx][2] + max(dp_max[pre_idx][1], dp_max[pre_idx][2]);
            dp_min[cur_idx][0] = arr[cur_idx][0] + min(dp_min[pre_idx][0], dp_min[pre_idx][1]);
            dp_min[cur_idx][1] = arr[cur_idx][1] + get_min(dp_min[pre_idx][0], dp_min[pre_idx][1], dp_min[pre_idx][2]);
            dp_min[cur_idx][2] = arr[cur_idx][2] + min(dp_min[pre_idx][1], dp_min[pre_idx][2]);
        }
    }

    //SOLVE

    //OUTPUT
    cout << get_max(dp_max[cur_idx][0], dp_max[cur_idx][1], dp_max[cur_idx][2]) << " " << get_min(dp_min[cur_idx][0], dp_min[cur_idx][1], dp_min[cur_idx][2]);
} 
//[100000][3] 배열을 선언해서 dp를 해도 답은 나오지만 메모리 초과가 뜬다
//2x3 슬라이딩 윈도우도 가능했지만 그냥 3x3했다 ㅎ