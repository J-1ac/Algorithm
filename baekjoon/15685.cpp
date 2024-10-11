#include<iostream>
#include<climits>
#include<vector>
using namespace std;

/** how to solve
 * 삼각함수 활용 특정 좌표를 기준으로 회전
 * x` = (x-a) * cosΘ - (y-b) * sinΘ + a
 * y` = (x-a) * sinΘ + (y-b) * cosΘ + b
 * 
 * 시계 방향 90도 회전이므로 Θ = 90 degrees
 * x` = -y + a + b
 * y` = x - a + b
 */

int n, x, y, d, g;
bool area[101][101];            //드래곤 커브가 지나는 좌표
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};

pair<int,int> rotate_point(pair<int,int> point, pair<int,int> origin){
    return {-point.second + origin.first + origin.second, point.first - origin.first + origin.second};
}

void draw_dragon_curve(){
    vector<pair<int,int>> dragon_curve;
    dragon_curve.push_back({x,y});
    dragon_curve.push_back({x+dx[d], y+dy[d]});
    area[x][y] = true;
    area[x+dx[d]][y+dy[d]] = true;

    for(int i=1; i<=g; i++){                                // g 세대까지 반복
        pair<int,int> origin_point = dragon_curve.back();
        int current_size = dragon_curve.size();
        for(int j=current_size-2; j>=0; j--){         // 끝점을 제외한 모든 드래곤커브의 점에 대하여
            pair<int,int> next_point = rotate_point(dragon_curve[j], origin_point);
            dragon_curve.push_back(next_point);
            area[next_point.first][next_point.second] = true;
        }
    }
}

void get_cnt(){
    int cnt=0;
    for(int row=0; row<100; row++){
        for(int col=0; col<100; col++){
            if(area[row][col] && area[row+1][col] && area[row][col+1] && area[row+1][col+1]) cnt++;
        }
    }

    cout << cnt;
}

int main(){
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> x >> y >> d >> g;
        draw_dragon_curve();
    }

    get_cnt();

    return 0;
}