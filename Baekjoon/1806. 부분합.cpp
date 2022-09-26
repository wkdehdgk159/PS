//https://www.acmicpc.net/problem/1806
//부분합(골드4)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

#define endl "\n"
using namespace std;

int N;
int ans = 0;
int sum_arr[100000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    int N, S, tmp;
    cin >> N >> S;

    sum_arr[0] = 0;
    //누적합이 되도록 넣어주기
    for(int i = 1; i <= N; i++) {
        cin >> tmp;
        sum_arr[i] = sum_arr[i - 1] + tmp;
    }

    int l = 0, r = 1, tmp_sum = 0, min_len = 100001;
    while(r < N + 1) {
        if(l >= r) break;
        tmp_sum = sum_arr[r] - sum_arr[l];
        //연속합이 목표치보다 크면 갱신하고 더 작은 길이에서도 만족하는지 검사하기 위해 왼쪽 포인터를 하나 당겨준다.
        if(tmp_sum >= S) {
            if(r - l >= 1 && r - l< min_len) {
                min_len = r - l;
                ans = min_len;
            }
            l++;
        }
        //목표치보다 작으면 더해줘야하므로 오른쪽 포인터 밀기 
        else {
            r++;
        }
    }

    cout << ans;



    return 0;
}

//투포인터로 부분합을 이동하며 최소 길이를 구한다. 근데 연속된 수열이라면서 하나도 포함이라니..