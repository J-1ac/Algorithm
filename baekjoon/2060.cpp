#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n, edge_n, a, b, cnode; vector<pair<int, int>> edges; queue<int> my_q; vector<int> visited;
    cin >> n >> edge_n;

    for(int i=0; i<edge_n; i++){
        cin >> a >> b;
        edges.push_back(make_pair(a, b));
        if(a==1) my_q.push(b);
        if(b==1) my_q.push(a);
    }

    while(!my_q.empty()){
        cnode = my_q.front();
        my_q.pop();
        if(find(visited.begin(), visited.end(), cnode)==visited.end()){
            visited.push_back(cnode);
            for(int i=0; i<edges.size(); i++){
                if(edges[i].first==cnode && find(visited.begin(), visited.end(), edges[i].second)==visited.end()) my_q.push(edges[i].second);
                if(edges[i].second==cnode && find(visited.begin(), visited.end(), edges[i].first)==visited.end()) my_q.push(edges[i].first);
            }
        }
    }

    if(visited.size()>=2) cout << visited.size()-1;
    else                  cout << 0;

    return 0;
}