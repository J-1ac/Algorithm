#include <iostream>
#include <vector>
#include <climits>
using namespace std;

/** how to solve
 * 
*/

struct Order{
    int row;
    int col;
    int s;
};

void rotateArray(int r, int c, int s){
    for(int i=r-s-1; i<r+s-1; i++){
        for(int j=c-s-1; j<c+s-1; j++){
            
        }
    }
}

int map[50][50]; int sums[50]; int min=INT_MAX;
int main(){
    int n, m, k, r, c, s; vector<Order> orders;
    cin >> n >> m >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<k; i++){
        cin >> r >> c >> s;
        orders.push_back({r,c,s});
    }



    return 0;
}