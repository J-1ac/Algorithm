#include <bits/stdc++.h>
#include <iostream>
using namespace std;
pair<int,int> d[4]={make_pair(0,-1), make_pair(0,1), make_pair(-1,0), make_pair(1,0)};                                      //up,down,left,right

int main(){
    queue<vector<int>> myq;                                                                                                 //x,y,time
    
    int m, n, temp, mtime=0; bool isallriped=true;
    cin >> m >> n;
    int tomatoes[n+1][m+1]{}, visited[n+1][m+1]{};
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> temp;
            tomatoes[i][j]=temp;
            if(temp==1) {
                myq.push({i, j, 0});
                visited[n][m]=1;
            }
        }
    }

    while(!myq.empty()){
        vector<int> ctomato=myq.front();
        myq.pop();
        tomatoes[ctomato[0]][ctomato[1]]=1;
        
        for(int i=0; i<4; i++){
            vector<int> nexttomato={ctomato[0]+d[i].first, ctomato[1]+d[i].second, ctomato[2]+1};
            if(nexttomato[0]>=0 && nexttomato[1]>=0 && nexttomato[0]<n && nexttomato[1]<m && tomatoes[nexttomato[0]][nexttomato[1]]==0 && visited[nexttomato[0]][nexttomato[1]]!=1){
                myq.push(nexttomato);
                visited[nexttomato[0]][nexttomato[1]]=1;
                if(mtime<nexttomato[2]) mtime=nexttomato[2];
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(tomatoes[i][j]==0){
                isallriped=false;
                break;
            }
        }
    }

    if(isallriped)  cout << mtime;
    else            cout << "-1";

    return 0;
}