#include <iostream>
#include <vector>
using namespace std;

/* how to solve
    dp 사용
    마지막날부터 순회하며 상담을 할 수 있는 경우 max(상담을 하는 경우, 상담을 하지 않는 경우)
*/

int dp[16];
int main(){
    int n, t, p; vector<pair<int,int>> consult;
    cin >> n; 
    for(int i=0; i<n; i++){
        cin >> t >> p;
        consult.push_back({t, p});
    }

    for(int i=n-1; i>=0; i--){
        if(consult[i].first+i+1>=n) dp[i]=dp[i+1];
        else                         dp[i]=max(dp[i+consult[i].first]+consult[i].second, dp[i+1]);
    }

    cout << dp[0];

    return 0;
}