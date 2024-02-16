#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve
    dp 사용.
    dp[j] = dp[j-1] + dp[j-2] + dp[j-3]
    * dp[1]=1, dp[2]=2, dp[3]=4
*/

int dp[12] = {0, 1, 2, 4};

int main(){
    int T, n;
    cin >> T;
    
    for(int j=4; j<=11; j++){
        dp[j] = dp[j-1] + dp[j-2] + dp[j-3];
    }

    for(int i=0; i<T; i++){
        cin >> n;
        cout << dp[n] << endl;
    }

    return 0;
}