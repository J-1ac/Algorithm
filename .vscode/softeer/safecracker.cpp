#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int w, n, m, p;
vector<pair<int,int>> cost;

struct mycmp {
    bool operator()(pair<int,int> a, pair<int,int> b) {
        return a.second > b.second;
    }
};

int main(int argc, char** argv){

    cin >> w >> n;

    for(int i=0; i<n; i++){
        cin >> m >> p;
        cost.push_back({m,p});
    }

    sort(cost.begin(), cost.end(), mycmp());

    int space=w, index=0, maxCost=0;
    while(space > 0){
        if(space >= cost[index].first){        // 현재 귀금속 모두 넣을 수 있는 경우
            maxCost += cost[index].first * cost[index].second;
            space -= cost[index].first;
        }else{                                          // 쪼개서 넣어야 하는 경우
            maxCost += space * cost[index].second;
            break;
        }
        index ++;
    }

    cout << maxCost;

    return 0;
}