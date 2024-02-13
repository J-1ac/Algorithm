#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve
    dp사용
    1부터 시작해서 어떤 수를 제곱했을 때 i에 가장 가까운 수를 n이라고 했을 때
    dp[i]=min(dp[i],dp[i-n*n]+1)
*/


int main(){
    int n; 
    cin >> n;
    vector<int> dp(n+1,0);

    for(int i=1; i<=n; i++){
        dp[i] = i;
        for(int j=1; j*j<=i; j++){
            dp[i]=min(dp[i], dp[i-j*j]+1);
        }
    }

    cout << dp[n];
    return 0;
}