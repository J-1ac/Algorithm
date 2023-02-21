#include <bits/stdc++.h>
using namespace std;

void add_newvertex(int v1, int v2, vector<int> &v_list){
    vector<int>::iterator p1 = find(v_list.begin(), v_list.end(), v1);
    vector<int>::iterator p2 = find(v_list.begin(), v_list.end(), v2);
    if(p1 == v_list.end()) v_list.push_back(v1);
    if(p2 == v_list.end()) v_list.push_back(v2);
}

void add_newedge(int v1, int v2, vector<pair<int,int>> &e_list){
    pair<int,int> newedge = make_pair(v1,v2);
    e_list.push_back(newedge);
}

void dfs(vector<int> &vertics, vector<pair<int,int>> &edges){

}

void bfs(vector<int> &vertics, vector<pair<int,int>> &edges){

}

int main(){
    int n, m, v, vertex1, vertex2;
    vector<int> vertics; vector<pair<int,int>> edges;
    cin >> n >> m >> v;
    
    for(int i=0; i<m; i++){
        cin >> vertex1 >> vertex2;
        add_newvertex(vertex1, vertex2, vertics);
        add_newedge(vertex1, vertex2, edges);
    }

    dfs(vertics, edges);
    bfs(vertics, edges);

    return 0;
}