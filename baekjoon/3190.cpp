#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    큐 사용
    시계방향으로 direction 정해둔 뒤 뱀의 다음 방향을 큐에 넣어서 저장
*/
int direction[4][2] = {{0,1}, {1,0}, {0,-1}, {-1,0}};
int main(){
    int n, k, l, t, x, y; char d;
    vector<pair<int, char>> timetable;
    queue<pair<int,int>> snake;
    int map[101][101]{};

    cin >> n >> k;
    for(int i=0; i<k; i++){
        cin >> x >> y;
        map[x][y] = 1;
    }
    cin >> l;
    for(int i=0; i<l; i++){
        cin >> t >> d;
        timetable.push_back(make_pair(t, d));
    }

    x=1, y=2; int direction_index=0, time=1; snake.push(make_pair(1,1));
    while(true){
        if(x<1 || x>n || y<1 || y>n || map[x][y]==-1) break;

        if(map[x][y]==1){
            map[x][y]=0;
        }else{
            map[snake.front().first][snake.front().second]=0;
            snake.pop();
        }

        snake.push(make_pair(x,y));
        map[x][y]=-1;

        for(int i=0; i<timetable.size(); i++){
            if(time == timetable[i].first){
                if(timetable[i].second == 'D'){
                    direction_index++;
                    if(direction_index==4) direction_index=0;
                }else{
                    direction_index--;
                    if(direction_index==-1) direction_index=3;
                }
            }
        }
        x = x + direction[direction_index][0];
        y = y + direction[direction_index][1];
        time++;
    }

    cout << time;

    return 0;
}