#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/*
Main Idea
#1 pollution된 vertex를 queue에 넣음
#2 time++하며 weight==time이 된다면 pollutioned
#3 만약, vertex와 연결된 edge들 중 max weight보다 time이 커지면, queue에서 pop
#4 모든 지역이 pollutioned될때 까지 반복
*/

int main(){
    int n, c1, c2, v1, v2, w, cnt=0;
    vector<tuple<int, int, int>> edges; queue<pair<int, int>> pollutioned;              //queue for pollutioned vertices(vertexnum, time)
    cin >> n >> c1 >> c2;
    int visited[n+1]{}; int weight[n+1]{};

    visited[c1]=1; pollutioned.push(make_pair(c1, 0));                                  //push Vc1 to pollutioned queue
    visited[c2]=1; pollutioned.push(make_pair(c2, 0));                                  //push Vc2 to pollutioned queue
    for(int i=0; i<n-1; i++){
        cin >> v1 >> v2 >> w;
        if(weight[v1]<w) weight[v1]=w;                                                  //update vertex's max weight
        if(weight[v2]<w) weight[v2]=w;
        edges.push_back(make_tuple(v1, v2, w));
    }

    while(cnt<n-2){                                                                     //while all vertices are pllutioned, time++
        vector<int> cpollutioned;
        int size=pollutioned.size();
        for(int i=0; i<size; i++){
            pair<int, int> cv=pollutioned.front();
            pollutioned.pop();
            cv.second++;
            for(int j=0; j<edges.size(); j++){                                          //pollution if wegiht==ctime
                if(get<0>(edges[j])==cv.first && get<2>(edges[j])==cv.second && visited[get<1>(edges[j])]==0) cpollutioned.push_back(get<1>(edges[j]));
                if(get<1>(edges[j])==cv.first && get<2>(edges[j])==cv.second && visited[get<0>(edges[j])]==0) cpollutioned.push_back(get<0>(edges[j]));
            }
            if(cv.second<weight[cv.first]) pollutioned.push(cv);                        //if time<weight -> push to queue again    
        }

        if(cpollutioned.size()>0){
            cnt+=cpollutioned.size();
            sort(cpollutioned.begin(), cpollutioned.end());
            for(int i=0; i<cpollutioned.size(); i++){
                cout << cpollutioned[i] << '\n';
                visited[cpollutioned[i]]=1;
                pollutioned.push(make_pair(cpollutioned[i], 0));
            }
        }
    }

    return 0;
}