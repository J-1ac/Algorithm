#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve
    dp 사용
*/

int main(){
    int n; int ins[1001], dp[1001];
    cin >> n;
    for(int i=1; i<=n; i++){
        cin >> ins[i];
        dp[i]=1;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<i; j++){
            if(ins[i]>ins[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    sort(dp, dp+n+1);

    cout << dp[n];

    return 0;
}