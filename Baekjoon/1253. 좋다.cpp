//https://www.acmicpc.net/problem/1253
//1253. 좋다 (Gold4, 정렬, 이분 탐색, 투포인터)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>

#define endl "\n"
using namespace std;

int N;
int ans = 0;
int A[2000];

void solve() {
    sort(A, A + N);

    for(int i = 0; i < N; i++) {
        int left = 0, right = N - 1;
        int target =  A[i];

        while(left < right) {
            int tmp = A[left] + A[right];
            //원하는 수보다 크면 right 줄여서 작게
            if(tmp > target) {
                right--;
            } 
            //원하는 수보다 작으면 left 키워서 크게
            else if(tmp < target) {
                left++;
            }
            //원하는 수와 일치하면 ans++ 지만 자기 자신을 포함하는 경우는 제외
            else if(tmp == target) {
                if(left == i) left++;
                else if(right == i) right--;
                else { 
                    ans++;
                    break;
                }
            }
        }
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
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    //SOLVE
    solve();

    //OUTPUT
    cout << ans << endl;


    return 0;
}

//투포인터로 단순 구현문제