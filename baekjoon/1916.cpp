#include<bits/stdc++.h>
using namespace std;

int n, m, s, e, bs, be, c;
vector<vector<pair<int, int>>> graph;
vector<int> dist;

void dijkstra(){
    dist.assign(n+1, INT_MAX);
    dist[s] = 0;

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
    pq.push({0,s});

    while(!pq.empty()){
        int cost = pq.top().first;
        int current = pq.top().second;
        pq.pop();

        if(dist[current] < cost) continue;

        for(auto &edge : graph[current]){
            int next = edge.first;
            int nextDist = cost + edge.second;

            if(nextDist < dist[next]){
                dist[next] = nextDist;
                pq.push({nextDist, next});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    graph.resize(n + 1);

    for(int i=0; i<m; i++){
        cin >> bs >> be >> c;
        graph[bs].push_back({be, c});
    }

    cin >> s >> e;

    dijkstra();

    cout << dist[e];

    return 0;
}