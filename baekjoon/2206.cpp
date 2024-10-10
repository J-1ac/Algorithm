#include<iostream>
#include<queue>
#include<climits>
using namespace std;

/**
 * how to solve
 * 벽을 부순 여부를 고려해서 visited 판단해야함.
 * why? 벽을 부수지 않고 특정 지점에 도달한 경로가 먼저 그 지점을 방문 처리해버림. 
 */


int n, m;
int area[1001][1001];
bool visited[1001][1001][2];  // [x][y][벽을 부순 여부]

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

struct Node{
    int x, y, wall, cnt;
    Node(int x, int y, int wall, int cnt) : x(x), y(y), wall(wall), cnt(cnt) {}
};

void bfs(){
    for(int row=1; row<=n; row++){
        for(int col=1; col<=m; col++){
            visited[row][col][0] = false;
            visited[row][col][1] = false;
        }
    }

    queue<Node> q;
    q.push(Node(1, 1, 0, 1));
    visited[1][1][0] = true;

    while(!q.empty()){
        Node current = q.front();
        q.pop();

        // break 조건 -> (N,M)에 방문한 경우
        if(current.x == n && current.y == m){
            cout << current.cnt;
            return;
        }

        for(int i=0; i<4; i++){
            Node next = Node(current.x+dx[i], current.y+dy[i], current.wall, current.cnt+1);

            if(next.x < 1 || next.x > n || next.y < 1 || next.y > m) continue;
            
            // 벽이 아닌 경우
            if(area[next.x][next.y]==0 && !visited[next.x][next.y][next.wall]){
                visited[next.x][next.y][next.wall] = true;
                q.push(next);
            }
            // 벽인 경우
            else if(area[next.x][next.y]==1 && next.wall == 0 && !visited[next.x][next.y][1]){
                next.wall++;
                visited[next.x][next.y][1] = true;
                q.push(next);
            }
        }
    }

    cout << "-1";
}

int main(){
    cin >> n >> m;
    for(int row=1; row<=n; row++){
        string line;
        cin >> line;
        for(int col=1; col<=m; col++){
            area[row][col] = line[col-1] - '0';
        }
    }

    //bfs 순회하며 벽을 부순 갯수도 고려 -> 구조체 사용
    bfs();

    return 0;
}