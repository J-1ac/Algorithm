#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base :: sync_with_stdio(false); 
    cin.tie(NULL); 
    cout.tie(NULL);
    int n, s, e, q, t; vector<int> time; vector<int> using_time;
    
    cin >> n;
    for(int i=0; i<1000000; i++) using_time.push_back(0);

    for(int i=0; i<n; i++){
        cin >> s >> e;
        for(int j=s; j<=e; j++){
            using_time[j]++;
        }
    }

    cin >> q;

    for(int i=0; i<q; i++){
        cin >> t;
        time.push_back(t);
    }

    for(int t :time){
        cout << using_time[t] << "\n";
    }

    return 0;
}