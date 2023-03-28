#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int my_maximumsum(const vector<int>& my_vector){
    int max_sum = INT_MIN;

    for(int i=0; i<my_vector.size(); i++){
        int sum=0;
        for(int j=i; j<my_vector.size(); j++){
            sum+=my_vector[j];
            if(max_sum<sum) max_sum=sum;
        }
    }

    return max_sum;
}

int main(){
    int p, n, m, t, temp_start, temp_end, temp_db; vector<int> schedule;
    cin >> p >> n >> m;
    

    for(int i=0; i<n; i++) schedule.push_back(p);

    for(int i=0; i<m; i++){
        cin >> t;
        for(int j=0; j<t; j++){
            cin >> temp_start >> temp_end >> temp_db;
            for(int time=temp_start; time<temp_end; time++) schedule[time]+=temp_db;
        }
    }
    
    cout << my_maximumsum(schedule);

    return 0;
}