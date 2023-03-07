#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n, m, v1, v2, cc=0;
    cin >> n >> m;
    int vertices[n]{}; vector<pair<int,int>> edges;
    for(int i=0; i<m; i++){
        cin >> v1 >> v2;
        edges.push_back(make_pair(v1, v2));
    }

    for(int i=0; i<n; i++){
        if(vertices[i]==0){
            cc++; queue<int> vincc;
            vincc.push(i+1);
            while(!vincc.empty()){
                int cv=vincc.front();
                vincc.pop();
                if(vertices[cv-1]==0){
                    vertices[cv-1]=1;
                    for(pair<int,int>edge :edges){
                        if(edge.first==cv && vertices[edge.second-1]==0) vincc.push(edge.second);
                        else if(edge.second==cv && vertices[edge.first-1]==0) vincc.push(edge.first);
                    }
                }
            }
        }
    }

    cout << cc;

    return 0;
}