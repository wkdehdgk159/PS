//https://www.acmicpc.net/problem/2531
//회전 초밥(실버 1, 브루트포스, 투 포인터)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

int eaten[3001]; //해당 초밥을 먹은 횟수
int sushi[30000]; 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(eaten, 0, sizeof(eaten));
    memset(sushi, 0, sizeof(sushi));

    int n, d, k, c, max_types = 0, tmp_types = 0;
    cin >> n >> d >> k >> c;
    for(int i = 0; i < n; i++) {
        cin >> sushi[i];
    }

    //SOLVE
    //초기 k개를 선택
    for(int i = 0; i < k; i++) {
        if(eaten[sushi[i]] == 0) max_types++;
        eaten[sushi[i]]++;
    }
    //내가 먹은 코스에 쿠폰스시가 없다면 꽁으로 하나
    //**** 여기 때문에 7번 틀림! 위아래 두줄이 바뀌면 안된다. 아래 for문에서 쿠폰을 따로 판별해 줄 것이기 때문(중복)
    tmp_types = max_types;
    if(eaten[c] == 0) max_types++;

    //벨트를 k개만큼의 간격으로 쭉 돌면서
    for(int i = 1; i < n; i++) {
        int start = i;
        int end = (i + k - 1) % n;

        if(eaten[sushi[end]] == 0) tmp_types++;
        eaten[sushi[end]]++;

        eaten[sushi[start - 1]]--;
        if(eaten[sushi[start - 1]] == 0) tmp_types--;

        if(eaten[c] == 0) {
            max_types = (tmp_types + 1 >= max_types) ? tmp_types + 1 : max_types;
        } else {
            max_types = (tmp_types >= max_types) ? tmp_types : max_types;
        }
    }
    
    //OUTPUT
    cout << max_types;

    return 0;
}
