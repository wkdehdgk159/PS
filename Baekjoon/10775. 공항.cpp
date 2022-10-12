//https://www.acmicpc.net/problem/10775
//10775. 공항(Gold 2, Union-find)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;

int G, P;
int Root[100001];

int find(int x) {
    if(x == Root[x]) return x;
    else return Root[x] = find(Root[x]);
}

void make_Union(int x, int y) {
    x = find(x);
    y = find(y);

    if(x == y) return;

    Root[y] = x;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> G;
    cin >> P;
    for(int i = 0; i < 100001; i++) {
        Root[i] = i;
    }

    //SOLVE
    int g_i, ans = 0;
    for(int i = 0; i < P; i++) {
        cin >> g_i;
        int eg = find(g_i);
        //주의 이 문제에서 Union by Rank를 적용하면 안된다. 무조건 앞 번호의 gate가 root가 되야하므로
        if(eg == 0) break;
        else {
            make_Union(eg - 1, eg);
            ans++;
        }
    }
        
    //OUTPUT
    cout << ans;
}
//이게 왜 Union-find 문제인 지 이해를 못 해서 블로그의 도움을 받았다.
//가장 그리디한 방법은 최대한 뒷 순서의 게이트에 도킹을 하고 뒤에서부터 빈 게이트를 찾는 것이겠으나 이는 최악의 경우 10^10
//번의 연산을 하게 될 것이고 그 결과 75% 정도에서 시간 초과가 걸렸다.
//앞 게이트와 union을 해주어 해당 칸 앞 게이트들 중 가장 뒤에 있는 게이트를 확인할 수 있고 만약 find 결과가 0일 경우 
//게이트 범위가 모두 차 있다는 의미를 가진다.