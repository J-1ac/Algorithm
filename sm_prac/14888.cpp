#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve
    최대 경우의 수 : 10! = 3628800 -> 브루트포스
    백트래킹 이용해서 모든 경우 조사.
*/
int n;
int op[4];
int an[11];
int mymin = INT_MAX;
int mymax = INT_MIN;

void backtracking(int rst, int cnt){ 
    if(cnt==n){
        if(rst<mymin) mymin=rst;
        if(rst>mymax) mymax=rst;
        return;
    }
    for(int i=0; i<4; i++){
        if(op[i] > 0){
            op[i]--;                                            //사용할 연산자 -1
            if(i==0) backtracking(rst+an[cnt], cnt+1);
            else if(i==1) backtracking(rst-an[cnt], cnt+1);
            else if(i==2) backtracking(rst*an[cnt], cnt+1);
            else if(i==3) backtracking(rst/an[cnt], cnt+1);
            op[i]++;                                            //사용한 연산자 +1
        }
    }
}


int main(){
    cin >> n;
    for(int i=0; i<n; i++){
        cin >> an[i];   
    }
    cin >> op[0] >> op[1] >> op[2] >> op[3];

    backtracking(an[0], 1);
    cout << mymax << "\n" << mymin;
    return 0;
}