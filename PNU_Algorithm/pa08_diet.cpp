#include <bits/stdc++.h>
#include <iostream>
using namespace std;

bool mycompare(const vector<int> a, const vector<int> b){
    return a[4]<b[4];
}
struct Node{
    vector<int> sum;                                          // n1, n2, n3, n4
    vector<int> choosen;                                      // choosen ingredients;
    int cost;
    int b;
    int level;
    Node(vector<int> s, vector<int> ch, int c, int b, int l): sum(s), choosen(ch), cost(c), b(b), level(l){}
};

struct comparenode {
    bool operator()(const Node& n1, const Node& n2) {
        return n1.b < n2.b;
    }
};

int calbound(const vector<vector<int>> &ingredients, const vector<int> &requirement, const Node &n){
    int b=n.cost, cnt=0; vector<int> nutri=n.sum;
    for(int i=n.level; i<ingredients.size(); i++){
        for(int j=0; j<4; j++) nutri[j]+=ingredients[i][j];
        if(nutri[0]>=requirement[0] && nutri[1]>=requirement[1] && nutri[2]>=requirement[2] && nutri[3]>=requirement[3]) return b;
        b+=ingredients[i][4];
    }

    return b;
}

void branchandbound(const vector<vector<int>> &ingredients, const vector<int> &requirement){
    int mincost=INT_MAX, rb=0, n=ingredients.size(); vector<int> bestingredient;           
    priority_queue<Node, vector<Node>, comparenode> pq;
    Node root(vector<int>(4,0), vector<int>(), 0, 0, 0);
    root.b = calbound(ingredients, requirement, root);
    pq.push(root);

    while(!pq.empty()){
        Node cnode=pq.top();
        pq.pop();
        bool needchange=false; int cost=cnode.cost, b=cnode.b, level=cnode.level; vector<int> sum=cnode.sum, choosen=cnode.choosen;

        if(sum[0]>=requirement[0] && sum[1]>=requirement[1] && sum[2]>=requirement[2] && sum[3]>=requirement[3]){
            if(cost<mincost) needchange=true;
            else if(cost==mincost){
                int sum_best=0, sum_choosen=0;
                for(int index :bestingredient){
                    for(int i=0; i<4; i++){
                        sum_best+=ingredients[index-1][i];
                    }
                }
                for(int index :choosen){
                    for(int i=0; i<4; i++){
                        sum_choosen+=ingredients[index-1][i];
                    }
                }
                if(sum_choosen>sum_best) needchange=true;
                else if(sum_choosen==sum_best){
                    int size=min(bestingredient.size(), choosen.size());
                    for(int i=0; i<size; i++){
                        if(bestingredient[i]>choosen[i]){
                            needchange=true;
                        }else if(bestingredient[i]<choosen[i]){
                            break;
                        }
                    }
                }
            }
            if(needchange){
                mincost=cost;
                bestingredient=choosen;
            }
        }
        if(level==n) continue;
        Node newnode1(sum, choosen, cost, 0, level+1), newnode2(sum, choosen, cost, 0, level+1);
        for(int i=0; i<4; i++)  newnode1.sum[i]+=ingredients[level][i];
        newnode1.choosen.push_back(ingredients[level][5]);
        newnode1.cost+=ingredients[level][4];
        newnode1.b=calbound(ingredients, requirement, newnode1);
        newnode2.b=calbound(ingredients, requirement, newnode2);
        if(newnode1.b<=mincost && newnode1.cost<=mincost) pq.push(newnode1);
        if(newnode2.b<=mincost && newnode2.cost<=mincost) pq.push(newnode2);
    }
    sort(bestingredient.begin(), bestingredient.end());
    for(int i :bestingredient) cout << i << " ";
}

int main(){
    bool ispossible=true; int k, temp; vector<int> minrequirements(4), total(4);
    cin >> k;
    vector<vector<int>> ingredients(k);
    for (int i = 0; i < 4; i++) {
        cin >> minrequirements[i];
        total[i]=0;
    }
    for (int i = 0; i < k; i++) {
        vector<int> ingredient(6);                    
        ingredient[5]=i+1;
        for (int j = 0; j < 5; j++) {
            cin >> ingredient[j];
            if(j<4) total[j]+=ingredient[j];
        }
        ingredients[i]=ingredient;
    }

    for(int i=0; i<4; i++) if(total[i]<minrequirements[i]) ispossible=false;
    sort(ingredients.begin(), ingredients.end(), mycompare);
    if(ispossible) branchandbound(ingredients, minrequirements);
    else           cout << "0";

    return 0;
}