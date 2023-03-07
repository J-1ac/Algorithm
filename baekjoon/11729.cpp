#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<pair<int, int>> my_hanoi;

void hanoi(int n){

}

int main(){
    int n;
    cin >> n;
 
    hanoi(n);

    cout << my_hanoi.size() << "\n";
    for(pair<int,int> phase: my_hanoi){
        cout << phase.first << ' ' << phase.second << "\n";
    }

    return 0;
}