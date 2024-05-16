#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/** how to solve 
 * dp 사용
 * dp[red 선택시 min cost][green 선택시 min cost][blue 선택시 min cost]
*/

int reds[1000], greens[1000], blues[1000]; 
int main(){
    int n; 
    array<array<int, 3>, 1000> dp{};
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> reds[i] >> greens[i] >> blues[i];
        if(i==0){
            dp[0][0] = reds[0];
            dp[0][1] = greens[0];
            dp[0][2] = blues[0];
        }else{
            dp[i][0] = min(dp[i-1][1] + reds[i], dp[i-1][2] + reds[i]);
            dp[i][1] = min(dp[i-1][0] + greens[i], dp[i-1][2] + greens[i]);
            dp[i][2] = min(dp[i-1][0] + blues[i], dp[i-1][1] + blues[i]);
        }
    }

    cout << min({dp[n-1][0], dp[n-1][1], dp[n-1][2]});

    return 0;
}