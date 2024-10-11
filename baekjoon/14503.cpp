#include<bits/stdc++.h>
using namespace std;

int n, m, d, r, c, cnt=0;
int area[50][50];                       // 0: 청소 x, 1: 벽, 2: 청소 o
int dr[4] = {-1, 0, 1, 0};              // 북, 동, 남, 서
int dc[4] = {0, 1, 0, -1};
int mapping_behind[4] = {2, 3, 0, 1};

void possible_cleaning(){
    for(int i=0; i<4; i++){
        int current_dir = (d - i + 3) % 4;
        pair<int,int> next = {r+dr[current_dir], c+dc[current_dir]};

        // 바라보는 방향을 기준으로 앞쪽 칸이 청소되지 않은 빈 칸인 경우
        if(next.first<0 || next.first>=n || next.second<0 || next.second>=m) continue;
        if(area[next.first][next.second]==0){
            r = next.first;
            c = next.second;
            d = current_dir;
            return;
        }
    }
}

void cleaning(){
    while(1){
        bool flag = false;

        if(area[r][c]==0){
            area[r][c]=2;
            cnt++;
            continue;
        }
        
        for(int i=0; i<4; i++){
            pair<int,int> next = {r+dr[i], c+dc[i]};
            if(next.first<0 || next.first>=n || next.second<0 || next.second>=m) continue;

            if(area[next.first][next.second]==0){       // 청소되지 않은 빈 칸이 있는 경우
                flag = true;
                possible_cleaning();
                break;
            }
        }

        // 청소되지 않은 빈 칸이 없는 경우
        if(!flag){
            // 바라보는 방향을 유지한 채로 한 칸 후진할 수 있는 경우
            pair<int,int> next = {r+dr[mapping_behind[d]], c+dc[mapping_behind[d]]};
            if(next.first<0 || next.first>=n || next.second<0 || next.second>=m) continue;
            if(area[next.first][next.second]!=1){
                r = next.first;
                c = next.second;
                continue;
            }else{
                return;
            }
        }
    }
}

int main(){
    cin >> n >> m >> r >> c >> d;
    for(int row=0; row<n; row++){
        for(int col=0; col<m; col++){
            cin >> area[row][col];
        }
    }

    cleaning();

    cout << cnt;

    return 0;
}