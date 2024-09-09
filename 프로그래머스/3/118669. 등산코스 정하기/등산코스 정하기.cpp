#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 100000000

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    
    vector<vector<pair<int, int>>> graph(n+1); //<vertex, weight>
    vector<int> intensity(n+1, INF);
    int min_intensity = INF, min_summit = INF;
    
    //그래프 작성
    for(int i = 0; i < paths.size(); i++) {
        graph[paths[i][0]].push_back({paths[i][1], paths[i][2]});
        graph[paths[i][1]].push_back({paths[i][0], paths[i][2]});
    }
    
    //다익스트라 - 우리는 최소 intensity와 봉우리 번호만 필요하기 때문에 시작지점 다 pq에 넣어주고 시작, 아니면 시간초과
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    
    for(int i = 0; i < gates.size(); i++) {
        pq.push({0, gates[i]});
        intensity[gates[i]] = 0;
    }
    
    while(!pq.empty()) {
        
        int inten = pq.top().first;
        int cv = pq.top().second;
        pq.pop();
        
        //산봉우리 도착 시 최소값 갱신하고 continue
        if(find(summits.begin(), summits.end(), cv) != summits.end()) {
            if(intensity[cv] < min_intensity) {
                min_intensity = intensity[cv];
                min_summit = cv;
            }
            //intensity는 같고 산봉우리가 다른 경우
            if(intensity[cv] == min_intensity && cv < min_summit) {
                min_summit = cv;
            }
            continue;
        }
        
        for(int i = 0; i < graph[cv].size(); i++) {
            int nv = graph[cv][i].first;
            int w = graph[cv][i].second;
            
            if(intensity[nv] > max(inten, w)) {
                intensity[nv] = max(inten, w);
                pq.push({intensity[nv], nv});
            }
        }
    }
    
    answer = {min_summit, min_intensity};
    
    return answer;
}

//갔다 오는 걸 고려하지 말고 가는 경로에서 intensity 작은 걸 골라주자
//다익스트라 사용하는데 최단 거리말고 현재 지점까지 오는데 걸리는 최소 intensity로 치환해서 구해주자
//모든 시작점에 대해서 다익스트라 돌리면 시간초과 -> 최소 intensity와 봉우리만 중요하니 pq에 모든 시작점 한번에 넣기