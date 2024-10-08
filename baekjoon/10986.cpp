#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    구간합
    (A+B)%C = A%C + B%C
*/

int sum[1000000];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, temp, ans=0;
    cin >> n >> m;

    for(int i=1; i<=n; i++){
        cin >> temp;
        sum[i] = sum[i-1] + temp;
    }

    for(int i=1; i<=n; i++){
        
    }


    return 0;
}