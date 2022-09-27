//https://www.acmicpc.net/problem/14658
//하늘에서 별똥별이 빗발친다(골드 3, 브루트포스)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

pair<int, int> SS[100];//Shooting Star라는 뜻 ㅎ

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("input.txt", "r", stdin);

    //INPUT
    int N, M, L, K, max_cover = 0;
    cin >> N >> M >> L >> K;
    for(int i = 0; i < K; i++) {
        int x, y;
        cin >> x >> y;
        SS[i] = make_pair(x, y);
    }

    //SOLVE
    for(int i = 0; i < K; i++) {
        for(int j = 0; j < K; j++) {
            int tmp = 0;
            int x = SS[i].first;
            int y = SS[j].second;
            for(int k = 0; k < K; k++) {
                int dx = SS[k].first;
                int dy = SS[k].second;
                if(x <= dx && dx <= x + L && y <= dy && dy <= y + L) tmp++;
            }
            max_cover = (tmp > max_cover) ? tmp : max_cover;
        }
    }
    
    //OUTPUT
    cout << K - max_cover;



    return 0;
}
//
