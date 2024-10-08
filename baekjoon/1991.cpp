#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/** how to solve
 * 재귀
*/

pair<char, char> graph[26];

//전위순회
void preorder(char cur){
    if(cur=='.')
    return;
    
    cout<<cur;
    preorder(graph[cur-'A'].first);
    preorder(graph[cur-'A'].second);
}

//중위순회
void inorder(char cur){
    if(cur=='.')
    return;

    inorder(graph[cur-'A'].first);
    cout<<cur;
    inorder(graph[cur-'A'].second);
}

//후위순회
void postorder(char cur){
    if(cur=='.')
    return;

    postorder(graph[cur-'A'].first);
    postorder(graph[cur-'A'].second);
    cout<<cur;
}

int main(){
    int n; 
    cin >> n;
    for(int i=0; i<n; i++){
        char parent, left, right;
        cin >> parent >> left >> right;
        graph[parent-'A'] = {left, right};
    }

    preorder('A');
    cout<<"\n";
    inorder('A');
    cout<<"\n";
    postorder('A');
    
    return 0;
}