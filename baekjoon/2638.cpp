#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    bfs, 구현
    1. 공기가 통하는지 판별
    2. 1시간 동안 녹는 치즈 판별
    더 이상 치즈가 남아있지 않을때까지 반복.
*/

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int myMap[100][100], airMap[100][100], t;
queue<pair<int,int>> q, airq;

bool isValid(const pair<int,int> &xy, const int &n , const int &m){
    if(xy.first>=0 && xy.first<n && xy.second>=0 && xy.second<m)    return true;
    else                                                            return false;
}

void cal(int n, int m, queue<pair<int,int>> &q){    
    airq.push({0,0});
    airMap[0][0]=1;

    while(!q.empty()){
        // 공기가 통하는지 판별
        while(!airq.empty()){
            pair<int,int> air_current = airq.front();
            airq.pop();
            airMap[air_current.first][air_current.second]=1;
            for(int i=0; i<4; i++){
                pair<int,int> air_next = {air_current.first+dx[i], air_current.second+dy[i]};
                if(isValid(air_next, n, m) && !airMap[air_next.first][air_next.second] && myMap[air_next.first][air_next.second]==0){
                    airMap[air_next.first][air_next.second]=1;
                    airq.push(air_next);
                }
            }
        }

        // 1시간 단위 녹는 치즈 판별
        int qsize = q.size();
        t++;
        for(int i=0; i<qsize; i++){
            int air=0;
            pair<int, int> current = q.front();
            q.pop();
            for(int j=0; j<4; j++){
                pair<int, int> near = {current.first+dx[j], current.second+dy[j]};
                if(isValid(near, n, m) && airMap[near.first][near.second]==1) air++;
            }
            if(air<2)   q.push(current);
            else{
                myMap[current.first][current.second]=0;
                airq.push(current);
            }   
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> myMap[i][j];
            if(myMap[i][j]==1){
                q.push({i, j});
            } 
        }
    }

    cal(n, m, q);

    cout << t;

    return 0;
}