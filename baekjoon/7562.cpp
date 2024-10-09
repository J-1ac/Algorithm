#include<iostream>
#include<queue>
#include<array>
#include<climits>
using namespace std;

int area[300][300]; 
bool visited[300][300];
int dx[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dy[8] = {-2, -1, 1, 2, -2, -1, 1, 2};
pair<int,int> s, e;
int t, l;

struct Node {
    int x, y, dist;
    Node(int _x, int _y, int _dist) : x(_x), y(_y), dist(_dist) {}
};


int bfs(){
    queue<Node> q;

    //visited 배열 초기화
    for(int row=0; row<l; row++){
        for(int col=0; col<l; col++){
            visited[row][col] = false;
        }
    }

    q.push(Node(s.first, s.second, 0));
    visited[s.first][s.second] = true;

    while (!q.empty()){
        Node current = q.front();
        q.pop();

        if (current.x==e.first && current.y==e.second){
            return current.dist;
        }

        for(int i=0; i<8; i++){
            Node next = Node(current.x+dx[i], current.y+dy[i], current.dist+1);
            if(next.x>=0 && next.x<l && next.y>=0 && next.y<l && visited[next.x][next.y]==false){
                visited[next.x][next.y]=true;
                q.push(next);
            }
        }
    }
}

int main(){
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> l;
        cin >> s.first >> s.second;
        cin >> e.first >> e.second;
        for(int row=0; row<l; row++){
            for(int col=0; col<l; col++){
                area[row][col]=0;                               // area 초기화
            }
        }
        cout << bfs() << '\n';
    }

    return 0;
}