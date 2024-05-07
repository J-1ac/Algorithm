#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/**
 * 상하좌우로 감염
 * 건물 o -> tb시간 이후 감염
 * 건물 x -> 1시간 이후 감염
 * 빈곳 0
 * 건물 1
 * 감염 -1
*/

int virusMap[1000][1000];
int r[4] = {1, -1, 0, 0};
int c[4] = {0, 0, -1, 1};
int survived;

void pass1H(queue<pair<int,int>> &virus, queue<array<int, 3>> &building, const int &n, const int &m, const int &tb){
    int qsize = virus.size();
    int bsize = building.size();

    for(int i=0; i<bsize; i++){
        array<int, 3> cb = building.front();
        building.pop();
        cb[2]--;
        if(cb[2]>0) building.push(cb);
        else{
            virusMap[cb[0]][cb[1]]=-1;
            virus.push({cb[0], cb[1]});
            survived--;
        }
    }

    for(int i=0; i<qsize; i++){
        pair<int,int> current = virus.front();
        virus.pop();
        for(int j=0; j<4; j++){
            int next_r = current.first+r[j];
            int next_c = current.second+c[j];
            if(next_r>=0 && next_r<n && next_c>=0 && next_c<m && virusMap[next_r][next_c]!=-1){
                if(virusMap[next_r][next_c]==0){
                    virusMap[next_r][next_c]=-1;
                    virus.push({next_r, next_c});
                    survived--;
                }else if(virusMap[next_r][next_c]==1){
                    building.push({next_r, next_c, tb});
                }
            }
        }
    }
}

int main(){
    cin.tie(nullptr); ios::sync_with_stdio(false);
    int n, m, tg, tb, x, b; char temp;
    cin >> n >> m >> tg >> tb >> x >> b;
    queue<pair<int,int>> virus;
    queue<array<int, 3>> building;
    survived=n*m;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> temp;
            if(temp == '*'){
                virusMap[i][j]=-1;
                virus.push({i, j});
                survived--;
            }
            if(temp == '#'){
                virusMap[i][j]=1;
            }
        }
    }

    for(int i=0; i<tg; i++){
        pass1H(virus, building, n, m, tb);
        if(survived<=0) break;
    }

    if(survived<=0) cout << -1;
    else{
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(virusMap[i][j]!=-1)  cout << i+1 << " " << j+1 << "\n";
            }
        }
    }

    return 0;
}