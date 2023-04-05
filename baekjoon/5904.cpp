#include <bits/stdc++.h>
#include <iostream>
using namespace std;

string my_moo(int cnt){
    if(cnt==0){
        return "moo";
    }
    else{
        string cmoo = my_moo(cnt-1);
        string temp = cmoo;
        cmoo += 'm';
        for(int i=0; i<cnt+2; i++){
            cmoo += 'o';
        }
        cmoo += temp;
        return cmoo;
    }
}

int main(){
    int n; cin >> n;

    string moo = my_moo(n);

    for(char c :moo) cout << c << ' ';
}