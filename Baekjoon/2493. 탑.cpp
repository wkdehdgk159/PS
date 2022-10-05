//https://www.acmicpc.net/problem/2493
//2493. 탑(Gold 5, 스택, 구현)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

int N;
int height[500001];
int meet[500001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(height, 0, sizeof(height));
    memset(meet, 0, sizeof(meet));

    cin >> N;
    for(int i = 1; i < N + 1; i++) {
        cin >> height[i];
    }

    //SOLVE
    //자신의 직전 탑이 더 높거나 같다면 그 탑을 출력하고 아니라면 직전 탑이 닿는 탑들을 따라가며 자신보다 크거나 같은 경우를 출력한다. O(1)은 힘든가?
    
    for(int i = 1; i < N + 1; i++) {
        if(height[i - 1] > height[i]) {
            meet[i] = i - 1;
        }
        else {
            for(int j = meet[i - 1]; j > 0;) {
                if(height[j] > height[i]) {
                    meet[i] = j;
                    break;
                } else {
                    j = meet[j];
                }
            }
        }
    }


    //OUTPUT
    for(int i = 1; i < N + 1; i++) cout << meet[i] << " ";

    return 0;
}
//나는 스택 문제인지도 몰르구 would you like hater.. 그냥 이전 탑들을 추적하는 것으로 생각했는데
//아이디어만 적자면 진행하면서 원하는 높이가 나올 때까지 pop하고 자신을 Push하면 된다.