#include <bits/stdc++.h>
#include <iostream>
using namespace std;
const pair<int,int> d[]={make_pair(1, 0), make_pair(-1, 0), make_pair(0, -1), make_pair(0, 1)};
//문제 접근 : bfs로 connected component 개수 파악하기.
//line28) 이미 방문했던 노드인지 확인 안한 경우 메모리초과 발생

int main(){
    int t, m, n, k, x, y;
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> m >> n >> k;
        int visited[m][n]{}, lands1[m][n]{}; vector<pair<int,int>> lands2; queue<pair<int,int>> my_q; int cc=0; 
        for(int i=0; i<k; i++){
            cin >> x >> y;
            lands1[x][y]=1;
            lands2.push_back(make_pair(x,y));
        }
        
        for(int i=0; i<lands2.size(); i++){
            pair<int,int> cxy=lands2[i];
            if(visited[cxy.first][cxy.second]==0){                                              //방문하지 않은 경우 bfs
                cc++;
                my_q.push(cxy);
                while(!my_q.empty()){
                    pair<int,int> bfs_xy=my_q.front();
                    my_q.pop();
                    if(visited[bfs_xy.first][bfs_xy.second]==1) continue;
                    else                                        visited[bfs_xy.first][bfs_xy.second]=1;
                    for(int i=0; i<4; i++){
                        pair<int,int> bfs_nextxy=make_pair(bfs_xy.first+d[i].first, bfs_xy.second+d[i].second);
                        if(visited[bfs_nextxy.first][bfs_nextxy.second]==0 && bfs_nextxy.first>=0 && bfs_nextxy.second>=0 && bfs_nextxy.first<m && bfs_nextxy.second<n && lands1[bfs_nextxy.first][bfs_nextxy.second]==1){
                            my_q.push(bfs_nextxy);
                        }
                    }
                }
            }
            else continue;
        }
        cout << cc << '\n';
    }

    return 0;
}