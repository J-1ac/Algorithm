#include <bits/stdc++.h>
#include <iostream>
using namespace std;
pair<int,int> direction[4]={make_pair(0,-1), make_pair(0,1), make_pair(-1,0), make_pair(1,0)};                                      //up,down,left,right
int moves[100][100]; int maze[100][100]; queue<pair<int,int>> myq;

void bfs_move(pair<int,int> gxy){
    moves[0][0]=1; 
    while(!myq.empty()){
        pair<int,int> cxy = myq.front();
        myq.pop();
        for(int i=0; i<4; i++){
            pair<int,int> nextxy=make_pair(cxy.first+direction[i].first, cxy.second+direction[i].second);
            if(nextxy.first>=0 && nextxy.second>=0 && nextxy.first<=gxy.first && nextxy.second<=gxy.second && maze[nextxy.second][nextxy.first]=='1' && !moves[nextxy.second][nextxy.first]){
                myq.push(nextxy);
                moves[nextxy.second][nextxy.first]=moves[cxy.second][cxy.first]+1;
            }
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    string temp; pair<int,int> cxy=make_pair(0,0), gxy=make_pair(m-1,n-1);
    for(int i=0; i<n; i++){
        cin >> temp;
        for(int j=0; j<m; j++){
            maze[i][j]=temp[j];
        }
    }

    myq.push(cxy);
    bfs_move(gxy);

    cout << moves[gxy.second][gxy.first];

    return 0;
}