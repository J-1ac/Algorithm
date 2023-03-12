#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main(){
    int n, m; string temp, question;
    map<string, int> pocketmons; vector<string> pocketmons2;
    cin >> n >> m;

    for(int i=0; i<n; i++){
        cin >> temp;
        pocketmons.insert(make_pair(temp, i+1));
        pocketmons2.push_back(temp);
    }

    for(int i=0; i<m; i++){
        cin >> question;
        if('A'<=question[0] && question[0]<='Z'){
            cout << pocketmons.find(question)->second << "\n";
        }else{
            cout << pocketmons2[stoi(question)-1] << "\n";
        }
    }

    return 0;
}