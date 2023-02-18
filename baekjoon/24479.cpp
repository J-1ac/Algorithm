#include <bits/stdc++.h>
using namespace std;
bool visited[100001];
vector<int> graph[100001];
int visited_order[100001];
int cnt=0;

bool compare(int a, int b){
    return a > b;
}

void dfs(int node){
    if (!visited[node]){
        visited[node]=true;
        visited_order[node] = ++cnt;
    } else return;
    for(int i=0; i<graph[node].size(); i++){
        int next_node = graph[node][i];
        if(!visited[next_node]) dfs(next_node);
    }
}
int main(void){
    int n,m,r;
    cin >> n >> m >> r;
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) sort(graph[i].begin(), graph[i].end(), compare);

    dfs(r);

    for(int i=1; i<=n; i++) cout << visited_order[i] << '\n';
    
    return 0;
}