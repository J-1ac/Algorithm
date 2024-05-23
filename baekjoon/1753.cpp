#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/** how to solve 
 * 다익스트라
*/


int main(){
    int v, e, s;
    cin >> v >> e >> s;
    vector<pair<int, int>> graph[v+1]; int ans[v+1];

    for(int i=0; i<e; i++){
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back(make_pair(v, w));
    }

    for(int i=1; i<=v; i++){
        if(i==s) ans[i]=0;
        else     ans[i]=-1;
    }

    // 다익스트라
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, s});

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (dist > ans[u]) continue; // 더 짧은 경로가 있는 경우 skip

        for (auto& neighbor : graph[u]) {
            int v = neighbor.first;
            int w = neighbor.second;

            if (ans[v] == -1 || ans[u] + w < ans[v]) {
                ans[v] = ans[u] + w;
                pq.push({ans[v], v});
            }
        }
    }

    for(int i=1; i<=v; i++){
        if(ans[i]==-1) cout << "INF\n";
        else           cout << ans[i] << '\n'; 
    }

    return 0;
}