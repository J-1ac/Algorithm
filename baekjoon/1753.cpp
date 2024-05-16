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





    for(int i=1; i<=v; i++){
        if(ans[i]==-1) cout << "INF\n";
        else           cout << ans[i] << '\n'; 
    }





    return 0;
}