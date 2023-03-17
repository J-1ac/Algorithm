#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n, temp, missnum1, missnum2; vector<int> result1, result2; bool is_same=true;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;
        result1.push_back(temp);
    }
    
    for(int i=0; i<n; i++){
        cin >> temp;
        result2.push_back(temp);
    }

    for(int i=0; i<n; i++){
        if(result1[i]!=result2[i]){
            is_same=false; missnum1=result1[i]; missnum2=result2[i]; 
            break;
        }
    }

    if(is_same) cout << "correct";
    else        cout << "miss: " << missnum1 << " , " << missnum2;

    return 0;
}