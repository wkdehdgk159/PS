//https://www.acmicpc.net/problem/1913
//1913. 달팽이(Silver 3, 구현)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INT_INF 2147483647
#define LL_INF 9223372036854775807
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    //INPUT
    int A, B;
    cin >> A >> B;

    //SOLVE
    cout << A + B;

    //OUTPUT
}
/*
1. 많은 조건 분기라니까 홀짝, mn의 대소들을 고려해보자
2. m n 중에 짧은 놈에 따라서 회전 수가 정해진다. m이 4보다 크고 n이 4 라면 m이 몇이든 간에 (4-1)*2+1
3. m이 더 짧으면 한번 회전을 덜한다 (m-1)*2
4. 둘이 같으면 한번 회전 덜한다 m <= n 으로 분기하자
5. 마지막 좌표는 홀짝 따라 대소에 따라 또 다른가?   
6. m > n
*/