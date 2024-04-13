#include <iostream>
#include <vector>
#include <queue>
#include <array>
#include <climits>
using namespace std;

/* how to solve
    BFS를 통해 현재 먹을 수 있고, 가장 가까운 거리에 속하는 먹이들만 pq에 넣기
    -> pq 중 top()만 먹고 다시 BFS를 통해 다음 먹이 후보군 탐색
*/

int map[20][20];
pair<int,int> current_shark;
pair<int,int> dir[4]={{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

// 먹이 구조체, 문제에서 정의된 우선순위 연산자
struct Food{
    int size;
    int row;
    int col;
    int distance;
    bool operator <(const Food f) const {
        if(this->distance == f.distance){
            if(this->row == f.row) return this->col > f.col;
            return this->row > f.row;
        }
        return this->distance > f.distance;
    }
};

// map을 bfs 순회하며, 현재 상어가 먹을 수 있는 먹이 중 가장 가까운 거리에 속하는 먹이들만 foods에 추가
void findFood(priority_queue<Food> &foods, int shark_size, int n){
    queue<array<int, 3>> q; 
    int visited[20][20]{};
    int min_distance = INT_MAX;
    q.push({current_shark.first, current_shark.second, 0});

    while(!q.empty()){
        array<int, 3> current = q.front();
        q.pop();
        if(current[2]>min_distance) break;
        if(map[current[0]][current[1]]<shark_size && map[current[0]][current[1]]!=0){
            min_distance=current[2];
            foods.push({map[current[0]][current[1]], current[0], current[1], current[2]});
        }
        for(int i=0; i<4; i++){
            array<int, 3> next = {current[0]+dir[i].first, current[1]+dir[i].second, current[2]+1};
            if(next[0]<0 || next[0]>=n || next[1]<0 || next[1]>=n || visited[next[0]][next[1]] || map[next[0]][next[1]]>shark_size){
                continue;
            }
            q.push(next);
            visited[next[0]][next[1]]=1;
        }
    }
}

int main(){
    int n, cnt=0, shark_size=2, shark_level=0; priority_queue<Food> foods;
    cin >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> map[i][j];
            if(map[i][j]==9){
                current_shark = {i,j}; 
                map[i][j]=0;
            }
        }
    }

    findFood(foods, shark_size, n);

    while(!foods.empty()){
        Food next_food = foods.top();
        cnt += next_food.distance;
        current_shark = {next_food.row, next_food.col};
        map[current_shark.first][current_shark.second]=0;
        shark_level++;
        if(shark_level >= shark_size){
            shark_size++;
            shark_level=0;
        }
        while(!foods.empty()) foods.pop();
        findFood(foods, shark_size, n);
    }

    cout << cnt;

    return 0;
}