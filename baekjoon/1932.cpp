#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/** how to solve 
 * 2차원 dp
*/


int main(){
    int n, index=1, my_max=INT_MIN; int dp[500][500]{};
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<index; j++){
            cin >> dp[i][j];
            if(i>0 && j>0 && j<index-1){
                dp[i][j] = max(dp[i][j]+dp[i-1][j-1], dp[i][j]+dp[i-1][j]);
            }else if(i>0 && j>0){
                dp[i][j] += dp[i-1][j-1];
            }else if(i>0 && j<index-1){
                dp[i][j] += dp[i-1][j];
            }
        }
        index++;
    }
    
    for(int i=0; i<n; i++){
        if(dp[n-1][i]>my_max) my_max=dp[n-1][i];
    }

    cout << my_max;


    return 0;
}