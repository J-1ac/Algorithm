#include <bits/stdc++.h>
#include <iostream>
#define MYMAX 1025
using namespace std;

/* how to solve 
    구간합
*/

int sum[MYMAX][MYMAX];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    for(int row=1; row<=n; row++){
        for(int col=1; col<=n; col++){
            int tmp;
            cin >> tmp;
            sum[row][col] = sum[row][col-1] + sum[row-1][col] - sum[row-1][col-1] + tmp;
        }
    }

    for(int i=0; i<m; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        cout << sum[x2][y2] - sum[x1-1][y2] - sum[x2][y1-1] + sum[x1-1][y1-1] << "\n";
    }


    return 0;
}