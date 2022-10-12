//https://www.acmicpc.net/problem/3780
//3780. 네트워크 연결(Platinum 5, Union-find)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;

int N, TC;
int Root[20001];
int Dist[20001];//자신의 부모까지의 거리 저장

int find(int x) {
    if(x == Root[x]) return x;
    else return find(Root[x]);
}

int Dist_to_Root(int x) {
    int d = 0;
    while(x != Root[x]) {
        d += Dist[x];
        x = Root[x];
    }
    return d;
}

void make_Union(int x, int y) {
    int d = abs(x - y) % 1000 + Dist_to_Root(x);
    x = find(x);
    y = find(y);
    Root[y] = x;
    Dist[y] = d;
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> TC;

    //SOLVE
    for(int i = 0; i < TC; i++) {
        cin >> N;
        for(int i = 0; i < 20001; i++) {
            Root[i] = i;
            Dist[i] = 0;
        }
        char cmd;
        int I, J;
        while(1) {
            cin >> cmd;
            if(cmd == 'E') {
                cin >> I;
                cout << Dist_to_Root(I) << endl;
            }
            //센터 I를 기업 J에 연결
            else if(cmd == 'I') {
                cin >> I >> J;
                make_Union(J, I);
            }
            else if(cmd == 'O') break;
        }
    }
    //OUTPUT
}
//Union-find를 이용하는 것을 알고 들어가서 구현 자체는 어렵지 않았다.
//여기서 최상위 Root에 Union을 하지 않고 그냥 아랫단에 붙이면(find(x), find(y)를 하지 않으면) 시간초과가 뜬다.
//이는 시간초과를 피하기 위해 어떤 기업을 센터에 직속으로 붙여준다는 의미이기에 그에 따른 거리도 Union 단계에서 갱신해주어야 한다.