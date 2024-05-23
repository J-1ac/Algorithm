#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/** how to solve 
 * 각 정점에서 x까지 최단 경로 다익스트라
 * x에서 각 정점까지 최단 경로 다익스트라
 * 총 n번의 다익스트라 진행
*/


int main(){
    int n, m, x, start, end, weight;
    cin >> n >> m >> x;
    vector<pair<int, int>> graph[n+1]; int visited[n+1]{}, distanceToX[n+1]{}, distanceFromX[n+1]{}, distanceSum[n+1]{};
    for(int i=0; i<m; i++){
        cin >> start >> end >> weight;
        graph[start].push_back({end, weight});
    }

    // 각 정점에서 x까지 최단 경로 다익스트라
    for(int i=1; i<=n; i++){
        if(i==x) continue;
        
        for(int j=1; j<=n; j++){
            if(j==i) visited[j]=0;
            else     visited[j]=-1;
        }

        // 다익스트라
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, i});

        while (!pq.empty()) {
            int u = pq.top().second;
            int dist = pq.top().first;
            pq.pop();

            if (u==x){                      // x까지 최단 경로를 구한 경우 break
                distanceToX[i]=dist;
                break;
            }

            if (dist > visited[u]) continue; // 더 짧은 경로가 있는 경우 skip

            for (auto& neighbor : graph[u]) {
                int v = neighbor.first;
                int w = neighbor.second;

                if (visited[v] == -1 || visited[u] + w < visited[v]) {
                    visited[v] = visited[u] + w;
                    pq.push({visited[v], v});
                }
            }
        }
    }

    // x에서 각 정점 최단 경로 다익스트라
    for(int i=1; i<=n; i++){
        if(i==x) distanceFromX[i]=0;
        else     distanceFromX[i]=-1;
    }

    // 다익스트라
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, x});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > distanceFromX[u]) continue; // 더 짧은 경로가 있는 경우 skip

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (distanceFromX[v] == -1 || distanceFromX[u] + w < distanceFromX[v]) {
                distanceFromX[v] = distanceFromX[u] + w;
                pq.push({distanceFromX[v], v});
            }
        }
    }

    for(int i=1; i<=n; i++){
        distanceSum[i] = distanceToX[i] + distanceFromX[i];
    }

    cout << *max_element(distanceSum, distanceSum + n + 1); 

    


    return 0;
}