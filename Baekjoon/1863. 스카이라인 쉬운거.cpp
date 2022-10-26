//https://www.acmicpc.net/problem/1863
//1863. 스카이라인 쉬운거(Gold 4, 스택, 그리디)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int n, ans = 0;
bool visited[500001];//높이에 따른 방문배열
int arr[50000];

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(visited, 0, sizeof(visited));
    int x;
    cin >> n;
    for(int i = 0; i < n; i++) cin >> x >> arr[i];

    //SOLVE
    if(arr[0] != 0) ans++;
    visited[arr[0]] = 1;
    for(int i = 1; i < n; i++) {
        //같은 높이는 나올 수 없음
        //이전보다 높이가 낮으면 그 사이의 높이들이 다시 지어질 수 있게 방문처리 취소하고 현재 높이 방문 체크하기
        if(arr[i] < arr[i-1]) {
            for(int j = arr[i] + 1; j <= arr[i-1]; j++) {
                visited[j] = false;
            }
            if(!visited[arr[i]]) {
                //고도 0일때 조심
                if(arr[i] != 0) ans++;
                visited[arr[i]] = true;
            }
        }
        //이전보다 고도가 높으면 새로운 건물이 필요하다는 이야기이므로 현재 높이 방문처리해주고 ans++
        if(arr[i] > arr[i-1]) {
            visited[arr[i]] = true;
            ans++;
        }
    }

    // OUTPUT
    cout << ans;
}
//구현을 잘 해서 풀긴 했지만 역시 노림수가 있는 문제였다.
//스택 큐를 개념만 알지 문제에 적용하는 건 아직 부족해 보인다. 스택을 이용한 알고리즘은 자신보다 낮은 원소가 나올때까지 pop하면서 1씩 추가하고
//마지막 건물까지 다 적용한 후 스택의 원소 수만큼을 더해준다.