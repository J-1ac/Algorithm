#include <bits/stdc++.h>
using namespace std;
vector<int> dfs_visited, dfs_result;

void dfs(const vector<int> tree[], int node){
    auto is_visited = find(dfs_visited.begin(), dfs_visited.end(), node);
    if (is_visited==dfs_visited.end()){
        dfs_visited.push_back(node);
        dfs_result.push_back(node);
    } else return;
    for(int i=0; i<tree[node].size(); i++){
        int next_node = tree[node][i];
        dfs(tree, next_node);
    }
}

void bfs(const vector<int> tree[], int root){

}

int main(){
    int n, m, v, vertex1, vertex2;
    cin >> n >> m >> v;
    vector<int> mytree[n+1];
    
    for(int i=0; i<m; i++){
        cin >> vertex1 >> vertex2;
        mytree[vertex1].push_back(vertex2);
        mytree[vertex2].push_back(vertex1);
    }

    for(int i=1; i<=n; i++) sort(mytree[i].begin(), mytree[i].end());

    dfs(mytree, v);
    for (int v:dfs_result) cout << v << ' ';
    cout << "\n";
    bfs(mytree, v);

    return 0;
}