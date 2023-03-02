#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n, m, b, temp, time=1000000000, top_level, maxh;
    cin >> n >> m >> b;
    vector<int> lands;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> temp;
            maxh+=temp;
            lands.push_back(temp);
        }
    }
    sort(lands.begin(), lands.end());
    maxh+=b; maxh=maxh/(n*m);
    for(int target=0; target<=maxh; target++){
        int ctime=0, hand=b; bool ispossible=true;

        for(int land: lands){
            if(land>target){
                hand+=land-target;
                ctime+=2*(land-target);
            }else if(land<target){
                hand-=target-land;
                ctime+=target-land;
            }
            if(ctime>time){
                ispossible=false;
                break;
            }
        }
        if(hand<0) ispossible=false;
        if(!ispossible) continue;
        if (ctime<time){
            top_level=target;
            time=ctime;
        }
        if(ctime==time && target>top_level){
            top_level=target;
        }
    }

    cout << time << " " << top_level;

    return 0;
}

/// lands 원소만 생각하는게 아닌 다른 경우도 찾아보기 중간값에서도 정답이 나올수있음