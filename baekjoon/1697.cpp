#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int visited[100001]{}; queue<pair<int,int>> my_q;

void bfs_move(int x, int goal, int time){
    while(!my_q.empty()){
        int cx=my_q.front().first, ctime=my_q.front().second;
        my_q.pop();
        visited[cx]=1;
        if(cx==goal){
            cout << ctime;
            break;
        }
        if(cx-1>=0 && visited[cx-1]==0){
            my_q.push(make_pair(cx-1, ctime+1));
        }
        if(cx+1<=100000 && visited[cx+1]==0){
            my_q.push(make_pair(cx+1, ctime+1));
        }
        if(cx*2<=100000 && visited[cx*2]==0){
            my_q.push(make_pair(cx*2, ctime+1));
        }
    }
}


int main(){
    int n, k;
    cin >> n >> k;
    
    my_q.push(make_pair(n, 0));
    bfs_move(n, k, 0);

    return 0;
}