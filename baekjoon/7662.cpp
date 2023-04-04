#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int t, k, num; char order; 
    cin >> t;

    for(int i=0; i<t; i++){
        priority_queue<int, vector<int>, greater<int>> my_pq;
        cin >> k;
        for(int j=0; j<k; j++){
            cin >> order >> num;
            switch(order){
            case 'D':
                if(my_pq.empty())   break;
                else if(num==1){
                    my_pq.
                }else{
                    my_pq.pop();
                }
                break;
            case 'I':
                my_pq.push(num);
                break;
            }
        }
        if(my_pq.empty())   cout << "EMPTY\n";
        else                cout << my_pq.top() << ' ' <<
    }


    return 0;
}