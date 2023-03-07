#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n, k, time=0;
    cin >> n >> k;
    while(k>n){
        if(k%2==0)  k/=2;
        else        k-=1;
        time++;
    }
    if(k==n)    cout << time;
    else        cout << time+1;

    return 0;
}