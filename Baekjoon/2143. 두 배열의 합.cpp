//https://www.acmicpc.net/problem/2143
//2143. 두 배열의 합(Gold 3, 누적합)

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

int n, m, T;
//누적합 저장
vector<ll> psA;
vector<ll> psB;
int arrA[1001];
int arrB[1001];

//일반적인 이분탐색이라면 end index값을 size-1로 잡아야 하겠지만
    //1. 모든 원소가 t 이하일 때 ub가 size를 값으로 가지도록 의도하였고
    //2. mid가 size와 같아질 수 없으므로 segfault를 일으킬 위험성이 없다
int ub(int t, int size) {
    int low = 0, high = size;
    while(low < high) {
        int mid = (low + high) / 2;
        if(psB[mid] > t) high = mid;
        else low = mid + 1;
    }
    return high + 1;
}
int lb(int t, int size) {
    int low = 0, high = size;
    while(low < high) {
        int mid = (low + high) / 2;
        if(psB[mid] >= t) high = mid;
        else low = mid + 1;
    }
    return high + 1;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);

    //INPUT
    cin >> T;
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> arrA[i];
    cin >> m;
    for(int i = 1; i <= m; i++) cin >> arrB[i];

    //SOLVE
    //누적합 계산
    for(int i = 1; i <= n; i++) {
        ll sum = 0;
        for(int j = i; j <= n; j++) {
            sum += arrA[j];
            psA.push_back(sum);
        }
    }
    for(int i = 1; i <= m; i++) {
        ll sum = 0;
        for(int j = i; j <= m; j++) {
            sum += arrB[j];
            psB.push_back(sum);
        }
    }

    sort(psB.begin(), psB.end());

    ll ans = 0;
    ll ans2 = 0;
    for(int i = 0; i < psA.size(); i++) {
        // <algorithm> 헤더에서 아래처럼 사용도 가능
        // int lb = lower_bound(psB.begin(), psB.end(), T - psA[i]) - psB.begin();
        // int ub = upper_bound(psB.begin(), psB.end(), T - psA[i]) - psB.begin();
        // ans += ub - lb;
        ans += ub(T-psA[i], psB.size()) - lb(T-psA[i], psB.size());
    }

    //OUTPUT
    cout << ans;
}