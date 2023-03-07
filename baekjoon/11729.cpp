#include <bits/stdc++.h>
#include <iostream>
using namespace std;
vector<pair<int, int>> my_hanoi;

void hanoi(int n, int from, int by, int to){
    if(n==0) return;
    hanoi(n-1, from, to, by);
    my_hanoi.push_back(make_pair(from, to));
    hanoi(n-1, by, from, to);
}

int main(){
    int n;
    cin >> n;
 
    hanoi(n, 1, 2, 3);

    cout << my_hanoi.size() << "\n";
    for(pair<int,int> phase: my_hanoi){
        cout << phase.first << ' ' << phase.second << "\n";
    }

    return 0;
}