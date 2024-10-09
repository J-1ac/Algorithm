#include<iostream>
#include<queue>
#include<climits>
#include<algorithm>
using namespace std;

int area[25][25];
bool visited[25][25];
vector<int> counts;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n;

void bfs(){
    //bfs 순환하며 집의 수 계산(pop하며 count++) 후 vector에 추가
    //오름차순 정렬 후 cout

    for(int row=0; row<n; row++){
        for(int col=0; col<n; col++){
            visited[row][col] = false;
        }
    }

    for(int row=0; row<n; row++){                   // 모든 구역에서 bfs 시행
        for(int col=0; col<n; col++){
            if(area[row][col]==1 && visited[row][col]==false){
                queue<pair<int,int>> q;
                int cnt=0;
                q.push({row,col});
                visited[row][col]=true;

                while(!q.empty()){
                    pair<int,int> current = q.front();
                    q.pop();
                    cnt++;
                    for(int i=0; i<4; i++){
                        pair<int,int> next = {current.first+dx[i], current.second+dy[i]};
                        // 경계안에 있고, area가 1(집) 이고, visited하지 않은 경우 push
                        if(next.first>=0 && next.first<n && next.second>=0 && next.second<n && area[next.first][next.second]==1 && visited[next.first][next.second]==false){
                            visited[next.first][next.second]=true;
                            q.push(next);
                        } 
                    }
                }
                counts.push_back(cnt);              // 계산된 집의 수 vector에 추가
            }
        }
    }
    sort(counts.begin(), counts.end());
    cout << counts.size() << "\n";
    for(int i=0; i<counts.size(); i++){
        cout << counts[i] << "\n";
    }

}

int main(){
    cin >> n;
    for(int row=0; row<n; row++){
        string line;
        cin >> line;
        for(int col=0; col<n; col++){
            area[row][col] = line[col] - '0';
        }
    }

    bfs();

    return 0;
}