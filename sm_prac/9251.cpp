#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    dp 사용
    str1, 2의 각 i, j 번째 글자가 같다면 -> dp[i-1][j-1] + 1
                                 다르면 -> max(dp[i-1][j], dp[i][j-1])
*/

string str1, str2; int lcs=0, dp[1001][1001]={};
int main(){
    cin >> str1 >> str2;

    for(int i=1; i<=str1.size(); i++){
        for(int j=1; j<=str2.size(); j++){
            if(str1[i-1] == str2[j-1]) dp[i][j] = dp[i-1][j-1]+1;
            else                       dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            if (lcs<dp[i][j])          lcs=dp[i][j];
        }
    }
    
	cout << lcs;

    return 0;
}