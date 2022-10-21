//https://www.acmicpc.net/problem/22866
//22866. 탑 보기(Gold 3, 스택)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <stack>

#define endl "\n"
#define INF 999999
using namespace std;

int N;
int height[100001];
int ans[100001];
int dist[100001]; //보이는 건물 중 가장 가까운 거리.
int can_watch[100001];
stack<pair<int, int> > st; //idx, height


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    memset(height, 0, sizeof(height));
    memset(ans, 0, sizeof(ans));
    memset(can_watch, 0, sizeof(can_watch));
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> height[i];
    
    //1바이트가 아닌 자료형의 memset은 0만 가능
    for(int i = 1; i <= N; i++) {
        dist[i] = 100001;
    }

    //SOLVE
    //건물에서 왼쪽 방향을 본다 가정하고 오른쪽 방향도 따로 해줘서 2번 for문을 돌림
    st.push(make_pair(1, height[1]));
    for(int i = 2; i <= N; i++) {
        while(1) {
            int l = st.top().first;
            int h = st.top().second;
            //자신보다 크다면 ans, dist 갱신
            if(h > height[i]) {
                ans[i] = l;
                dist[i] = i - l;
                can_watch[i] += st.size();
                st.push(make_pair(i, height[i]));
                break;
            } 
            //현재 건물의 높이보다 낮은 왼쪽 건물들은 어차피 현재 건물에게 다 가려질 예정이기에 pop해준다.
            else if(h <= height[i]) {
                st.pop();
                //비어있다면 현재 건물로 채워주기
                if(st.empty()) {
                    st.push(make_pair(i, height[i]));
                    break;
                }
            }
        }
    }
    
    //스택 클리어
    while(!st.empty()) st.pop();

    //오른쪽 방향을 본다 가정
    st.push(make_pair(N, height[N]));
    for(int i = N - 1; i >= 1; i--) {
        while(1) {
            int l = st.top().first;
            int h = st.top().second;
            //자신보다 크다면 왼쪽방향에서의 dist 확인 후 갱신
            if(h > height[i]) {
                if(dist[i] > l - i) {
                    ans[i] = l;
                    dist[i] = l - i;
                }
                can_watch[i] += st.size();
                st.push(make_pair(i, height[i]));
                break;
            } 
            //현재 건물의 높이보다 낮은 왼쪽 건물들은 어차피 현재 건물에게 다 가려질 예정이기에 pop해준다.
            else if(h <= height[i]) {
                st.pop();
                //비어있다면 현재 건물로 채워주기
                if(st.empty()) {
                    st.push(make_pair(i, height[i]));
                    break;
                }
            }
        }
    }

    // OUTPUT
    for(int i = 1; i <= N; i++) {
        if(can_watch[i] > 0) {
            cout << can_watch[i] << " " << ans[i] << endl;
        }
        else {
            cout << 0 << endl;
        }
    }

}
//100001개라는 큰 수라서 O(n)의 해결법을 찾아야 한다는 안일한 생각과
//스택을 사용해야한다는 것을 알고 나서도 좌측으로 한번 우측으로 한번 해야한다는 생각을 하지 못해 오래 걸린 문제다.
//+ memset에 대한 제한사항까지 배운 것이 많은 문제였다.