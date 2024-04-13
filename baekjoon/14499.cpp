#include <iostream>
#include <vector>
using namespace std;

/** how to solve
 * 단순 구현이라 적을게 없음
 * 주사위를 구르는 방향에 따라 dice의 내용 변경해주기
*/

int map[20][20]; int dice[6]; int dir[4][2] = {{0,1}, {0,-1}, {-1,0}, {1,0}};

void rollDice(int dir){
    int temp[6];
    if(dir==1){
        temp[0]=dice[3]; temp[1]=dice[1]; temp[2]=dice[0]; temp[3]=dice[5]; temp[4]=dice[4]; temp[5]=dice[2]; 
    }else if(dir==2){
        temp[0]=dice[2]; temp[1]=dice[1]; temp[2]=dice[5]; temp[3]=dice[0]; temp[4]=dice[4]; temp[5]=dice[3]; 
    }else if(dir==3){
        temp[0]=dice[1]; temp[1]=dice[5]; temp[2]=dice[2]; temp[3]=dice[3]; temp[4]=dice[0]; temp[5]=dice[4]; 
    }else{
        temp[0]=dice[4]; temp[1]=dice[0]; temp[2]=dice[2]; temp[3]=dice[3]; temp[4]=dice[5]; temp[5]=dice[1]; 
    }
    for(int i=0; i<6; i++) dice[i]=temp[i];
    return;
}

int main(){
    int n, m, x, y, k, order; 
    cin >> n >> m >> x >> y >> k;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<k; i++){
        cin >> order;
        int next_x=x+dir[order-1][0], next_y=y+dir[order-1][1];
        if(next_x<0 || next_x>=n || next_y<0 || next_y>=m)  continue;
        rollDice(order); x=next_x; y=next_y;
        if(map[x][y]==0){
            map[x][y]=dice[5];
        }else{
            dice[5]=map[x][y];
            map[x][y]=0;
        }
        cout << dice[0] << "\n";
    }

    return 0;
}