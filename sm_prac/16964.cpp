#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve         unsolved.
    dfs 사용
*/

int visit[100001]={}; 
queue<int> ins; vector<int> edges[100001]={};

bool dfs(int x){
    /**
     * 1. 부모가 visited 인지 확인.
    */
    if(visit[x] == true){
        return 1;
    }
    visit[x] = true;
    //
    for(int y=0; y<edges[x].size(); y++){
        if(visit[edges[x][y]] == false){
            dfs(edges[x][y]);
        }
    }
}

int main(){
    int N, n1, n2, temp;
    cin >> N;
    for(int i=0; i<N-1; i++){
        cin >> n1 >> n2;
        edges[n1].push_back(n2);
        edges[n2].push_back(n1);
    }
    for(int i=0; i<N; i++){
        cin >> temp;
        ins.push(temp);
    }

    if(ins.front()!=1){
        cout << 0;
    }else{
        ins.pop(); 
        if(dfs(1)) cout << 1;
        else       cout << 0;
    }

    return 0;
}