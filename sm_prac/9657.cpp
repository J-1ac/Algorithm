#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve
    dp 사용.
    SK가 첫턴에 -1, -3, -4를 해서 이전의 CY의 승리패로 만들 수 있다면 SK의 승.
*/

int dp[1000] = {0, 1, 0, 0};

int main(){
    int n;
    cin >> n;
    for(int i=4; i<n; i++){
        if(dp[i-1]==1 || dp[i-3]==1 || dp[i-4]==1)  dp[i]=0;
        else                                        dp[i]=1;
    }
    if(dp[n-1]==0)    cout << "SK";
    else              cout << "CY";
    return 0;
}