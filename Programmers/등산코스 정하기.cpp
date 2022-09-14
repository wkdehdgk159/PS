//https://school.programmers.co.kr/learn/courses/30/lessons/118669
//등산코스 정하기 (Level 3, 다익스트라)

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

#define INF 90000000

using namespace std;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;

    vector<vector<pair<int, int>>> graph(n + 1); //<vertex, weight>
    vector<int> intensity(n + 1, INF);

    int min_intensity = INF;
    int min_summit = INF;

    //make graph
    for(int i = 0; i < paths.size(); i++) {
        int v1 = paths[i][0];
        int v2 = paths[i][1];
        int d = paths[i][2];

        graph[v1].push_back(make_pair(v2, d));
        graph[v2].push_back(make_pair(v1, d));
    }

    for(int i = 0; i < gates.size(); i++) {
        intensity[gates[i]] = 0;
    }

    //Dijkstra
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for(int i = 0; i < gates.size(); i++) {
        pq.push(make_pair(intensity[gates[i]], gates[i]));
    }
    int size = gates.size();

    while(!pq.empty()) {
        int inten = pq.top().first;
        int curr = pq.top().second;
        pq.pop();

        //산봉우리에 도착했다면 최소값 갱신 후 continue
        if(find(summits.begin(), summits.end(), curr) != summits.end()) {
                if(intensity[curr] < min_intensity) {
                    min_intensity = intensity[curr];
                    min_summit = curr;
                }
                if(intensity[curr] == min_intensity && curr < min_summit) {
                    min_summit = curr;
                }
                continue;
        }

        for(int i = 0; i < graph[curr].size(); i++) {
            int v = graph[curr][i].first;
            int w = graph[curr][i].second;

            if(intensity[v] > max(inten, w)) {
                intensity[v] = max(inten, w);
                pq.push(make_pair(intensity[v], v));
            }
        }
    }
    answer.push_back(min_summit);
    answer.push_back(intensity[min_summit]);
    return answer;
}

//weight가 아닌 intensity를 갱신시키는 다익스트라