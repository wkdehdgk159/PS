//https://www.acmicpc.net/problem/17615
//볼 모으기(Silver 1, 그리디)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
using namespace std;

int N;
int exe_balls[500000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT

    char tmp[500100];
    int min_move = 500000, idx = 0;;
    cin >> N;

    cin >> tmp;
    for(int i = 0; i < N; i++) {
        if(tmp[i] == 'R') {
            if(exe_balls[idx] >= 0) {
                exe_balls[idx]++;
            } else {
                idx++;
                exe_balls[idx]++;
            }
        } else {
            if(exe_balls[idx] <= 0) {
                exe_balls[idx]--;
            } else {
                idx++;
                exe_balls[idx]--;
            }
        }
    }

    //SOLVE
    //아이디어는 어차피 한쪽 방향으로만 다 옮겨야 한다. R을 전부 오른쪽, R을 전부 왼쪽
    //B를 전부 오른쪽, B를 전부 왼쪽으로 옮기는 상황 중 답이 있을 것이다.
    
    //R을 전부 오른쪽으로 -> exe_balls의 양수들을 앞에서부터 전부 더하고 마지막이 R인지 B인지만 확인
    int tmp_move = 0;
    int start = (exe_balls[0] > 0) ? 0 : 1;
    for(int i = start; i <= idx; i += 2) {
        tmp_move += exe_balls[i];
    }
    //마지막이 R이었다면 움직일 필요가 없었으니 다시 빼주기
    if(exe_balls[idx] > 0) tmp_move -= exe_balls[idx];
    min_move = tmp_move < min_move ? tmp_move : min_move;

    //R을 전부 왼쪽으로
    tmp_move = 0;
    start = (exe_balls[0] > 0) ? 2 : 1;
    for(int i = start; i <= idx; i += 2) {
        tmp_move += exe_balls[i];
    }
    min_move = tmp_move < min_move ? tmp_move : min_move;

    //B를 전부 오른쪽
    tmp_move = 0;
    start = (exe_balls[0] < 0) ? 0 : 1;
    for(int i = start; i <= idx; i += 2) {
        tmp_move += exe_balls[i];
    }
    if(exe_balls[idx] < 0) tmp_move -= exe_balls[idx];
    tmp_move = -tmp_move;
    min_move = tmp_move < min_move ? tmp_move : min_move;

    //B를 전부 왼쪽
    tmp_move = 0;
    start = (exe_balls[0] < 0) ? 2 : 1;
    for(int i = start; i <= idx; i += 2) {
        tmp_move += exe_balls[i];
    }
    tmp_move = -tmp_move;
    min_move = tmp_move < min_move ? tmp_move : min_move;

    //OUTPUT
    cout << min_move;

    return 0;
}
//이 누적합(?)을 이용한 풀이보다 그냥 모든 원소 하나하나 체크해주면서 하는 풀이가 더 직관적이고 깔끔해보였다. 누적합 좀 배웠나보다..