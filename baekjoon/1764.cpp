#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//map활용 예제

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; map<string, int> nohear, nohearnsee; string name;
    cin >> n >> m;
    
    for(int i=0; i<n; ++i){
        cin >> name;
        nohear.insert({name, i});
    }

    for(int i=0; i<m; ++i){
        cin >> name;
        if(nohear.find(name)!=nohear.end()) nohearnsee.insert({name, i});
    }
    
    cout << nohearnsee.size() << '\n';
    for(auto it=nohearnsee.begin(); it!=nohearnsee.end(); it++) cout << it->first << '\n';

    return 0;
}