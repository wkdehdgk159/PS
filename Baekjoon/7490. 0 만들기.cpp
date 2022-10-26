//https://www.acmicpc.net/problem/7490
//7490. 0 만들기(Gold 5, 백트래킹, 브루트포스)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int TC, N;
int ans[10];

void cal_ans(int res, int cnt, int num, int sym, string a) {//sym은 1이나 -1이냐
    //마지막 계산
    if(N == cnt) {
        res = res + sym * num;
        if(res == 0) cout << a << endl;
    }
    else {
        //아스키 순
        //공백 - 미리 계산하지 않고 num에 합쳐질 수를 전달한다. 
        cal_ans(res, cnt + 1, num * 10 + cnt + 1, sym, a + ' ' + char(cnt + 1 + '0'));
        //+
        cal_ans(res + sym * num, cnt + 1, cnt + 1, 1, a + '+' + char(cnt + 1 + '0'));
        //-
        cal_ans(res + sym * num, cnt + 1, cnt + 1, -1, a + '-' + char(cnt + 1 + '0'));
    }
    return;
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
        cal_ans(0, 1, 1, 1, "1");
        cout << endl;
    }

    // OUTPUT
}
//구현문제인데 재귀방식에 대해 고민을 좀 한 문제