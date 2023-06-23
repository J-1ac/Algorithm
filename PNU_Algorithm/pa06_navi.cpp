#include <bits/stdc++.h>
#include <iostream>
using namespace std;

pair<int,int> dir[4]={make_pair(-1,0), make_pair(1,0), make_pair(0,-1), make_pair(0,1)};

struct node{
    int x;
    int y;
    int f;
    int h;
};

struct mycompare{
    bool operator()(node a, node b){
        return a.f+a.h > b.f+b.h;
    }
};

int main(){
    int m, n, num_0, s_x, s_y, t_x, t_y, num_ob; string garbage; priority_queue<node, vector<node>, mycompare> mypq;
    cin >> m >> n >> num_0;
    pair<int, int> maps[m][n]{};                                                                    //maps) first: -1 for obstacle, 0 for unvisited, other for f / second: h(uclide distance)
    for(int i=0; i<num_0; i++){
        int x, y;
        cin >> garbage >> x >> y;
        maps[x][y].first=-1;
    }
    cin >> garbage >> s_x >> s_y >> garbage >> t_x >> t_y >> garbage >> num_ob;

    for(int i=0; i<num_ob; i++){                                                                    //filling obstacle in maps
        int p1_x, p1_y, p2_x, p2_y;
        cin >> p1_x >> p1_y >> p2_x >> p2_y;
        if(p1_x>p2_x) swap(p1_x, p2_x);
        if(p1_y>p2_y) swap(p1_y, p2_y);
        for(int i=p1_x; i<=p2_x; i++){
            for(int j=p1_y; j<=p2_y; j++){
                maps[i][j].first=-1;
            }
        }
    }

    for(int j=0; j<n; j++){                                                                         //get h by uclide
        for(int i=0; i<m; i++){ 
            maps[i][j].second = sqrt(pow(3*(t_x-i), 2) + pow(3*(t_y-j), 2));
        }
    }
    
    mypq.push({s_x, s_y, 0, maps[s_x][s_y].second});

    while(!mypq.empty()){                                                                           //Astar algorithm
        struct node cnode=mypq.top();
        mypq.pop();
        if(maps[cnode.x][cnode.y].first!=0) continue;                                               //if visited or obstacle continue

        maps[cnode.x][cnode.y].first=cnode.f;                                                       //update f

        if(cnode.x==t_x && cnode.y==t_y) break;                                                     //if get goal's f, break
        else{                                                                                       //else, push neighbor node
            for(int i=0; i<4; i++){
                pair<int,int> next_node{cnode.x+dir[i].first, cnode.y+dir[i].second};               
                if(next_node.first<0 || next_node.second<0 || next_node.first>=m || next_node.second>=n) 
                    continue;                                                                  //if next_node off the maps, continue
                if(maps[next_node.first][next_node.second].first!=-1) 
                    mypq.push({next_node.first, next_node.second, cnode.f+3, maps[next_node.first][next_node.second].second});
            }
        }
    }

    cout << maps[t_x][t_y].first << endl;

    return 0;
}