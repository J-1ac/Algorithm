#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve
    dp 사용
*/

int n, k; int w[101], v[101], dp[101][100001];
int main(){
    cin >> n >> k;
    for(int i=1; i<=n; i++){
        cin >> w[i] >> v[i];
    }


    for(int i=1; i<=k; i++){
        for(int j=1; j<=n; j++){
            if(w[j]>i){                                             //담을 수 없는 경우 -> i-1번째 아이템까지 고려했을때 optimal과 동일
                dp[j][i] = dp[j-1][i];   
            }else{                                                  //담을 수 있는 경우 -> i번째 아이템까지 고려했을때 optimal 고려
                dp[j][i] = max(dp[j-1][i-w[j]]+v[j], dp[j-1][i]);   //max(현재 아이템 넣을 경우, 안넣을 경우)
            }
        }
    }

    cout << dp[n][k];

    return 0;
}