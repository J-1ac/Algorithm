#include<bits/stdc++.h>
using namespace std;

// 미해결

struct Node{
    int mid, pid, color, depth;
    vector<int> children;
    Node(int mid = 0, int pid = -1, int color = 0, int depth = 0, vector<int> children = {}) : mid(mid), pid(pid), color(color), depth(depth), children(children) {}
};

int q, order;
Node nodes[100000];                      // 노드 저장 배열
bool visited[100000];                    // 점수 계산 시 방문했던 노드 판단 배열
vector<Node> roots;                      // root 노드 저장 배열

bool validate_max_depth(int pid, int depth){
    Node parent = nodes[pid];
    if(depth > parent.depth) return false; 
    if(parent.pid==-1)        return true;
    return  validate_max_depth(parent.pid, depth+1);
}

void add_children(int mid, int children){
    nodes[mid].children.push_back(children);
    if(nodes[mid].pid != -1){
        add_children(nodes[nodes[mid].pid].mid, children);
    }
}

void add_node(int mid, int pid, int color, int depth){
    Node node(mid, pid, color, depth, vector<int>{});

    // root 노드인 경우
    if(pid == -1){
        nodes[mid] = node;
        roots.push_back(node);
        return;
    }
    
    // max depth 검증
    if(!validate_max_depth(pid, 2)) {
        return;
    }
    
    // 노드 추가
    nodes[mid] = node;

    // 부모 노드들의 children에 추가
    add_children(pid, mid);
}

void change_color(int mid, int color){
    nodes[mid].color = color;
    for(int child_id : nodes[mid].children){
        change_color(child_id, color);
    }
}

int calculate_point(int mid){
    if(visited[mid]){
        return 0;
    }
    visited[mid]=true;

    int sum=0;
    Node node = nodes[mid];
    set<int> colors;

    // 현재 노드의 색상 추가
    colors.insert(node.color);

    // 자식 노드들의 색상 추가 및 점수 계산
    for (int child_id : node.children) {
        colors.insert(nodes[child_id].color);
        sum += calculate_point(child_id);  // 재귀적으로 자식 노드의 점수 계산
    }

    sum += pow(colors.size(), 2);
    return sum;
}

void retrieve_point(){
    int total_sum = 0;
    memset(visited, false, sizeof(visited));            // visited 초기화
    for(Node root : roots){
        total_sum += calculate_point(root.mid);
    }
    cout << total_sum << "\n";
}

int main(){
    cin >> q;
    for(int i=0; i<q; i++){
        int mid, pid, color, depth;
        cin >> order;
        if(order==100){                 // 노드 추가
            cin >> mid >> pid >> color >> depth;
            add_node(mid, pid, color, depth);
        }else if(order==200){           // 색깔 변경
            cin >> mid >> color;
            change_color(mid, color);
        }else if(order==300){           // 색깔 조회
            cin >> mid;
            cout << nodes[mid].color << "\n";
        }else if(order==400){           // 점수 조회
            retrieve_point();
        }
    }

    return 0;
}