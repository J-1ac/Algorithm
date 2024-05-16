#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/** how to solve 
 * 브루투포스
 * 조합으로 가능한 경우의 벡터 조합 생성
 * 벡터의 합을 계산해 min과 비교
*/

double vectorMin=DBL_MAX;

pair<int,int> getVector(pair<int,int> v1, pair<int,int> v2){
    return {v2.first-v1.first, v2.second-v1.second};
}

double getSum(vector<pair<int, int>> &vectors){
    int x=0, y=0;
    for(int i=0; i<vectors.size(); i++){
        x+=vectors[i].first;
        y+=vectors[i].second;
    }
    return sqrt(pow(x,2)+pow(y,2));
}


void permutation(vector<pair<int,int>> &points, int depth, int n, int r){
    if(depth == r){
        double sum=0; vector<pair<int,int>> vectors;
        for(int i=0; i<points.size(); i+=2){
            vectors.push_back(getVector(points[i], points[i+1]));
        }
        sum = getSum(vectors);
        if(sum<vectorMin) vectorMin=sum;
        return;
    }
    for(int i = depth; i < n; i++){
        swap(points[depth], points[i]);   // 스왑
        permutation(points, depth + 1, n, r);  // 재귀
        swap(points[depth], points[i]);  // 다시 원래 위치로 되돌리기
    }
}

int main(){
    int t;
    cin >> t;
    for(int i=0; i<t; i++){
        int n, x, y; vectorMin=DBL_MAX;
        vector<pair<int,int>> points;
        cin >> n;
        for(int j=0; j<n; j++){
            cin >> x >> y;
            points.push_back({x,y});
        }
        
        permutation(points, 0, points.size(), points.size());
        

        printf("%.12lf\n", vectorMin);

    }

    return 0;
}
