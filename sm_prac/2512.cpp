#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve
    pq 사용.
    pq.top * size 이 남은 예산보다 작을 경우 pop할 수 없음.
    ### 이분탐색도 고려해 볼 것.
*/

int main(){
    int n, temp, num, max, sum=0; priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> temp;
        pq.push(temp);
        sum+=temp;
    }
    cin >> max;

    while(!pq.empty()){
        num=pq.top();
        if(num*pq.size()>max){          //더이상 pop하지 못하는 경우.
            num = int(max/pq.size());
            break;
        }
        pq.pop();
        max-=num;
    }

    cout << num;

    return 0;
}