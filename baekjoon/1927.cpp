#include <bits/stdc++.h>
#include <iostream>
using namespace std;
//prioirty queue 활용
//시간초과 line8,9 확인

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, x;
    priority_queue<int, vector<int>, greater<int>> mypq;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> x;
        if(x==0){
            if(mypq.empty())    cout << 0 << '\n';
            else{
                                cout << mypq.top() << '\n';
                                mypq.pop();
            }
        }else{
                                mypq.push(x);
        }
    }

    return 0;
}