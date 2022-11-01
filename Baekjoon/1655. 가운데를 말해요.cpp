//https://www.acmicpc.net/problem/1655
//1655. 가운데를 말해요(Gold 2, 우선순위 큐)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <queue>

#define endl "\n"
#define INF 999999
#define ll long long

using namespace std;

int N;

int main()  
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    
    //SOLVE
    priority_queue<int> lq;
    priority_queue<int, vector<int>, greater<int> > rq;

    int tmp;
    for(int i = 1; i <= N; i++) {
        cin >> tmp;
        if(i % 2) {
            lq.push(tmp);
        } else {
            rq.push(tmp);
        }
        //lq의 top은 rq의 top보다 작거나 같아야 한다. 아니라면 swap
        if(i != 1 && lq.top() > rq.top()) {
            int a = lq.top();
            int b = rq.top();
            lq.pop();
            rq.pop();
            lq.push(b);
            rq.push(a);
        }
        cout << lq.top() << endl;
    }
    //OUTPUT
    
}
//구현으로 엄청 잘 풀었다고 생각했는데 자료구조 안쓰면 틀리라는 의도로 시간 제한을 엄격하게 둔 듯하다
//최대 힙 최소 힙을 양쪽에 두고 중간값을 빠르게 정렬하는 방식