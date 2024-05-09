#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    위상정렬 + dp
*/

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n, k, w, x, y, times[1001]{}, dp[1001]{};
        vector<int> inDegree;
        vector<vector<int>> graph;
        queue<int> q;

        cin >> n >> k;
        inDegree.assign(n+1, 0);
        graph.assign(n+1, vector<int>(0,0));

        for(int j=1; j<=n; j++){
            cin >> times[j];
            dp[j] = times[j];
        }
        for(int j=0; j<k; j++){
            cin >> x >> y;
            graph[x].push_back(y);
            inDegree[y]++;
        }

        cin >> w;

        // 위상 정렬 진행하며 dp로 cost 계산
        for(int j=1; j<=n; j++){
            if(inDegree[j]==0) q.push(j);
        }

        while(!q.empty()){
            int cur = q.front();
            q.pop();
            for(int j=0; j<graph[cur].size(); j++){
                int next = graph[cur][j];
                dp[next] = max(dp[next], dp[cur] + times[next]);
                if(--inDegree[next] == 0) q.push(next);
            }
        }

        cout << dp[w] << endl;

    }

    return 0;
}