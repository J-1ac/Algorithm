#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/** how to solve
 * col(i)==col(j)     같은 col에 퀸
 * col(i)-col(j)==i-j 같은 대각선에 퀸
*/
int col[15], ans=0, N;

bool pruning(int row){
    for(int i = 0; i < row; i++)
        if(col[i] == col[row] || abs(col[row] - col[i]) == row - i)
            return false;
    return true;
}

void n_queen(int row){
    if(row == N)
        ans++;
    else{
        for(int i = 0; i < N; i++){
            col[row] = i; 
            if(pruning(row)) 
                n_queen(row+1);
        }
    }    
}

int main(){
    cin >> N;
    n_queen(0);
    cout << ans;

    return 0;
}