#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve
    stack 사용
    잘려진 조각의 수 = 현재 stack의 razor 갯수 - 각 막대기가 push 될때 stack의 razor 갯수 + 1
*/

int main(){
    queue<char> p; char temp; stack<int> mystack; int total=0, razorcnt=0; bool prior_close=false;
    while(cin >> temp){
        p.push(temp);
    }

    while(!p.empty()){
        razorcnt=0; prior_close=false;
        mystack.push(razorcnt);
        p.pop();
        while(!mystack.empty()){
            if(p.front()==')'){
                if(!prior_close){                    //razor
                    razorcnt++;
                }else{                               //bar
                    total+=razorcnt-mystack.top()+1;
                }   
                prior_close=true;
                mystack.pop();
            }else if(p.front()=='('){
                prior_close=false;
                mystack.push(razorcnt);
            }
            p.pop();
        }
    }

    cout << total;

    return 0;
}