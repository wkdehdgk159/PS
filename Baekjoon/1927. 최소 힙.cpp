//https://www.acmicpc.net/problem/1927
//1927. 최소 힙(Silver 2, Heap)

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

#define endl "\n"
#define INF 999999999
using namespace std;

int N;
int node[100001];
int h_size = 0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> N;
    memset(node, 0, sizeof(node));

    //SOLVE
    int x, curr, parent, tmp;
    for(int i = 0;  i < N; i++) {
        cin >> x;
        //POP & REMOVE
        if(x == 0) {
            if(h_size == 0) {
                cout << 0 << endl;
            }
            else {
                cout << node[1] << endl;
                curr = 1;
                node[curr] = node[h_size];
                node[h_size] = 0;
                h_size--;
                while(curr < h_size) {
                    int min_idx;
                    if(curr * 2 + 1 <= h_size) {
                        min_idx = node[curr * 2] < node[curr * 2 + 1] ? curr * 2 : curr * 2 + 1;
                    } else if(curr * 2 <= h_size) {
                        min_idx = curr * 2;
                    }
                    if(node[curr] > node[min_idx]) {
                        tmp = node[curr];
                        node[curr] = node[min_idx];
                        node[min_idx] = tmp;
                        curr = min_idx;
                    }
                    else {
                        break;
                    }
                }
            }
        }
        //INSERT
        else {
            curr = ++h_size;
            node[curr] = x;
            while(curr > 1) {
                parent = curr / 2;
                if(node[parent] > node[curr]) {
                    tmp = node[curr];
                    node[curr] = node[parent];
                    node[parent] = tmp;
                    curr = parent;
                }
                else {
                    break;
                }
            }
        }
    }
    
    //OUTPUT
}