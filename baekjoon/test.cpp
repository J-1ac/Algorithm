#include <bits/stdc++.h>
#include <iostream>
using namespace std;
pair<int,int> direction[4]={make_pair(0,-1), make_pair(0,1), make_pair(-1,0), make_pair(1,0)};                                      //up,down,left,right
vector<pair<int,int>> visited; int moves[100][100];

void my_move(pair<int,int> cxy, pair<int,int> gxy, const vector<string> &maze, int cmove){
    for(int i=0; i<visited.size(); i++){
        if(visited[i].first==cxy.first && visited[i].second==cxy.second && cmove>moves[cxy.second][cxy.first]) return;
    }
    visited.push_back(cxy);
    if(cxy.first<0 || cxy.second<0 || cxy.first>gxy.first || cxy.second>gxy.second || maze[cxy.second][cxy.first]=='0'){
        return;
    }else{
        moves[cxy.second][cxy.first]=cmove;
        for(int i=0; i<4; i++){
            my_move(make_pair(cxy.first+direction[i].first, cxy.second+direction[i].second), gxy, maze, cmove+1);
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<string> maze; string temp; pair<int,int> cxy=make_pair(0,0), gxy=make_pair(m-1,n-1);
    for(int i=0; i<n; i++){
        cin >> temp;
        maze.push_back(temp);
    }
    my_move(cxy, gxy, maze, 0);
    
    cout << moves[gxy.second][gxy.first]+1;

    return 0;
}