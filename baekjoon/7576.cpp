#include <bits/stdc++.h>
#include <iostream>
using namespace std;
pair<int,int> d[4]={make_pair(0,-1), make_pair(0,1), make_pair(-1,0), make_pair(1,0)};                                      //up,down,left,right

int main(){
    queue<vector<int>> myq;                                                                                                 //x,y,time
    vector<pair<int,int>> visited;
    int m, n, temp, mtime=0; bool isallmyq=true;
    cin >> m >> n;
    int tomatoes[n][m];
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> temp;
            tomatoes[i][j]=temp;
            if(temp==1) {
                myq.push({i, j, 0});
                visited.push_back(make_pair(i, j));
            }
        }
    }

    while(!myq.empty()){
        vector<int> ctomato=myq.front();
        myq.pop();
        tomatoes[ctomato[0]][ctomato[1]]=1;
        cout << "-----------------------\nctomato : " << ctomato[0] << " , " << ctomato[1] << " time: " << ctomato[2] << "\n";
        
        for(int i=0; i<4; i++){
            bool isvisited=false;
            vector<int> nexttomato={ctomato[0]+d[i].first, ctomato[1]+d[i].second, ctomato[2]+1};
            cout << "nexttomato : " << nexttomato[0] << " , " << nexttomato[1] << " time: " << nexttomato[2] << "\n";
            if(nexttomato[0]>=0 && nexttomato[1]>=0 && nexttomato[0]<n && nexttomato[1]<m && tomatoes[nexttomato[0]][nexttomato[1]]==0){
                for(int i=0; i<visited.size(); i++){
                    if(visited[i].first==nexttomato[0] && visited[i].second==nexttomato[1]){
                        isvisited=true;
                        break;
                    }
                }
                if(!isvisited) {
                    cout << "pused : " << nexttomato[0] << " , " << nexttomato[1] << "\n";
                    myq.push(nexttomato);
                    visited.push_back(make_pair(nexttomato[0], nexttomato[1]));
                    if(mtime<nexttomato[2]) mtime=nexttomato[2];
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tomatoes[i][j]==0){
                isallmyq=false;
                break;
            }
        }
    }

    if(isallmyq)  cout << mtime;
    else            cout << "-1";

    return 0;
}