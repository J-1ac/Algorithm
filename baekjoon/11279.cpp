#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, order; priority_queue<int, vector<int>, less<int>> my_pq;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> order;
        if(order==0){
            if(my_pq.empty()) cout << 0 << '\n';
            else{
                cout << my_pq.top() << '\n';
                my_pq.pop();
            }
        }else{
            my_pq.push(order);
        }
    }

    return 0;
}