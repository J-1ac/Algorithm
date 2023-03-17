#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool my_compare(pair<int,int> a, pair<int,int> b){
    return a.first<b.first;
}

int main(){
    int n, temp; vector<pair<int,int>> before_x; 
    cin >> n;
    int ans[n]{};

    for(int i=0; i<n; i++){
        cin >> temp;
        before_x.push_back(make_pair(temp, i));
    }

    sort(before_x.begin(), before_x.end(), my_compare);

    int cnt=0, pre_x=before_x[0].first;

    for(int i=0; i<n; i++){
        if(pre_x<before_x[i].first) cnt++;
        ans[before_x[i].second]=cnt;
        pre_x=before_x[i].first;
    }

    for(int i=0; i<n; i++) cout << ans[i] << ' ';

    return 0;
}