//https://www.acmicpc.net/problem/13144
//13144. List of Unique Numbers(Gold 4, 투포인터)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N;
int arr[100001];
int visited[100001];
ll ans = 0;

//1부터 a까지 더한 값

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(visited, 0, sizeof(visited));
    cin >> N;
    for(int i = 0; i < N; i++) cin >> arr[i];

    //SOLVE
    int l = 0, r = 0;
    while(l < N) {
        //방문처리 해주면서 r 이동
        while(r < N) {
            if(visited[arr[r]]) break;
            visited[arr[r]] = 1;
            r++;
        }
        ans += r - l;
        //r 위치에 있는 중복되는 수는 이제는 유일한 수이니 방문 0으로 만들어 줄 것 어차피 후에 순회하면서 다시 방문처리될 것이니
        visited[arr[l]] = 0;
        l++;
    }
    

    // OUTPUT
    cout << ans;
}
//DP와 투포인터의 구분이 쉽지 않다.