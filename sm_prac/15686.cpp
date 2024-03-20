#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    backtracking 사용
*/
int get_distance(pair<int, int> p1, pair<int, int> p2){
    return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}

int main(){
    int n, m, temp, answer=0; vector<pair<int, int>> house, chicken; vector<vector<int>> chicken_distance;
    cin >> n >> m;
    int map[n][n]={};
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> temp;
            map[i][j]=temp;
            if(temp==1)         house.push_back(make_pair(i, j));
            else if(temp==2)    chicken.push_back(make_pair(i, j));
        }
    }

    for(int i=0; i<house.size(); i++){
        for(int j=0; j<chicken.size(); j++){
            //각 집별로 각 치킨집에 대한 치킨거리 연산.
        }
    }




    return 0;
}