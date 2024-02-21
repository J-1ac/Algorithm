#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve
    bfs 탐색
*/

int main(){
    int n, t1, t2, cnode; pair<int, int> edge[100001]; int parent[100001]={}; queue<int> q;
    cin >> n;
    for(int i=1; i<n; i++){
        cin >> t1 >> t2;
        edge[i] = make_pair(t1, t2);
    }

    q.push(1);

    while(!q.empty()){
        cnode = q.front();
        q.pop();
        for(int i=1; i<n; i++){
            if(edge[i].first == cnode && !parent[edge[i].second]){          //방문하지 않은 경우만 탐색
                q.push(edge[i].second);
                parent[edge[i].second] = cnode;
            }else if(edge[i].second == cnode && !parent[edge[i].first]){
                q.push(edge[i].first);
                parent[edge[i].first] = cnode;
            }
        }
    }

    for(int i=2; i<=n; i++){
        cout << parent[i] << "\n";
    }

    return 0;
}