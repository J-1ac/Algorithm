#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n, num, cp, cs, cm, cd; vector<int> an;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> num;
        an.push_back(num);   
    }
    cin >> cp >> cs >> cm >> cd;

    for(int i=0; i<n; i++){
        cout << an[i] << " ";   
    }

    cout << "\n" << cp << " " <<  cs << " " <<  cm << " " << cd;
    
    return 0;
}