#include<bits/stdc++.h>
using namespace std;

int n;
int area[20][20];
int myMin = INT_MAX;

void getStat(vector<int>& newarr){
    int team1 = 0, team2 = 0, sub;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            bool i_in_newarr = std::find(newarr.begin(), newarr.end(), i) != newarr.end();
            bool j_in_newarr = std::find(newarr.begin(), newarr.end(), j) != newarr.end();

            if (i_in_newarr && j_in_newarr) {
                team1 += area[i][j];
            } else if (!i_in_newarr && !j_in_newarr) {
                team2 += area[i][j];
            }
        }
    }

    sub = abs(team1-team2);
    if(sub<myMin) myMin =sub;
}

void combination(int start, int size, vector<int>& newarr) {
    if (newarr.size() == size) {
        getStat(newarr);
        return;
    }

    for (int i = start; i < n; i++) {
        newarr.push_back(i);
        combination(i + 1, size, newarr);
        newarr.pop_back();
    }
}


int main(){

    cin >> n;

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> area[i][j];
        }
    }

    vector<int> newarr;

    // 가능한 조합 구해서 능력치의 차이값 구하기, min보다 작으면 update
    combination(0, n/2, newarr);

    cout << myMin;

    return 0;
}