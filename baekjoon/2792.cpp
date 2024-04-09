#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    이분탐색
    SUM(각 보석의 개수 / 한 사람이 가져가는 보석의 수) = 보석을 가져간 사람의 수 -> n
*/

int n, m, gem[300000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(nullptr);

    cin >> n >> m;
    for(int i=0; i<m; i++){
        cin >> gem[i];
    }

    int left=1, right=*max_element(gem, gem + m), mid, total;

    while(left<=right){
        mid = (right+left)/2;
        total=0;
        for(int i=0; i<m; i++){
            total += gem[i]/mid;
            if(gem[i]%mid!=0)   total++;
        }
        if(total>n) left = mid+1;
        else        right = mid-1;
    }

    cout << left;

    return 0;
}