#include <bits/stdc++.h>
#include <iostream>
using namespace std;

/* how to solve 
    구간합 활용
    각 index별 지금까지 나왔던 알파벳 개수를 배열에 추가
*/

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

    string str; int q; 
    cin >> str >> q;

    int len=str.size(); vector<array<int, 26>> d(str.size(), array<int, 26> {});
    d[0][str[0]-'a']++;

    for(int i=1; i<len; i++){
        d[i] = d[i-1];
        d[i][str[i]-'a']++;
    }

    for(int i=0; i<q; i++){
        char c; int l, r;
        cin >> c >> l >> r;
        if(l!=0)    cout << d[r][c-'a'] - d[l-1][c-'a'] << '\n';
        else        cout << d[r][c-'a'] << '\n';
    }

    return 0;
}