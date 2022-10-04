//https://www.acmicpc.net/problem/14719
//14719. 빗물(Gold 5, 구현)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

int H, W;
int height[500];
int lmost[500];
int rmost[500];
int ans = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(height, 0, sizeof(height));
    memset(lmost, 0, sizeof(lmost));
    memset(rmost, 0, sizeof(rmost));

    cin >> H >> W;
    for(int i = 0; i < W; i++) {
        cin >> height[i];
    }

    //SOLVE
    //해당 칸에서 쌓이는 빗물은 자신의 왼쪽과 오른쪽에 가장 높은 높이 중 작은 것 - 자신의 높이 (본인이 그들보다 낮을 경우이며 양 끝은 제외(무조건 배수됨))

    int l_max = 0, r_max = 0;
    for(int i = 0; i < W; i++) {
        if(l_max < height[i]) l_max = height[i];
        lmost[i] = l_max;
    }

    for(int i = W - 1; i > 0; i--) {
        if(r_max < height[i]) r_max = height[i];
        rmost[i] = r_max;
    }

    for(int i = 1; i < W - 1; i++) {
        int tmp = min(lmost[i], rmost[i]) - height[i];
        if(tmp > 0) {
            ans += tmp;
        }
    }

    //OUTPUT
    cout << ans;

    return 0;
}
//아이디어만 떠올린다면 구현도 굉장히 쉬운 문제. 골드 난이도는 아닌 것 같다