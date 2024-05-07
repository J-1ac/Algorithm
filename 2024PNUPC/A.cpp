#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x, s, c, p , max=0;
    cin >> n >> x >> s;

    vector<pair<int,int>> ins;

    for(int i=0; i<n; i++){
        cin >> c >> p;
        ins.push_back({c,p});
    }

    sort(ins.begin(), ins.end(), [](pair<int,int> &a, pair<int,int> &b){
                                      return a.second > b.second;
                                  });
    
    for(int i=0; i<n; i++){
        if(x>=ins[i].first){
            max = ins[i].second;
            break;
        }
    }

    if(max>s) cout << "YES";
    else      cout << "NO";
    

    return 0;
}