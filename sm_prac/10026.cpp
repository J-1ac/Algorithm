#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    dfs 사용
    dfs로 탐색 -> visit할 경우 'V'.
    모든 정점 방문할때까지 반복.
*/

int dx[4] = {0, 0, -1, 1}, dy[4] = {1, -1, 0, 0};
char a1[100][100], a2[100][100];

void dfs1(int x, int y, int n){
    if(a1[x][y] == 'V'){
        return;     
    }
    char color = a1[x][y];
    a1[x][y] = 'V';
    for(int i=0; i<4; i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n && a1[nx][ny]!='V' && a1[nx][ny]==color){
            dfs1(x+dx[i], y+dy[i], n);
        }
    }
}

void dfs2(int x, int y, int n){
    if(a2[x][y] == 'V'){
        return;     
    }
    char color = a2[x][y];
    a2[x][y] = 'V';
    for(int i=0; i<4; i++){
        int nx=x+dx[i], ny=y+dy[i];
        if(nx>=0 && nx<n && ny>=0 && ny<n && a2[nx][ny]!='V' && a2[nx][ny]==color){
            dfs2(x+dx[i], y+dy[i], n);
        }
    }
}
int main(){
    int n, cnt1=0, cnt2=0; char temp;
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> temp;
            if(temp == 'R' || temp =='G'){
                a2[i][j]='R';
            }else{
                a2[i][j] = temp;
            }
            a1[i][j] = temp;
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a1[i][j]!='V'){
                dfs1(i, j, n);
                cnt1++;
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(a2[i][j]!='V'){
                dfs2(i, j, n);
                cnt2++;
            }
        }
    }
    cout << cnt1 << " " << cnt2;

    return 0;
}