#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/** how to solve 
 * deque 사용
 * 가중치가 낮은 경우 (=우선 순위 높은 경우) push_front 해줘야 함!
*/

int main(){
    int n, k;
    cin >> n >> k;

    if(n>=k){
        cout << n-k;
        return 0;
    }

    int ans[100001];
    std::fill_n(ans, 100001, -1);
    deque<int> dq;
    dq.push_back(n);
    ans[n]=0;

    while(!dq.empty()){
        int cur = dq.front();
        dq.pop_front();

        if(cur == k){
            cout << ans[cur];
            break;
        }

        for(int next : {cur*2, cur-1, cur+1}){
            if(next < 0 || next > 100000)   continue;
            if(ans[next] != -1)             continue;       // 이미 방문한 경우
            if(next == cur*2){                              // 우선순위 높음
                ans[next] = ans[cur];
                dq.push_front(next);
            }
            else{                                           // 우선순위 낮음
                ans[next] = ans[cur]+1;
                dq.push_back(next);
            }
        }   
    }

    return 0;
}