#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    dp 다시풀기
*/

int num[100001];
int main(){
    int n, ans=0;
    for(int i=0; i<n; i++){
        cin >> num[i];
    }

    for(int d=-99; d<=99; d++){
        int dp[101]{};
        for(int i=0; i<n; i++){
            if(num[i]-d<1 || num[i]-d>100){
                dp[num[i]]=1;
            }else{
                dp[num[i]]=dp[num[i]-d]+1;
            }
            ans=max(ans,dp[num[i]]);
        }
    }

    cout << ans;


    return 0;
}