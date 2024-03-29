#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    큐 사용
    회전된 톱니의 원래 전극 : index + 첫 톱니의 회전방향 * -1 ^ 첫 톱니와의 거리
*/

void rotateGear(deque<int>& gear, int r) {
    int temp;
    if(r==1){                                   //시계방향 회전
        temp = gear.back();
        gear.pop_back();
        gear.push_front(temp);
    }else{                                      //반시계방향 회전
        temp = gear.front();
        gear.pop_front();
        gear.push_back(temp);
    }
}

int main(){
    int t, k, n, r, cnt=0;
    cin >> t;
    vector<deque<int>> gear; queue<pair<int,int>> q;
    for(int i=0; i<t; i++){
        deque<int> temp; int tv;
        for(int j=0; j<8; j++){
            scanf("%1d", &tv);
            temp.push_back(tv);
        }
        gear.push_back(temp);
    }
    cin >> k;

    for(int i=0; i<k; i++){
        cin >> n >> r;
        n--;
        q.push({n, 0});
        while(!q.empty()){
            int current_n = q.front().first;
            int current_d = q.front().second;
            q.pop();
            rotateGear(gear[current_n], r * pow(-1, abs(current_n-n)));
            //왼쪽 톱니 회전
            if(current_n>0 && current_d != 1 && gear[current_n-1][2]!=gear[current_n][6+r*pow(-1, abs(current_n-n))]){      
                q.push({current_n-1, -1});
            }         
            //오른쪽 톱니 회전
            if(current_n<t-1 && current_d != -1 && gear[current_n+1][6]!=gear[current_n][2+r*pow(-1, abs(current_n-n))]){
                q.push({current_n+1, 1});
            }
        }
    }
    
    for(int i=0; i<t; i++){
        if(gear[i][0]==1) cnt++;        
    }

    cout << cnt;

    return 0;
}