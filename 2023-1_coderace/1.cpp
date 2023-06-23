#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m; vector<vector<int>> weapons; int time=0, prev_weapon=1000;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        vector<int> weapon;
        for(int j=0; j<m; j++){
            int temp;
            cin >> temp;
            weapon.push_back(temp);
        }
        weapons.push_back(weapon);
    }

    for(auto weapon :weapons){
        time += 
    }


    return 0;
}