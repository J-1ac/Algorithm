#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n, temp, a, b, sum=0; priority_queue<int, vector<int>, greater<int>> my_pq;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        my_pq.push(temp);
    }
    
    if(n==1) cout << 0;
    else{
        while(my_pq.size()!=1){
            a=my_pq.top();
            my_pq.pop();
            b=my_pq.top();
            my_pq.pop();
            my_pq.push(a+b);
            if(my_pq.size()>1) sum+=a+b;
        }

        cout << my_pq.top()+sum;
    }

    return 0;

}