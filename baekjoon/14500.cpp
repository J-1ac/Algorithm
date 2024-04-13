#include <iostream>
#include <climits>
#include <vector>
using namespace std;

/** how to solve
 * DFS로 현재 좌표에서 만들 수 있는 모든 테트로미노 탐색 + ㅜ 모양 추가 탐색 (DFS로 탐색 불가)
 * 그 합이 my_max보다 크면 갱신
*/

int map[500][500]; int my_max=INT_MIN; int dir[4][2]={{0,1},{0,-1},{1,0},{-1,0}};

void dfs(int row, int col, vector<pair<int,int>> &visited, int n, int m){
    if(visited.size()==4){
        int sum=0;
        for(int i=0; i<visited.size(); i++){
            sum+=map[visited[i].first][visited[i].second];
        }
        if(sum>my_max)  my_max=sum;
        return;
    }
    for(int i=0; i<4; i++){
        int next_row=row+dir[i][0], next_col=col+dir[i][1]; 
        if(next_row<0 || next_row>=n || next_col<0 || next_col>=m) continue;
        bool is_visited=false;
        for(int j=0; j<visited.size(); j++){                                    // 방문했던 node 재방문 방지
            if(visited[j].first==next_row && visited[j].second==next_col){
                is_visited=true;
                break;
            }
        }
        if(!is_visited){
            vector<pair<int,int>> next_visited = visited;
            next_visited.push_back({next_row, next_col});
            dfs(next_row, next_col, next_visited, n, m);
        }
    }
}

void findTetromino(int row, int col, int n, int m){
    for(int i=0; i<4; i++){
        int sum=map[row][col];
        for(int j=0; j<4; j++){
            if(i==j) continue;
            int next_row=row+dir[j][0], next_col=col+dir[j][1];
            if(next_row<0 || next_row>=n || next_col<0 || next_col>=m) continue;
            sum+=map[next_row][next_col];
        }
        my_max=max(my_max,sum);
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            findTetromino(i, j, n, m);
            vector<pair<int,int>> visited;
            visited.push_back({i,j});
            dfs(i, j, visited, n, m);
        }
    }

    cout << my_max;

    return 0;
}