//https://www.acmicpc.net/problem/7682
//7682. 틱택토(Gold 5, 백트래킹, 구현)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

string input;
char board[9];
int xc, oc;
int xrc, xcc, xdc, orc, occ, odc;

bool check() {
    xc = 0, oc = 0, xrc = 0, xcc = 0, xdc = 0, orc = 0, occ = 0, odc = 0;
    for(int i = 0; i < 9; i++) {
        if(board[i] == 'X') xc++;
        if(board[i] == 'O') oc++;
    }

    if(board[0] == 'X' && board[0] == board[1] && board[1] == board[2]) xrc++;
    if(board[3] == 'X' && board[3] == board[4] && board[4] == board[5]) xrc++;
    if(board[6] == 'X' && board[6] == board[7] && board[7] == board[8]) xrc++;
    if(board[0] == 'X' && board[0] == board[3] && board[3] == board[6]) xcc++;
    if(board[1] == 'X' && board[1] == board[4] && board[4] == board[7]) xcc++;
    if(board[2] == 'X' && board[2] == board[5] && board[5] == board[8]) xcc++;
    if(board[0] == 'X' && board[0] == board[4] && board[4] == board[8]) xdc++;
    if(board[2] == 'X' && board[2] == board[4] && board[4] == board[6]) xdc++;

    if(board[0] == 'O' && board[0] == board[1] && board[1] == board[2]) orc++;
    if(board[3] == 'O' && board[3] == board[4] && board[4] == board[5]) orc++;
    if(board[6] == 'O' && board[6] == board[7] && board[7] == board[8]) orc++;
    if(board[0] == 'O' && board[0] == board[3] && board[3] == board[6]) occ++;
    if(board[1] == 'O' && board[1] == board[4] && board[4] == board[7]) occ++;
    if(board[2] == 'O' && board[2] == board[5] && board[5] == board[8]) occ++;
    if(board[0] == 'O' && board[0] == board[4] && board[4] == board[8]) odc++;
    if(board[2] == 'O' && board[2] == board[4] && board[4] == board[6]) odc++;

    int ec = xrc + xcc + xdc + orc + occ + odc;

    //X가 이기는 경우 - 마지막에 결정되는 것 고려
    if(xrc + xcc + xdc >= 1 && orc + occ + odc == 0) {
        if(xc == oc + 1) return true;
    }
    //O가 이기는 경우
    if(orc + occ + odc == 1 && xrc + xcc + xdc == 0) {
        if(xc == oc) return true;
    }
    //비기는 경우
    if(xrc + xcc + xdc == 0 && orc + occ + odc == 0) {
        if(xc == 5 && oc == 4) return true;
    }
    return false;
}

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    while(1) {
        cin >> input;
        if(input == "end") return 0;
        for(int i = 0; i < 9; i++) {
            board[i] = input[i];
        }
        if(check()) cout << "valid" << endl;
        else cout << "invalid" << endl;
    }

    //SOLVE

    // OUTPUT
}
//처음에는 기본을 true로 놓고 false인 경우를 거르는 방법으로 짰는데 계속 20%에서 막혔다.
//계속 반례를 못 찾는가 싶어 이제는 맞는 경우를 거르는 방법으로 계속 고민해도 20%에서 막혔다.
//여러 블로그를 봤는데 나와 알고리즘이 똑같았다. string만 달랐다.
//예전에 인풋 char를 크게 설정하지 않아 삽질했던 기억이 불현듯 떠올랐다. 휴..