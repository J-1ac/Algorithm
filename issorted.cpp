#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n, temp, false_index; vector<int> result; bool is_sorted=true;
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> temp;
        result.push_back(temp);
    }

    for(int i=0; i<result.size()-1; i++){
        if(result[i]>result[i+1]){
            is_sorted=false;
            false_index=i;
            break;
        }
    }

    if(is_sorted) cout << "correct";
    else        cout << "miss: " << false_index;


    return 0;
}