#include <bits/stdc++.h>
using namespace std;

bool visited[100001];
vector<int> graph[100001];
queue<int> q;
int visited_order[100001];
int cnt=0;

bool compare(int a, int b){
    return a < b;
}

void bfs(int node){
    visited[node]=true;
    q.push(node);
    visited_order[node]=++cnt;
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        for(int i=0; i<graph[u].size(); i++){
            int next_node = graph[u][i];
            if(!visited[next_node]){
                visited[next_node]=true;
                q.push(next_node);
                visited_order[next_node]=++cnt;
            }
        }
        cout << "size of queue: " << q.size() << endl;
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

    bfs(r);

    for(int i=1; i<=n; i++) cout << visited_order[i] << '\n';
    
    return 0;
}