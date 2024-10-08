#include <iostream>
#include <queue>
#include <climits>
using namespace std;

int area[100][100];
bool visited[100][100];
int n;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int getSafeArea() {
    int count = 0;
    queue<pair<int, int>> q;
    
    // visited 배열 초기화
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            visited[i][j] = false;
        }
    }
    
    // 모든 지점에 대해 BFS 수행
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            if (!visited[i][j] && area[i][j] != -1) {
                count++;
                q.push({i, j});
                visited[i][j] = true;
                
                while (!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    
                    for (int k = 0; k < 4; k++) {
                        int nx = x + dx[k];
                        int ny = y + dy[k];
                        
                        if (nx >= 0 && nx < n && ny >= 0 && ny < n && !visited[nx][ny] && area[nx][ny] != -1) {
                            q.push({nx, ny});
                            visited[nx][ny] = true;
                        }
                    }
                }
            }
        }
    }
    
    return count;
}

int main(){
    int max = INT_MIN, max_safe_area = 1, count_safe_area;
    cin >> n;

    for(int row=0; row<n; row++){
        for (int col=0; col<n; col++){
            cin >> area[row][col];
            if(area[row][col]>max) max=area[row][col];
        }
    }

    // 높이를 1부터 max까지 증가하며
        // 물에 잠기는 지점 update (area[row][col]=-1)
        // bps로 안전한 영역 갯수 count
        // max_safe_area update

    for(int h=1; h<=max; h++){
        for(int row=0; row<n; row++){
            for (int col=0; col<n; col++){
                if(area[row][col] <= h) area[row][col] = -1;
            }
        }
        count_safe_area = getSafeArea();
        if (count_safe_area > max_safe_area)    max_safe_area = count_safe_area;
    }

    cout << max_safe_area;

    return 0;
}
