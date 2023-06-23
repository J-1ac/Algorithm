#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int gm(const vector<int> &a, const vector<int> &b){         //getmanhattan()
    int d=0;
    d+=abs(a[0]-b[0]);
    d+=abs(a[1]-b[1]);
    return d;
}

struct Node{                                                //struct Node 
    vector<int> p;
    int l, d, b, c;
};

struct mycompare{                                           //mycompare for priority queue
    bool operator()(const Node& n1, const Node& n2) {
        return n1.b < n2.b;
    }
};

int calb(Node cn, int n, const vector<vector<int>>& dis){   //calcuratebound()
    int b=cn.d, i=1, min=1234567890;                        //add distance to bound
    while(i<2*n+1){                                         //choose next vi
        bool possible=false;
        if(cn.c<2 && i%2==1 && count(cn.p.begin(), cn.p.end(), i)==0) possible=true;
        else if(i%2==0 && count(cn.p.begin(), cn.p.end(), i-1)!=0 && count(cn.p.begin(), cn.p.end(), i)==0) possible=true;
        if(possible && dis[cn.p.back()][i]<min) min=dis[cn.p.back()][i];
        i++;
    }
    b+=min;
    i=1;
    while(i<2*n+1){                                         //get min for each remain node
        bool possible=false;
        if(cn.c<2 && i%2==1 && count(cn.p.begin(), cn.p.end(), i)==0) possible=true;
        else if(i%2==0 && count(cn.p.begin(), cn.p.end(), i-1)!=0 && count(cn.p.begin(), cn.p.end(), i)==0) possible=true;
        if(possible){
            int j=0; min=1234567890;
            bool possible2=false;
            while(j<2*n+1){
                if(i!=j && cn.c<2 && i%2==1 && count(cn.p.begin(), cn.p.end(), i)==0) possible2=true;
                else if(i%2==0 && count(cn.p.begin(), cn.p.end(), i-1)!=0 && count(cn.p.begin(), cn.p.end(), i)==0) possible2=true;
                else if(j==0 && i!=0) possible2=true;
                if(possible2 && dis[i][j]<min) min=dis[i][j];
                j++;
            }
            b+=min;
        } 
        i++;
    }
    return b;
}


void bb(int n, const vector<vector<int>>& dis){             //branchandbound()
    vector<int> op; int min=1234567890;
    priority_queue<Node, vector<Node>, mycompare> pq;
    Node u, v;                                              //v:current node, u:next node
    v.l=0; v.p.push_back(0); v.d=0; v.c=0; 
    v.b=calb(v,n,dis);
    pq.push(v);                                             //push root to priority queue
    while(!pq.empty()){
        v=pq.top(); pq.pop(); 
        int i=1;
        while(i<2*n+1){
            bool possible=false;
            if(v.c<2 && i%2==1 && count(v.p.begin(), v.p.end(), i)==0) possible=true;                                           //if nextnode is pickup
            else if(i%2==0 && count(v.p.begin(), v.p.end(), i-1)!=0 && count(v.p.begin(), v.p.end(), i)==0) possible=true;      //if nextnode is destination
            if(possible){
                if(i%2) u.c=v.c+1;
                else    u.c=v.c-1;
                u.l=v.l+1;
                u.p=v.p;
                u.p.push_back(i);
                u.d=v.d+dis[v.p.back()][i];
                if(u.l == 2*n){                                             //if next node is finish
                    if(u.d<min){
                        min=u.d;
                        op=u.p;
                    }else if(u.d==min){                                     //sort in dictionary order
                        int j=0, ind1, ind2;
                        while(j<op.size() && op[j]==u.p[j]) j++;
                        if(u.p[j]%2) ind1=(u.p[j]-1)/2+1;
                        else            ind1=-(u.p[j]-1)/2+1;
                        if(op[j]%2) ind2=(op[j]-1)/2+1;
                        else           ind2=-(op[j]-1)/2+1;
                        if(ind1<ind2){
                            min=u.d;
                            op=u.p;
                        }
                    }
                }else{                                                      //if promising(bound<=min) -> push to priority queue
                    u.b=calb(u, n, dis);
                    if(u.b<=min){
                        pq.push(u);
                    }
                }
            } i++;
        }
    }
    for(int i=1; i<op.size(); i++){                                         //print result
        if(op[i]%2) cout << (op[i]-1)/2+1 << " ";
        else    cout << -((op[i]-1)/2+1) << " ";}
    cout << "\n" << min;
}

int main(){ 
    int n;
    cin >> n;
    vector<vector<int>> nodes(n, vector<int>(4,0)), dis(2*n+1,vector<int>(2*n+1,0)); vector<int> n1(2), n2(2);      //nodes: 0:pickup.x, 1:pickup.y, 2:destination.x, 3:destination.y.
    for(int i=0; i<n; i++){                                                                                         //dis: if index%2==1 -> pickupnode, else -> destinationnode
        cin >> nodes[i][0] >> nodes[i][1] >> nodes[i][2] >> nodes[i][3];
    }

    for(int i=0; i<2*n+1; i++){                                                             //calcurate distance, index 0:rider start{500,500}, else if(index%2)->pickup, else->destination
        if(i==0)     n1={500,500};
        else if(i%2) n1={nodes[(i-1)/2][0], nodes[(i-1)/2][1]};
        else         n1={nodes[(i-1)/2][2], nodes[(i-1)/2][3]};
        for(int j=0; j<2*n+1; j++){
            if(j==0)     n2={500,500};
            else if(j%2) n2={nodes[(j-1)/2][0], nodes[(j-1)/2][1]};
            else         n2={nodes[(j-1)/2][2], nodes[(j-1)/2][3]};
            dis[i][j]=gm(n1,n2);
        }
    }

    bb(n, dis);                                     //get optimal travel.

    return 0;
}