#include <bits/stdc++.h>
#include <iostream>
using namespace std;
pair<int,int> dir[4] = {make_pair(0,0), make_pair(0, 1), make_pair(1, -1), make_pair(0, 1)};
int cnt=0;

void my_z(int size, pair<int, int> crc, int r, int c){
    if(size==2){
        for(int i=0; i<4; i++){
            crc.first+=dir[i].first;
            crc.second+=dir[i].second;
            if(crc.first==r && crc.second==c){
                cout << cnt;
                return;
            }
            cnt++;
        }
    }else{
        if(crc.first+size >= r && crc.second+size >= c && crc.first <= r && crc.second <= c){
            my_z(size/2, make_pair(crc.first, crc.second), r, c);
            my_z(size/2, make_pair(crc.first, crc.second+size/2), r, c);
            my_z(size/2, make_pair(crc.first+size/2, crc.second), r, c);
            my_z(size/2, make_pair(crc.first+size/2, crc.second+size/2), r, c);
        }else{
            cnt+=size*size;
        }
    }
}

int main(){
    int n, r, c;
    cin >> n >> r >> c;

    int size=pow(2, n);
    my_z(size, make_pair(0, 0), r, c);
}